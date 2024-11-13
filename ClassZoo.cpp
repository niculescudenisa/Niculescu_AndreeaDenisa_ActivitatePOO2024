#include<iostream>

using namespace std;

class Zoo {
private:
	string nume;
	char* locatie;
	float pretBilet;
	bool gratuitPtCopii;
	static int nrTotalZoo;
	const int anInfiintare;
	int nrAngajati;
	float* salarii;

public:

	// Constructor implicit
	Zoo() :anInfiintare(2019) {
		this->nume = "Gradina Zoologica Bucuresti";
		this->locatie = new char[strlen("Bucuresti") + 1];
		strcpy_s(locatie, strlen("Bucuresti") + 1, "Bucuresti");
		this->pretBilet = 20;
		this->gratuitPtCopii = false;
		this->nrAngajati = 5;
		this->salarii = NULL;

		nrTotalZoo++;
	}

	// Constructor cu toti paramtrii
	Zoo(string nume, const char* locatie, float pretBilet, bool gartuitPtCopii, const int an, int nrAngajati, float* salarii) :anInfiintare(an) {
		this->nume = nume;
		this->locatie = new char[strlen(locatie) + 1];
		strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
		this->pretBilet = pretBilet;
		this->gratuitPtCopii = gartuitPtCopii;
		this->nrAngajati = nrAngajati;

		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = salarii[i];
		}
	}

	// Constructor de copiere
	Zoo(const Zoo& z):anInfiintare(z.anInfiintare){
		this->nume = z.nume;
		this->locatie = new char[strlen(z.locatie) + 1];
		strcpy_s(this->locatie, strlen(z.locatie) + 1, z.locatie);
		this->pretBilet = z.pretBilet;
		this->gratuitPtCopii = z.gratuitPtCopii;
		this->nrAngajati = z.nrAngajati;
		if (z.nrAngajati > 0 && z.salarii!=NULL) {
			this->salarii = new float[z.nrAngajati];
			for (int i = 0; i < z.nrAngajati; i++) {
				this->salarii[i] = z.salarii[i];
			}
		}
		else {
			this->salarii = NULL;
		}
	}

	// Operator =

	Zoo operator=(const Zoo& z) {
		if (&z != this) {
			this->nume = z.nume;
			this->locatie = new char[strlen(z.locatie) + 1];
			strcpy_s(this->locatie, strlen(z.locatie) + 1, z.locatie);
			this->pretBilet = z.pretBilet;
			this->nrAngajati = z.nrAngajati;

			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			if (z.nrAngajati > 0 && z.salarii != NULL) {
				this->salarii = new float[z.nrAngajati];
				for (int i = 0; i < z.nrAngajati; i++) {
					this->salarii[i] = z.salarii[i];
				}
			}
			else {
				this->salarii = NULL;
			}
		}
		return *this;
	}


	// Functia de afisare
	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Locatia:" << this->locatie << endl;
		cout << "Pret bilet:" << this->pretBilet << endl;
		cout << "Gratuit pt copii:" << this->gratuitPtCopii << endl;
		cout << "An infiintare:" << this->anInfiintare << endl;
		cout << "Nr totale zoo:" << this->nrTotalZoo << endl;
		cout << "Nr angajati:" << this->nrAngajati << ":" << endl;
         if(this->salarii!=NULL)
		 {
			for (int i = 0; i < nrAngajati; i++) 
			{
				cout << this->salarii[i] << ",";
			}
		}
		 cout << endl << endl;
	}

	~Zoo() {
		if (this->locatie != NULL) {
			delete[]this->locatie;
		}
		if (this->salarii != NULL)
		{
			delete[]this->salarii;
		}
	}
		

	friend ostream& operator<<(ostream& output, Zoo z);
	
	friend istream& operator>>(istream& input, Zoo& z) {
		cout << "Nume:";
		input >> z.nume;
		cout << "Locatia:";
		input >> z.locatie;
		cout << "Pret bilet:";
		input >> z.pretBilet;
		cout << "Nr angajati:";
		input >> z.nrAngajati;

		if (z.salarii != NULL) {
			delete[]z.salarii;
		}
		cout << "Salarii:";
		z.salarii = new float[z.nrAngajati];
		for (int i = 0; i < z.nrAngajati; i++) {
			input >> z.salarii[i];
		}
		
		cout << endl << endl;
		return input;
	}


	// Getteri si setteri

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	char* getLocatia() {
		return this->locatie;
	}

	void setLocatia(char* locatie) {
			this->locatie = locatie;
		
	}


	float getPretBilet() {
		return this->pretBilet;
	}

	void setPretBilet(float pretBilet) {
		if (pretBilet > 0) {
			this->pretBilet = pretBilet;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;

			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}


	// Operatorul [] index

	float& operator[](int index) {
		if (index >= 0 && index < nrAngajati) {
			return salarii[index];
		}
	}

	// Operatorii de incrementare si decrementare, se mai adauga un angajat, respectiv se mai scade un angajat
	
	Zoo operator++() {
		this->nrAngajati++;
		return *this;
	}

	Zoo operator++(int) {
		Zoo copie = *this;
		this->nrAngajati++;
		return copie;
	}

	Zoo operator--() {
		this->nrAngajati = this->nrAngajati - 1;
		return *this;
	}

	Zoo operator--(int) {
		Zoo copie = *this;
		this->nrAngajati = this->nrAngajati - 1;
		return copie;
	}

	//// Operatorul +, se adauga un adaos la pretBilet

	//Zoo operator+(float adaosPret) {
	//	Zoo temp = *this;
	//	temp.pretBilet = this->pretBilet + adaosPret;
	//	return temp;
	//}

	//friend Zoo operator+(float adaosPret, Zoo z) {
	//	Zoo temp = z;
	//	temp.pretBilet = z.pretBilet + adaosPret;
	//	return temp;
	//}

	//Zoo operator+(const Zoo& z)const {
	//	Zoo temp = *this;
	//	temp.pretBilet = this->pretBilet + z.pretBilet;
	//	return temp;
	//}

	

	// Operatorul +, pentru adaugarea la vectorul alocat dinamic

	friend Zoo operator+(float salariul, Zoo z) {
		Zoo temp = z;
		
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati+1];
		for (int i = 0; i < z.nrAngajati; i++) {
			temp.salarii[i] = z.salarii[i];
		}

		temp.salarii[temp.nrAngajati] = salariul;
		temp.nrAngajati++;
		return temp;
	}

	Zoo operator+(float salariu){
		Zoo temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}

		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++)
		{
			temp.salarii[i] = this->salarii[i];
		}

		temp.salarii[this->nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	Zoo operator+(Zoo z1)const {
		Zoo temp = *this;
		temp.nrAngajati = this->nrAngajati + z1.nrAngajati;

		float* aux = new float[temp.nrAngajati];

		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}

		for (int i = 0; i < z1.nrAngajati; i++) {
			aux[i + this->nrAngajati] = z1.salarii[i];
		}

		if (temp.salarii != NULL) 
		{
			delete[]temp.salarii;
		}
		 temp.salarii=aux;
		 return temp;

	}

	// Functia care calculeaza salariul mediiu
	float CalculeazaSalariulMediu(int nrAngajati, float* salarii) {
		if (nrAngajati > 0 && salarii != NULL) {
			float SumaSalarii = 0;
			for (int i = 0; i < nrAngajati; i++) {
				SumaSalarii += salarii[i];
			}
			return SumaSalarii / nrAngajati;
		}
	}

};

