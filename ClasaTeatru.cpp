#include<iostream>

using namespace std;

class Teatru {
private:
	string nume;
	string locatie;
	float pretBilet;
	const int anDeschidere;
	static int TVA;
	int nrActori;
	float* varste;

public:

	//Constructor fara parametrii
	Teatru() :anDeschidere(2019) {
		this->nume = "Teatrul I.L. Caragiale";
		this->locatie = "Bucuresti";
		this->pretBilet = 75;
		this->nrActori = 10;
		this->varste = NULL;
	}

	// Constructor cu parametrii
	Teatru(string nume, string locatie, float pretBilet, const int an, int nrActori, float* varste) :anDeschidere(an) {
		this->nume = nume;
		this->locatie = locatie;
		this->pretBilet = pretBilet;
		this->nrActori = nrActori;
		this->varste = new float[nrActori];
		for (int i = 0; i < nrActori; i++) {
			this->varste[i] = varste[i];
		}
	}

	// Destructor
	~Teatru() {
		if (this->varste != NULL) {
			delete[]this->varste;
		}
	}

	// Constructor de copiere
	Teatru(const Teatru& t) :anDeschidere(t.anDeschidere) {
		this->nume = t.nume;
		this->locatie = t.locatie;
		this->pretBilet = t.pretBilet;
		this->nrActori = t.nrActori;
		this->varste = new float[t.nrActori];
		for (int i = 0; i < t.nrActori; i++) {
			this->varste[i] = t.varste[i];
		}
	}

	// Functia de afisare
	void afisare() {
		cout << "Nume teatru:" << this->nume << endl;
		cout << "Locatie:" << this->locatie << endl;
		cout << "Pret bilet:" << this->pretBilet << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "Nr actori:" << this->nrActori << ":" << endl;
		if (this->varste!=NULL)
		{
			for (int i = 0; i < nrActori; i++)
			{
				cout << this->varste[i] << ",";
			}
		}
		cout << endl << endl;
	}

	// Operatorul de atribuire
	Teatru operator=(const Teatru& t) {
		if (&t != this)
		{
			this->nume = t.nume;
			this->locatie = t.locatie;
			this->pretBilet = t.pretBilet;
			this->nrActori = t.nrActori;
			if (this->varste != NULL) {
				delete[]this->varste;
			}
			this->varste = new float[t.nrActori];
			for (int i = 0; i < t.nrActori; i++) {
				this->varste[i] = t.varste[i];
			}
		}
		return *this;
	}

	// Getteri si setteri

	string getNume() {
		return this->nume;
	}

	string getLocatie() {
		return this->locatie;
	}

	void setNume(string noulNume) {
		if (nume.length() > 1) {
			this->nume = noulNume;
		}
	}

	void setLocatie(string nouaLocatie) {
		if (locatie.length() > 1) {
			this->locatie = nouaLocatie;
		}
	}

	float getPretBilet() {
		return this->pretBilet;
	}

	void setPretBilet(float noulPret) {
		if (pretBilet > 0) {
			this->pretBilet = noulPret;
		}
	}

	int getNrActori() {
		return this->nrActori;
	}

	void setNrActori(int nrActori, float* varste) {
		if (nrActori > 0) {
			this->nrActori = nrActori;
			if (this->varste != NULL) {
				delete[]this->varste;
			}
			this->varste = new float[nrActori];
			for (int i = 0; i < nrActori; i++) {
				this->varste[i] = varste[i];
			}
		}
	}

	float* getVarste() {
		return this->varste;
	}

	// Operatorul index
	
	float& operator[](int index) {
		if (index >= 0 && index < nrActori) {
			return varste[index];
		}
	}

	// Operatorul ++
	Teatru operator++() {  // Prefixare
		this->nrActori++; // this->nrActori=this->nrActori+1;
		return *this;
	}

	Teatru operator++(int) { //postfixare
		Teatru copie = *this;
		this->nrActori++; // this->nrActori=this->nrActori+1;
		return copie;
	}

	//// Operatorul +, adaugare PretBilet
	//Teatru operator+(float adaosPret) {
	//	Teatru temp = *this;
	//	temp.pretBilet = this->pretBilet + adaosPret;
	//	return temp;
	//}


	

	//friend Teatru operator+(float adaosPret, Teatru teatru) {
	//	Teatru temp = teatru;
	//	temp.pretBilet = teatru.pretBilet + adaosPret;
	//	return temp;
	//}

	//Teatru operator+(const Teatru& teatru)const {
	//	Teatru temp = *this;
	//	temp.pretBilet = this->pretBilet + teatru.pretBilet;
	//	return temp;
	//}




	friend ostream& operator<<(ostream& output, Teatru t);

	friend istream& operator>>(istream& input, Teatru& t) {
		cout << "Nume:";
		input >> t.nume;
		cout << "Locatie:";
		input >> t.locatie;
		cout << "Pret bilet:";
		input >> t.pretBilet;
		cout << "Nr actori:";
		input >> t.nrActori;
		if (t.varste != NULL)
		{
			delete[]t.varste;
		}
		if (t.nrActori > 0) {
			t.varste = new float[t.nrActori];
			cout << "Varste:";
			for (int i = 0; i < t.nrActori; i++) {
				input >> t.varste[i];
			}
		}
		else {
			t.varste = NULL;
		}
		cout << endl << endl;
		return input;
	}


	//Operatorul +, pt vectorul alocat dinamic

