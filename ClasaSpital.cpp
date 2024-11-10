#include<iostream>

using namespace std;

class Spital {
private:
	string denumire;
	string sectie;
	int nrSaloane;
	bool estePublic;
	const int anConstruire;
	static int CapacitatePersoane;
	int nrPacientiSectie;
	float* varste;
	
public:
	
	// Constructor fara parametrii
	Spital() :anConstruire(1990) {
		this->denumire = "Spitalul Universitar";
		this->sectie = "Cardiologie";
		this->nrSaloane = 50;
		this->estePublic = true;
		this->nrPacientiSectie = 5;
		this->varste = NULL;
	}

	// Constructor cu 3 parametrii
	Spital(string denumire, string sectie, int nrSaloane) :anConstruire(1991) {
		this->denumire = denumire;
		this->sectie = sectie;
		this->nrSaloane = nrSaloane;
		this->estePublic = true;
		this->nrPacientiSectie = 6;
		this->varste = NULL;
	}

	// Constrcutor cu toti parametrii
	Spital(string denumire, string sectie, int nrSaloane, bool estePublic, const int an, int nrPacientiSectie, float* varste) :anConstruire(an) {
		this->denumire = denumire;
		this->sectie = sectie;
		this->nrSaloane = nrSaloane;
		this->estePublic = estePublic;
		this->nrPacientiSectie = nrPacientiSectie;
		if (this->varste != NULL)
		{
			delete[]this->varste;
		}
		this->varste = new float[nrPacientiSectie];
		for (int i = 0; i < nrPacientiSectie; i++)
		{
			this->varste[i] = varste[i];
		}
	}

	
	// Constructor de copiere

	Spital operator=(const Spital& s) {
		this->denumire = s.denumire;
		this->sectie = s.sectie;
		this->nrSaloane = s.nrSaloane;
		this->estePublic = s.estePublic;
		this->nrPacientiSectie = s.nrPacientiSectie;
		if (this->varste != NULL) {
			delete[]this->varste;

			this->varste = new float[s.nrPacientiSectie];
			for (int i = 0; i < s.nrPacientiSectie; i++)
			{
				this->varste[i] = s.varste[i];
			}
		}
		return *this;
	}

	// Getteri si Setteri

	string getDenumire() {
		return denumire;
	}

	void setDenumire(string nouaDenumire) {
		if (denumire.length() > 2) {
			this->denumire = nouaDenumire;
		}
	}

	string getSectie() {
		return sectie;
	}

	void setSectie(string nouaSectie) {
		if (sectie.length() > 2) {
			this->sectie = nouaSectie;
		}
	}

	int getNrSaloane() {
		return nrSaloane;
	}

	void setNrSaloane(int noulNrSaloane) {
		if (nrSaloane > 0) {
			this->nrSaloane = noulNrSaloane;
		}
	}

	int getNrPacienti() {
		return nrPacientiSectie;
	}

	void setNrPacienti(int noulNrPacienti, float* varste) {
		if (nrPacientiSectie > 0) {
			this->nrPacientiSectie = noulNrPacienti;

			if (this->varste != NULL)
			{
				delete[]this->varste;
			}
			this->varste = new float[noulNrPacienti];
			for (int i = 0; i < noulNrPacienti; i++)
			{
				this->varste[i] = varste[i];
			}
		}
	}


	float operator[](int index) {
		if (index >= 0 && index < nrPacientiSectie)
		{
			return varste[index];
		}
	}

	Spital operator+(int adaugareSaloane) {
		Spital temp = *this;
		temp.nrSaloane += adaugareSaloane;
		return temp;
	}

	friend Spital operator+(int adaugareSaloane, Spital spital) {
		Spital temp = spital;
		temp.nrSaloane = spital.nrSaloane + adaugareSaloane;
		return temp;
	}

	Spital operator+(const Spital& spital)const {
		Spital temp = *this;
		temp.nrSaloane = this->nrSaloane + spital.nrSaloane;
		return temp;
	}

	// Functia de afisare
	void afisare() {
		cout << "Denumire:" << this->denumire << endl;
		cout << "Sectia:" << this->sectie << endl;
		cout << "Nr saloane:" << this->nrSaloane << endl;
		cout << "Anul de construire:" << this->anConstruire << endl;
		cout << "Este public:" << this->estePublic << endl;
		cout << "Capacitatea maxima pacienti:" << this->CapacitatePersoane << endl;
		cout << "Nr pacienti/sectie:" << this->nrPacientiSectie << ":" << endl;
			for (int i = 0; i < nrPacientiSectie; i++){
				if(this->varste!=NULL)
			{
				cout << this->varste[i] << ",";
			}
		}
		cout << endl << endl;
	}


	friend ostream& operator<<(ostream& output, Spital s);

	friend istream& operator>>(istream& input, Spital& s) {
		cout << "Denumire:";
		input >> s.denumire;
		cout << "Sectie:";
		input >> s.sectie;
		cout << "Nr saloane:";
		input >> s.nrSaloane;
		cout << "Nr pacienti/sectie:";
		input >> s.nrPacientiSectie;
		if (s.varste != NULL)
			{
			delete[]s.varste;
			}
		if (s.nrPacientiSectie > 0)
		{
			s.varste = new float[s.nrPacientiSectie];
			cout << "Varste:";
			for (int i = 0; i < s.nrPacientiSectie; i++)
			{
				input >> s.varste[i];
			}
		}
		else
		{
			s.varste = NULL;
		}
		cout << endl << endl;
		return input;
	}


};


int Spital::CapacitatePersoane = 300;

ostream& operator<<(ostream& output, Spital s) {
	output << "Denumire:" << s.denumire << endl;
	output << "Sectia:" << s.sectie << endl;
	output << "Nr saloane:" << s.nrSaloane << endl;
	output << "Anul de construire:" << s.anConstruire << endl;
	output << "Este public:" << s.estePublic << endl;
	output << "Capacitatea maxima pacienti:" << s.CapacitatePersoane << endl;
	output << "Nr pacienti/sectie:" << s.nrPacientiSectie << ":" << endl;
	for (int i = 0; i < s.nrPacientiSectie; i++)
	{
		if (s.varste != NULL)
		{
			output << s.varste[i] << ",";
		}
	}
	cout << endl << endl;
	return output;
}

int main() {
	Spital s1;
	s1.afisare();
	Spital s2("Spitalul Floreasca", "Ortopedie", 70);
	s2.afisare();
	Spital s3("Spitalul de urgenta Timisoara", "Neurologie", 30, true, 1997, 5, new float[5] {45, 39, 40, 71, 60});
	s3.afisare();

	Spital s4;
	cout << s4;

	cout << s3[1] << endl << s3[2] << endl << endl;
	s3.setDenumire("Spitalul Timisoara");
	s3.setSectie("Cardiologie");
	s3.setNrPacienti(7, new float[7] {61, 62, 63, 64, 65, 66, 67});
	cout << s3;

	Spital s6;
	Spital s7;
	Spital s8;
	s6.setNrSaloane(20);
	s6 = s6 + 7;  //20+7
	cout << s6.getNrSaloane() << endl << endl;
	s6.setNrSaloane(20);
	s6 = 8 + s6; //8+20
	cout << s6.getNrSaloane() << endl << endl;
	s6.setNrSaloane(21);
	s7.setNrSaloane(34);
	s8 = s6 + s7;   // 21+34
	cout << s8.getNrSaloane() << endl << endl;


	Spital s5;
	cin >> s5;
	s5.afisare();

}