int Zoo::nrTotalZoo = 0;

ostream& operator<<(ostream& output, Zoo z) {
	output << "Nume:" << z.nume << endl;
	output << "Locatia:" << z.locatie << endl;
	output << "Pret bilet:" << z.pretBilet << endl;
	output << "Gratuit pt copii:" << z.gratuitPtCopii << endl;
	output << "An infiintare:" << z.anInfiintare << endl;
	output << "Nr totale zoo:" << z.nrTotalZoo << endl;
	output << "Nr angajati:" << z.nrAngajati << ":" << endl;
	if (z.nrAngajati>0 && z.salarii != NULL)
	{
		for (int i = 0; i < z.nrAngajati; i++)
		{
			output << z.salarii[i] << ",";
		}
	}
	cout << endl << endl;
	return output;
}

int main() {
	Zoo z1;
	z1.afisare();

	Zoo z2("Gradina Zoo Brasov", "Brasov", 30, true, 2020, 5, new float[5] {3000, 3100, 3200, 3300, 3400});
	cout << z2;
	Zoo z4;
	Zoo z3("Gradina Zoo Sibiu", "Sibiu", 50, true, 2023, 3, new float[3] {5000, 6000, 7000});
	Zoo z31("Gradina Zoo Sibiu", "Sibiu", 50, true, 2023, 3, new float[3] {4000, 3000, 8000});

	cout << z2.getNrAngajati() << endl << endl;
	for (int i = 0; i < z2.getNrAngajati(); i++) {
		cout << z2.getSalarii()[i] << ",";
	}
	cout << endl << endl;

	cout << "Salariul angajatului de la z2 de pe pozitia 0 este:   " << z2[0] << " Iar al celui de pe pozitia 4 este:   " << z2[4] << endl << endl;
	z2++;
	cout << z2.getNrAngajati() << endl << endl; //6
	--z1;
	cout << z1.getNrAngajati() << endl << endl; //4


	//z1 = z1 + 5; //25
	//cout << z1.getPretBilet() << endl << endl;
	//z1 = 10 + z1; //35
	//cout << z1.getPretBilet() << endl << endl;
	//z1 = z2 + z4; //20+30
	//cout << z1.getPretBilet() << endl << endl;

	cout << "Salariul mediu al angajatilor din z2 este:" << z2.CalculeazaSalariulMediu(5, new float[5] {3000, 3100, 3200, 3300, 3400}) << endl << endl; //3200

	Zoo z5("Gradina Zoo Brasov", "Brasov", 30, true, 2020, 5, new float[5] {3000, 3100, 3200, 3300, 3400});
	z5 = 4000 + z5;
	cout << z5.getNrAngajati() << endl << endl;
	for (int i = 0; i < z5.getNrAngajati(); i++) {
		cout << z5.getSalarii()[i] << ",";
	}

	z5 = z5 + 4500;
	cout << z5.getNrAngajati() << endl << endl;
	for (int i = 0; i< z5.getNrAngajati(); i++)
	{
		cout << z5.getSalarii()[i] << ",";
	}
	cout << endl << endl;

	z5 = z31 + z3;
	cout << z5.getNrAngajati() << endl << endl;
	for (int i = 0; i < z5.getNrAngajati(); i++) {
		cout << z5.getSalarii()[i] << ",";
	}
	cout << endl << endl;


	cout << endl << endl;

	Zoo zz;
	cin >> zz;
	cout << zz;


}