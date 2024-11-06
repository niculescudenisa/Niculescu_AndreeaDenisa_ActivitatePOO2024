#include<iostream>

using namespace std;

class Cinema {
private:
	string denumire;
	int nrLocuri;
	float pret;
	static int TVAbilet;
	const int anDeschidere;
	int nrFilme;
	string* filme;

public: 

	Cinema() :anDeschidere(2024) {
		this->denumire = "Cinema City";
		this->nrLocuri = 100;
		this->pret = 20;
		this->nrFilme = 5;
		this->filme = NULL;
	}


	Cinema(string denumire, int nrLocuri, float pret):anDeschidere(2023){
		this->denumire = denumire;
		this->nrLocuri = nrLocuri;
		this->pret = pret;

	}

	Cinema(string denumire, int nrLocuri, float pret, const int an, int nrFilme, string* filme):anDeschidere(an) {
		this->denumire = denumire;
		this->nrLocuri = nrLocuri;
		this->pret = pret;
		this->nrFilme = nrFilme;
		if (this->filme != NULL) {
			delete[]this->filme;
		}
			this->filme = new string[this->nrFilme];
			for (int i = 0; i < nrFilme; i++) {
				this->filme[i] = filme[i];
			}
		

	}


	string getDenumire() {
		return denumire;
	}

	void setDenumire(string nouaDenumire) {
		if (denumire.length() > 2)
		{
			this->denumire = nouaDenumire;
		}
	}


	int getNrLocuri() {
		return nrLocuri;
	}

	void setNrLocuri(int nrLocuri) {
		if (nrLocuri > 0) {
			this->nrLocuri = nrLocuri;
		}
	}

	float getPret() {
		return pret;
	}

	void setPret(float noulPret) {
		if (pret > 0)
		{
			this->pret = noulPret;
		}
	}

	int getNrFilme() {
		return nrFilme;
	}


	void setNrFillme(int nrFilme, string* filme) {
		if (nrFilme > 0)
		{
			this->nrFilme = nrFilme;
			if (this->filme != NULL)
			{
				delete[]this->filme;
				this->filme = new string [nrFilme];
				for (int i = 0; i < nrFilme; i++)
				{
					this->filme[i] = filme[i];
				}

			}
		}
	}

	// Constructorul de copiere

	Cinema operator=(const Cinema& c) {
		this->denumire = c.denumire;
		this->nrLocuri = c.nrLocuri;
		this->pret = c.pret;
		this->nrFilme = c.nrFilme;
		if (this->filme != NULL)
		{
			delete[]this->filme;
			this->filme = new string[c.nrFilme];
			for (int i = 0; i < c.nrFilme; i++)
			{
				this->filme[i] = c.filme[i];
			}
		}
	}


	void afisare() {
		cout << "Denumire:" << this ->denumire << endl;
		cout << "Nr de locuri:" << this->nrLocuri << endl;
		cout << "Anul deschiderii:" << this->anDeschidere << endl;
		cout << "Pretul biletului:" << this->pret << endl;
		cout << "TVA bilet:" << this->TVAbilet << endl;
		cout << "Nr de filme:" << this->nrFilme << ":" << endl;
		
		for (int i = 0; i < this->nrFilme; i++)
		{
			if (this->filme != NULL)
			{

				cout << this->filme[i] << ",";
			}
		}
		
		cout << endl;
	}
	


	~Cinema() {
		if (this->filme != NULL)
		{
			delete[]this->filme;
		}
	}
};

int Cinema::TVAbilet = 19;
int main() {
	Cinema c1;
	c1.afisare();

	Cinema c2("Cinema Max", 111, 27);
	c2.setDenumire("Cinema AFI");
	c2.setPret(28);
	c2.afisare();
	cout << c2.getPret();
	cout << "\n";

	Cinema c3("Cinema Pro", 200, 50, 2020, 3, new string[3]{ "Home Alone 1","Home Alone 2","Home Alone 3" });
	c3.setDenumire("Cinema Vip");
	c3.setPret(45);
	c3.setNrFillme(2, new string[2]{ "A Christmas Carol","Titanic" });
	c3.afisare();
	cout << c3.getDenumire();
	cout << "\n";
	cout<<c3.getPret();
	
	
}