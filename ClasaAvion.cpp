#include<iostream>

using namespace std;

class Avion {
private:
	string nume;
	int capacitate;
	float altMax;
	static int nrAvioane;
	const int anConstruire;
	int nrPersoane;
	int* varste;

public:

	Avion() :anConstruire(2000) {
		this->nume = "Boeing 747 ";
		this->capacitate = 300;
		this->altMax = 10000;
		this->nrPersoane = 5;
		this->varste = new int[5];
		varste[0] = 60;
		varste[1] = 30;
		varste[2] = 25;
		varste[3] = 30;
		varste[4] = 25;
	
	}

	Avion(string nume, int capacitate) :anConstruire(2001) {
		this->nume = nume;
		this->capacitate = capacitate;
		this->altMax = 10500;
		this->nrPersoane = 200;
		this->varste = NULL;
	}

	Avion(string nume, int capacitate, float altMax, const int an, int nrPersoane, int* varste) :anConstruire(an) {
		this->nume = nume;
		this->capacitate = capacitate;
		this->altMax = altMax;
		this->nrPersoane = nrPersoane;
		if (this->varste != NULL)
		{
			delete[]this->varste;
		}
		this->varste = new int[nrPersoane];
		for (int i = 0; i < nrPersoane; i++)
		{
			this->varste[i] = varste[i];
		}
	}

	Avion operator=(const Avion& a) {
		this->nume = a.nume;
		this->capacitate = a.capacitate;
		this->altMax = a.altMax;
		this->nrPersoane = a.nrPersoane;
		if (this->varste != NULL)
		{
			delete[]this->varste;
			this->varste = new int[a.nrPersoane];
			for (int i = 0; i < a.nrPersoane; i++)
			{
				this->varste[i] = a.varste[i];
			}
		}
		return *this;
	}


	string getNum() {
		return nume;
	}

	void setNume(string noulNume) {
		if (nume.length() > 0)
		{
			this->nume = noulNume;
		}
	}

	int getCapacitate() {
		return capacitate;
	}

	void setCapacitate(int nouaCapacitate) {
		if (capacitate > 0)
		{
			this->capacitate = nouaCapacitate;
		}
	}

	float getAltMax() {
		return altMax;
	}

	void setAltMax(float nouaAltMax) {
		if (altMax > 0) {
			this->altMax = nouaAltMax;
		}
	}

	int getNrPersoane() {
		return nrPersoane;
	}

	void setNrPersoane(int noulNrPersoane, int* varste) {
		if (nrPersoane > 0)
		{
			this->nrPersoane = noulNrPersoane;
			if (this->varste != NULL)
			{
				delete[]this->varste;
			}
			this->varste = new int[noulNrPersoane];
			for (int i = 0; i < noulNrPersoane; i++)
			{
				this->varste[i] = varste[i];
			}
		}
	}

	int* getVarste() {
		return this->varste;
	}

	int CalculVarstaMedie()const {
		if (nrPersoane > 0 && varste != NULL) {
			int sumaVarste = 0;
			for (int i = 0; i < nrPersoane; i++)
			{
				sumaVarste += varste[i];
			}
			return sumaVarste / nrPersoane;
		}
		else
		{
			return 0;
		}
	}


	int& operator[](int index) {
		if (index >= 0 && index < nrPersoane)
		{
			return varste[index];
		}
	}

	Avion operator+(int adaosCapacitate) {
		Avion temp = *this;
		temp.capacitate += adaosCapacitate;
		return temp;
	}

	friend Avion operator+(int adaosCapacitate, Avion avion) {
		Avion temp = avion;
		temp.capacitate = avion.capacitate + adaosCapacitate;
		return temp;
	}

	Avion operator+(const Avion& avion)const {
		Avion temp = *this;
		temp.capacitate = this->capacitate + avion.capacitate;
		return temp;
	}


	int operator()() const{
		return capacitate - nrPersoane;
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Capacitatea:" << this->capacitate << endl;
		cout << "Alt maxima:" << this->altMax << endl;
		cout << "Nr avioane:" << this->nrAvioane << endl;
		cout << "An construire:" << this->anConstruire << endl;
		cout << "Numar persoane:" << this->nrPersoane << ":" << endl;
		for (int i = 0; i < this->nrPersoane; i++)
		{
			if (this->varste != NULL)
			{
				cout << this -> varste[i] << ",";
			}
		}
		cout << endl << endl;
	}


	friend ostream& operator<<(ostream& output, Avion a);

	friend istream& operator>>(istream& input, Avion& a) {
		cout << "Nume:";
		input >> a.nume;
		cout << "Capacitate:";
		input >> a.capacitate;
		cout << "Altitudine maxima:";
		input >> a.altMax;
		cout << "Nr persoane:";
		input >> a.nrPersoane;
		if (a.nrPersoane > 0)
		{
			if (a.varste != NULL)
			{
				cout << "Varste:";
				for (int i = 0; i < a.nrPersoane; i++)
				{
					input >> a.varste[i];
				}
			}
		}
		return input;
	}
	
};

int Avion::nrAvioane = 0;

ostream& operator<<(ostream& output, Avion a) {
	output << "Nume:" << a.nume << endl;
	output << "Capacitatea:" << a.capacitate << endl;
	output << "Alt maxima:" << a.altMax << endl;
	output << "Nr avioane:" << a.nrAvioane << endl;
	output << "An construire:" << a.anConstruire << endl;
	output << "Numar persoane:" << a.nrPersoane << ":" << endl;
	for (int i = 0; i < a.nrPersoane; i++)
	{
		if (a.varste != NULL)
		{
			output << a.varste[i] << ",";
		}
	}
	output << endl;
	return output;
}

int main() {
	Avion a1;
	a1.afisare();
	Avion a2("Airbus A380", 310);
	a2.afisare();
	Avion a3("Cessna 172 ", 30, 9000, 2010, 7, new int[7] {20, 21, 22, 23, 30, 33, 37});
	cout << a3 << endl;

	cout << a3[2] << endl << a1[0] << endl << endl;   // 22 si 25

	Avion a5;
	a5.setCapacitate(250);
	a5 = a5 + 100; // 250+100
	cout << a5.getCapacitate() << endl;
	a5 = 100 + a5;   //100+350
	cout << a5.getCapacitate() << endl;

	Avion a6;
	Avion a7;
	a6.setCapacitate(100);
	a7.setCapacitate(100);
	a5 = a6 + a7;
	cout << a5.getCapacitate() << endl;
	cout << endl << endl;

	Avion a8("Airbus 828", 100 , 10000, 2014, 3, new int[3] {30,60,90});
	cout << a8 << endl;
	cout << a8.getNrPersoane() << endl << endl << endl;
	cout << "Varsta medie a1:" << a1.CalculVarstaMedie() << endl << endl;
	Avion a9("Cessna 172", 30, 9000, 2010, 4, new int[4] {20, 40, 20, 40});
	cout << a9<< endl;
	cout << "Varsta medie pentru a3: " << a9.CalculVarstaMedie() << endl << endl;


	Avion a10;
	a10.setCapacitate(50);
	a10.setNrPersoane(10,new int[10]{20,25,45,78,45,65,98,45,78,10});
	cout << a10.getCapacitate() << endl << a10.getNrPersoane() << endl << endl;
	cout << "Nr locuri disponibile pentru a10:" << a10() << endl << endl;   //50-10

	Avion a4;
	cin >> a4;
	cout <<endl<< a4 << endl;

}