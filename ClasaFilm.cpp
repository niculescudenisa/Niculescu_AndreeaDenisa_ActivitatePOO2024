#include<iostream>

using namespace std;

class Film {
private:
	string denumire;
	string canal;
	int durata;
	const int anAparitie;
	static string limbaSubtitrare;
	int nrPersonaje;
	string* personaje;
	bool esteFilmDeCraciun;


public:
	// Constructor fara parametrii
	Film() :anAparitie(2000) {
		this->denumire = "Titanic";
		this->canal = "HBO";
		this->durata = 120;
		this->esteFilmDeCraciun = false;
		this->nrPersonaje = 10;
		this->personaje = NULL;
	}

	//Constructor cu 3 parametrii
	Film(string denumire, int durata, bool esteFilmDeCraciun) :anAparitie(2001) {
		this->denumire = denumire;
		this->durata = durata;
		this->esteFilmDeCraciun = false;
	}

	// Constructor cu toti parametrii
	Film(string denumire,string canal,int durata,bool esteFilmDeCraciun,const int an, int nrPersonaje,string* personaje) :anAparitie(an) {
		this->denumire = denumire;
		this->canal = canal;
		this->durata = durata;
		this->esteFilmDeCraciun = true;
		this->nrPersonaje = nrPersonaje;
		if (this->personaje != NULL)
		{
			delete[]this->personaje;
		}
		this->personaje = new string[nrPersonaje];
			for (int i = 0; i < nrPersonaje; i++)
			{
				this->personaje[i] = personaje[i];
			}

	}

	// Getteri si Setteri
	string getDenumire() {
		return denumire;
	}

	void setDenumire(string nouaDenumire){
		if (denumire.length() > 2)
		{
			this->denumire = denumire;
		}
	}

	string getCanal() {
		return canal;
	}

	void setCanal(string canal) {
		if (canal.length() > 2)
		{
			this->canal = canal;
		}
	}

	int getDurata() {
		return durata;
	}

	void setDurata(int durata) {
		if (durata > 0)
		{
			this->durata = durata;
		}
	}

	int getNrPersonaje() {
		return nrPersonaje;
	}

	void setNrPersonaje(int nrPersonaje, string* personaje) {
		if (nrPersonaje > 0)
		{
			this->nrPersonaje = nrPersonaje;
			if (this->personaje != NULL)
			{
				delete[]this->personaje;
				this->personaje = new string[nrPersonaje];
				for (int i = 0; i < nrPersonaje; i++)
				{
					this->personaje[i] = personaje[i];
				}

			}
		}
	}

	// Constructor de copiere
	Film operator=(const Film& f) {

		this->denumire = f.denumire;
		this->canal = f.canal;
		this->durata = f.durata;
		this->esteFilmDeCraciun = false;
		this->nrPersonaje = f.nrPersonaje;
		if (this->personaje != NULL)
		{
			delete[]this->personaje;
		}
		this->personaje = new string[f.nrPersonaje];
		for (int i = 0; i < f.nrPersonaje; i++)
		{
			this->personaje[i] = f.personaje[i];
		}

	}
	
	void afisare() {
		cout << "Denumire:" << this->denumire << endl;
		cout << "Canal:" << this->canal << endl;
		cout << "Durata:" << this->durata << endl;
		cout << "An aparitie:" << this->anAparitie << endl;
		cout << "Limba subtitrare:" << this->limbaSubtitrare << endl;
		cout << "Este film de craciun:" << this->esteFilmDeCraciun << endl;
		cout << "Nr de personaje:" << this->nrPersonaje << ":" << endl;
	
		for (int i = 0; i < nrPersonaje; i++)
		{
			if (this->personaje != NULL)
			{
				cout << this->personaje[i] << ",";
			}
		}
		cout << endl;
		
	}

	// Destructor
	~Film() {
		if (this->personaje != NULL)
		{
			delete[]this->personaje;
		}
	}

};

string Film::limbaSubtitrare = "Engleza";

int main() {
	Film f1;
	f1.afisare();

	Film f2("Fear Streets", 100, false);
	f2.afisare();

	Film f3("Home Alone","Disney+",120,true,2004,3,new string[3]{"personaj1","personaj2","personaj3"});
	f3.setNrPersonaje(2, new string[2]{"Macaulay Culkin","Joe Pesci"});
	f3.setDenumire("Home Alone - New York");
	f3.afisare();
	cout << f3.getDenumire();
	


}