	friend Teatru operator+(float varsta, Teatru t) {
		Teatru temp = t;
		if (temp.varste != NULL) {
			delete[]temp.varste;
		}
		temp.varste = new float[temp.nrActori + 1];
		for (int i = 0; i < t.nrActori; i++) {
			temp.varste[i] = t.varste[i];
		}
		temp.varste[temp.nrActori] = varsta;
		temp.nrActori++;
		return temp;
	}

	Teatru operator+(Teatru t1)const {
		Teatru temp= *this;
		temp.nrActori = this->nrActori + t1.nrActori;

		float* aux = new float[temp.nrActori];
		for (int i = 0; i < this->nrActori; i++)
		{
			aux[i] = this->varste[i];
		}

		for (int i = 0; i < t1.nrActori; i++) {
			aux[i + this->nrActori] = t1.varste[i];
		}

		if (temp.varste != NULL) {
			delete[]temp.varste;
		}
		temp.varste = aux;
		return temp;
	}

	// Functie care modifica tva-ul
	static void ModificareTVA(int noulTVA) {
		if (noulTVA > 0) {
			 Teatru::TVA = noulTVA;
		}
	}

	// Functia care calculeaza varsta medie a actorilor dintr-un teatru
	float CalculeazaVarstaMedie(int nrActori, float* varste) {
		if (nrActori > 0 && varste != NULL) {
			int SumaVarste = 0;
			for (int i = 0; i < nrActori; i++) {
				SumaVarste += varste[i];
			}
			return SumaVarste / nrActori;
		}
	}

};


int Teatru::TVA = 12;


ostream& operator<<(ostream& output, Teatru t) {
	output << "Nume teatru:" << t.nume << endl;
	output << "Locatie:" << t.locatie << endl;
	output << "Pret bilet:" << t.pretBilet << endl;
	output << "An deschidere:" << t.anDeschidere << endl;
	output << "TVA:" << t.TVA << endl;
	output << "Nr actori:" << t.nrActori << ":" << endl;
	if (t.varste != NULL)
	{
		for (int i = 0; i < t.nrActori; i++)
		{
			output << t.varste[i] << ",";
		}
	}
	cout << endl << endl;
	return output;
}

int main() {
	Teatru t1;
	t1.afisare();
	Teatru t2("Teatrul National Brasov", "Brasov", 80, 2020, 5, new float[5] {20, 25, 30, 35, 40});
	cout << t2;


	Teatru t4("Teatrul National Constanta", "Constanta", 85, 2020, 4, new float[4] {45,50,55,60});
	cout << t4;
	t4.setNrActori(5, new float[5] {31, 32, 33, 34, 35});
	cout << t4.getNrActori() << endl;
	cout << "Varstele actorilor din t4:";
	for (int i = 0; i < t4.getNrActori(); i++)
	{
		cout << t4.getVarste()[i] << endl;
	}

	cout << endl<<"Varsta primului actor din t4:" << t4[0] << endl << endl; // 31

	++t4; 
	cout << t4.getNrActori() << endl << endl; // afisare 6
	t4.setNrActori(5, new float[5] {31, 32, 33, 34, 35});
	t4++;
	cout << t4.getNrActori() << endl << endl;  // afiseaza 6
	
	Teatru t5("Teatrul National Galati", "Galati", 85, 2020, 4, new float[4] {45,50,55,60});
	//Teatru t6("TNT", "Targoviste", 50, 2020, 5, new float[5] {23, 25, 25, 26, 24});
	//Teatru t7 ("TNS", "Suceava", 50, 2020, 5, new float[5] {20, 21, 22, 23, 24});
	//t5 = t5 + 5;   //85+5
	//cout << t5.getPretBilet() << endl << endl;
	//t5 = 5 + t5; //90+5
	//cout << t5.getPretBilet() << endl << endl;

	//t5 = t6 + t7; // 50+50
	//cout << t5.getPretBilet() << endl << endl;

	Teatru a1("TNS", "Sighisoara", 2020, 50, 5, new float[5] {20, 21, 22, 23, 24});
	cout << a1.getNrActori() << ":";
	for (int i = 0; i < a1.getNrActori(); i++) {
		cout << a1.getVarste()[i] << ",";
	}
	cout << endl << endl;

	a1 = 30+a1;
	cout << "Nr actorilor din teatrul a1 este:" << a1.getNrActori() << endl << endl; // 5+1
	for (int i = 0; i < a1.getNrActori(); i++) {
		cout << a1.getVarste()[i] << ",";
	}
	cout << endl << endl;

	a1 = t2 + t5;
	cout << "Nr actorilor din teatrul a1 este:" << a1.getNrActori() << endl << endl;  //4+5
	for (int i = 0; i < a1.getNrActori(); i++) {
		cout << a1.getVarste()[i] << ",";
	}
	cout << endl << endl;


	Teatru teatru1("TNB", "Brasov", 50, 2023, 5, new float[5] {19, 18, 20, 21, 22});
	teatru1.ModificareTVA(19);
	cout << teatru1 << endl << endl;

	Teatru teatru2("TNC", "Constanta", 60, 2020, 5, new float[5] {20, 30, 50, 25, 40});
	cout<<"Varsta medie a actorilor din teatrul2 este:"<< teatru2.CalculeazaVarstaMedie(5, new float[5] {20, 30, 50, 25, 40}) << endl << endl;  // 33

	Teatru t3;
	cin >> t3;
	cout << t3;

}