#include<iostream>
using namespace std;

class Carte {
private:
	string titlu;
	string autor;
	int nrPagini;
	const int ISBN;
	static int nrCarti;
	float pret;
	int nrCapitole;
	string* capitole;

public:
	Carte():ISBN(1234) {
		this->titlu = "Ion";
		this->autor = "Liviu Rebreanu";
		this->nrPagini = 300;
		this->pret = 20;
		this->nrCapitole = 25;
		this->capitole = NULL;

	}

	Carte(const int ISBN, string titlu, string autor, int nrPagini, float pret, int nrCapitole) :ISBN(ISBN) {
		this->titlu = titlu;
		this->autor = autor;
		this->nrPagini = nrPagini;
		this->pret = pret;
		this->nrCapitole = nrCapitole;
		this->capitole = new string[nrCapitole];
		for (int i = 0; i < nrCapitole; i++)
		{
			this->capitole[i] = capitole[i];
		}
	}

	// Constructor de copiere
	Carte(const Carte& c) :ISBN(c.ISBN) {
		this->titlu = c.titlu;
		this->autor = c.autor;
		this->nrPagini = c.nrPagini;
		this->pret = c.pret;
		if(c.nrCapitole>0 && c.capitole!=NULL)
		{ 
			this->nrCapitole = c.nrCapitole;
			this->capitole = new string[c.nrCapitole];
			for (int i = 0; i < c.nrCapitole; i++)
			{
				this->capitole[i] = c.capitole[i];
			}
		}
		else
		{
			this->nrCapitole = 0;
			this->capitole = NULL;
		}

		
	}
	Carte(string titlu, string autor) :ISBN(1236) {
		this->titlu = titlu;
		this->autor = autor;
		this->pret = 10;
		this->nrPagini = 100;
		this->nrCapitole = 15;
	}

	void afisare() {
		cout << "Codul ISBN:" << this->ISBN << endl;
		cout << "Nr de carti:" << this->nrCarti << endl;
		cout << "Titlul:" << this->titlu << endl;
		cout << "Autorul:" << this->autor << endl;
		cout << "Nr de pagini:" << this->nrPagini << endl;
		cout << "Pretul:" << this->pret << endl;
		cout << "Nr de capitole:" << this->nrCapitole << endl;
	
	}

	void setTitlu(string titlu) {
		if (titlu.length() > 3)
		{
			this->titlu = titlu;
		}
	}
	string getTitlu() {
		return titlu;
	}

	string getAutor() {
		return autor;
	}

	void setAutor(string autor) {
		if (autor.length() > 3)
		{
			this->autor = autor;
		}
	}

	int getISBN() {
		return ISBN;
	}


	float getPret() {
		return pret;
	}

	void setPret(float pret) {
		if (pret > 0)
		{
			this->pret = pret;
		}
	}

	int getNrPagini() {
		return nrPagini;
	}

	void setNrPagini() {
		if (nrPagini > 0)
		{
			this->nrPagini = nrPagini;
		}
	}

	int getNrCapitole() {
		return nrCapitole;
	}

	void setNrCapitole(int nrCapitole, string* capitole) {
		if (capitole)
		{
			delete[]this->capitole;
		}
			this->nrCapitole = nrCapitole;
			delete[]this->capitole;
			this->capitole = new string[this->nrCapitole];
			for (int i = 0; i < nrCapitole; i++)
				this->capitole[i] = capitole[i];
		
	}

	string* getCapitole() {
		return this->capitole;
	}
	~Carte() {
		if (this->nrCapitole != NULL)
		{
			delete[]this->capitole;
		}
	}
};

int Carte::nrCarti = 100;

int main() {
	Carte c1;
	c1.afisare();

	Carte c2(1235, "Iona", "Marin Sorescu", 150, 20, 4);
	c2.afisare();

	Carte c3("Poezii", "Mihai Eminescu");
	cout << c3.getAutor() << endl;
	c3.setAutor("Eminescu");
	c3.afisare();

	Carte c4;
	c4.setAutor("Ion Creanga");
	c4.setTitlu("Harap Alb");

}