#include<iostream>

using namespace std;

class Florarie {
private:
	string denumire;
	int nrAngajati;
	float pretMediu;
	bool faceLivrari;
	const int anDeschidere;
	static int impozitLocatie;
	int nrTipuriFlori;
	string* flori;

public:
	
	// Constructor fara parametrii
	Florarie() :anDeschidere(2018) {
		this->denumire = "Floraria Bloom";
		this->nrAngajati = 3;
		this->pretMediu = 50;
		this->faceLivrari = false;
		this->nrTipuriFlori = 10;
		this->flori = NULL;

	}

	// Constructor cu 3 parametrii
	Florarie(string denumire, int nrAngajati, float pretMediu) :anDeschidere(anDeschidere) {
		this->denumire = denumire;
		this->nrAngajati = nrAngajati;
		this->pretMediu = pretMediu;
	}

	// Constrcutor cu toti parametrii
	Florarie(string denumire, int nrAngajati, float pretMediu, bool faceLivrari, const int an, int nrTipuriFlori, string* flori) :anDeschidere(an) {
		this->denumire = denumire;
		this->nrAngajati = nrAngajati;
		this->pretMediu = pretMediu;
		this->faceLivrari = true;
		this->nrTipuriFlori = nrTipuriFlori;
		if (this->flori != NULL)
		{
			delete[]this->flori;
		}
		this->flori = new string[nrTipuriFlori];
		for (int i = 0; i < nrTipuriFlori; i++)
		{
			this->flori[i] = flori[i];
		}
	}

	

	// Constrcutor de copiere
	Florarie operator=(const Florarie& f)
	{
     		this->denumire = f.denumire;
			this->nrAngajati = f.nrAngajati;
			this->pretMediu = f.pretMediu;
			this->faceLivrari = true;
			this->nrTipuriFlori = f.nrTipuriFlori;
			if (this->flori != NULL)
			{
				delete[]this->flori;
			this->flori = new string[f.nrTipuriFlori];
			for (int i = 0; i < f.nrTipuriFlori; i++)
			{
				this->flori[i] = f.flori[i];
			}

		}
		return *this;
	}

	// Getteri si Setteri

	string getDenumire() {
		return denumire;
	}

	void setDenumire(string nouaDenumire) {
		if (denumire.length() > 2)
		{
			this->denumire = nouaDenumire;
		}
	}

	int getNrAngajati() {
		return nrAngajati;
	}

	void setNrAngajati(int noulNrAngajati) {
		if (nrAngajati > 0)
		{
			this->nrAngajati = noulNrAngajati;
		}
	}

	float getPretMediu() {
		return pretMediu;
	}

	void setPretMediu(float noulPretMediu) {
		if (pretMediu > 0)
		{
			this->pretMediu = noulPretMediu;
		}
	}


	int getNrTipuriFlori() {
		return nrTipuriFlori;
	}

	void setNrTipuriFlori(int nrTipuriFlori, string* flori) {
		if (nrTipuriFlori > 0) {
			this->nrTipuriFlori = nrTipuriFlori;
			if (this->flori != NULL)
			{
				delete[]this->flori;
			}
			this->flori = new string[nrTipuriFlori];
			for (int i = 0; i < nrTipuriFlori; i++)
			{
				this->flori[i] = flori[i];
			}
		}
	}

	string* getFlori() {
		return this->flori;
	}


	// Functia de afisare
	void afisare() {
		cout << "Denumire:" << this->denumire << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Pretul mediu:" << this->pretMediu << endl;
		cout << "Face livrari:" << this->faceLivrari << endl;
		cout << "Impozitul platit pe locatie:" << this->impozitLocatie << endl;
		cout << "Anul deschiderii:" << this->anDeschidere << endl;
		cout << "Numar tipuri flori:" << this->nrTipuriFlori << ":" << endl;
		for (int i = 0; i < nrTipuriFlori; i++) {
			if (this->flori != NULL)
			{
				cout << this->flori[i] << ",";
			}
		}
		cout << endl << endl;
	}



	Florarie operator+(float adaosPret)const {
		Florarie temp = *this;
		temp.pretMediu+= adaosPret;
		return temp;
	}


	friend Florarie operator+(float adaosPret, Florarie f) {
		Florarie temp = f;
		temp.pretMediu = f.pretMediu + adaosPret;
		return temp;
	}

	Florarie operator+(const Florarie& f) const {
		Florarie temp = *this;
		temp.pretMediu= this->pretMediu + f.pretMediu;
		return temp;
	}


	// Destructor
	~Florarie() {
		if (this->flori != NULL)
		{
			delete[]this->flori;
		}
	}


	friend ostream& operator<<(ostream& output , Florarie f);

	friend istream& operator>>(istream& input, Florarie& f)
	{
		cout << "Denumire:";
		input >> f.denumire;
		cout << "Nr angajati:";
		input >> f.nrAngajati;
		cout << "Pret mediu:";
		input >> f.pretMediu;
		cout << "Nr tipuri flori:";
		input >> f.nrTipuriFlori;

		if (f.flori != NULL)
		{
			delete[]f.flori;
		}

		if (f.nrTipuriFlori > 0)
		{
			f.flori = new string[f.nrTipuriFlori];
			cout << "Flori:";
			for (int i = 0; i < f.nrTipuriFlori; i++)
			{
				input >> f.flori[i];
			}
		}
		else
		{
			f.flori = NULL;
		}

		return input;
	}

	string operator[](int index)
	{
		if (index >= 0 && index < nrTipuriFlori)
		{
			return flori[index];
		}
	}


};


int Florarie::impozitLocatie = 15;


ostream& operator<<(ostream& output, Florarie f) {
	output << "Denumire:" << f.denumire << endl;
	output << "Nr angajati:" << f.nrAngajati << endl;
	output << "Pretul mediu:" << f.pretMediu << endl;
	output << "Face livrari:" << f.faceLivrari << endl;
	output << "Impozitul platit pe locatie:" << f.impozitLocatie << endl;
	output << "Anul deschiderii:" << f.anDeschidere << endl;
	output << "Numar tipuri flori:" << f.nrTipuriFlori << ":" << endl;
	for (int i = 0; i < f.nrTipuriFlori; i++) {
		if (f.flori != NULL)
		{
			output << f.flori[i] << ",";
		}
	}
	output << endl << endl;
	return output;
	}

int main() {
	Florarie f1;
	f1.afisare();
	Florarie f2("Floraria Eden", 4, 52);
	f2.afisare();
	Florarie f3("Floraria Iris",5,60,true,2020,5,new string[5]{"Trandafiri","Lalele","Orhidee","Crin","Azalee"});
	f3.afisare();

	Florarie f4;
	f4.setDenumire("Floraria Petal");
	f4.setPretMediu(55);
	cout << f4;
	cout << endl;

	Florarie f6(" Luna", 5, 70, true, 2021, 2, new string[2]{ "Lalele","Crin" });
	f6.setDenumire("Floraria Luna");
	f6.setNrTipuriFlori(2, new string[2]{ "A","B" });
	f6.afisare();
	cout << endl;


	Florarie f7;
	Florarie f8;
	f7 = f7 + 1;
	cout << f7.getPretMediu() << endl << f8.getPretMediu() << endl;
	cout << endl;

    Florarie f9;
	f9= 11 + f9;   
	cout << f9.getPretMediu() << endl;
	cout << endl;

	Florarie f10;
	f7.setPretMediu(22);
	f8.setPretMediu(55);
	f10 = f7 + f8;   // 22+55
	cout << f10.getPretMediu() << endl;
	cout << endl << endl;

	cout << f3[0] << endl << f3[1] << endl;
	cout << endl;

	Florarie f5;
	cin >> f5;
	cout << endl << endl;
	f5.afisare();

	



}