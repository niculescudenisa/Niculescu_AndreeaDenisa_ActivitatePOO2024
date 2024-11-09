#include<iostream>

using namespace std;

class Apartament {
private:
	string adresaStrada;
	int etaj;
	float chirie;
	static int impozit;
	const int nrApartament;
	int nrApartamente;
	string* locuitori;  //  locuitorii din ficare apartament

public:

	// Constructor implicit fara parametrii
	Apartament() :nrApartament() {
		this->adresaStrada = "Strada Florilor";
		this->etaj = 1;
		this->chirie = 1000;
		this->nrApartamente = 3;
		this->locuitori = NULL;

	}

	// Constructor cu 3 parametrii
	Apartament(string adresaStrada, int etaj, float chirie) :nrApartament(2) {
		this->adresaStrada = adresaStrada;
		this->etaj = etaj;
		this->chirie = chirie;
	}

	// Constructor cu toti parametrii
	Apartament(string adresaStrada, int etaj, float chirie, const int nrApt, int nrApartamente, string* locuitori) :nrApartament(nrApt) {
		this->adresaStrada = adresaStrada;
		this->etaj = etaj;
		this->chirie = chirie;
		this->nrApartamente = nrApartamente;
		if (this->locuitori != NULL)
		{
			delete[]this->locuitori;
		}
		this->locuitori = new string[nrApartamente];
		for (int i = 0; i < nrApartamente; i++) 
		{
			this->locuitori[i] = locuitori[i];
		}
	}

	void afisare() {
		cout << "Adresa-Strada:" << this->adresaStrada << endl;
		cout << "Etaj:" << this->etaj << endl;
		cout << "Numarul apartamentului:" << this->nrApartament << endl;
		cout << "Chirie:" << this->chirie << endl;
		cout << "Impozit:" << this->impozit << endl;
		cout << "Nr de apartamente:" << this->nrApartamente << ":" << endl;
		for (int i = 0; i < this->nrApartamente; i++) {
			if (this->locuitori != NULL)
			{
				cout << this->locuitori[i]<< ",";
			}
		}
		cout << endl;
		
	}


	string getAdresaStrada() {
		return adresaStrada;
	}

	void setAdresaStrada(string nouaAdresa) {
		if (adresaStrada.length() > 2)
		{
			this->adresaStrada = nouaAdresa;

		}
	}

	int getEtaj() {
		return etaj;
	}

	void setEtaj(int etaj) {
			this->etaj = etaj;
		}

	float getChirie() {
		return chirie;
	}

	void setChirie(float nouaChirie) {
		if (chirie > 0) {
			this->chirie = nouaChirie;
		}
	}



	int getNrApartamente() {
		return nrApartamente;
	}

	void setNrApartamente(int nrApartamente, string* locuitori) {
		if (nrApartamente > 0) {
			this->nrApartamente = nrApartamente;

			if (this->locuitori != NULL) {
				delete[]this->locuitori;

				this->locuitori = new string[nrApartamente];
				for (int i = 0; i < nrApartamente; i++)
				{
					this->locuitori[i] = locuitori[i];
				}
			}
		}
	}

	string* getLocuitori() {
		return this->locuitori;
	}

	// Constructor de copiere
	Apartament operator=(const Apartament& a) {
			this->adresaStrada = a.adresaStrada;
			this->etaj = a.etaj;
			this->chirie = a.chirie;
			this->nrApartamente = a.nrApartamente;
			if (this->locuitori != NULL) {
				delete[]this->locuitori;
				this->locuitori = new string[a.nrApartamente];
				for (int i = 0; i < a.nrApartamente; i++)
				{
					this->locuitori[i] = a.locuitori[i];
				}

			}
		
		return *this;
	}

	string operator[](int index) {
		if (index >= 0 && index < nrApartamente)
		{
			return locuitori[index];
		}
		
	}

	Apartament operator+(float adaosChirie) {
		Apartament temp = *this;
		temp.chirie = this->chirie + adaosChirie;
		return temp;
	}


	friend Apartament operator+(float adaosChirie,Apartament apt){
		Apartament temp = apt;
		temp.chirie = apt.chirie + adaosChirie;
		return temp;
	}

	Apartament operator+(const Apartament& apt) const {
		Apartament temp = *this;
		temp.chirie = this->chirie + apt.chirie;
		return temp;
	}


	// Destructor
	~Apartament() {
		if (this->locuitori != NULL)
		{
			delete[]this->locuitori;
		}
	}

	friend ostream& operator<<(ostream& output, Apartament a);
	friend istream& operator>>(istream& input, Apartament& a) {
		cout << "Strada:";
		input >> a.adresaStrada;
		cout << "Etaj:";
		input >> a.etaj;
		cout << "Chiria:";
		input >> a.chirie;
		cout << "Nr de apartamente:";
		input >> a.nrApartamente;

		if (a.locuitori != NULL)
		{
			delete[]a.locuitori;
		}
		if (a.nrApartamente > 0) {
			a.locuitori = new string[a.nrApartamente];
			cout << "Locuitori:";
			for (int i = 0; i < a.nrApartamente; i++)
			{
				input >> a.locuitori[i];
			}
		}
		else {
			a.locuitori = NULL;
		}
		return input;
	}

};

int Apartament::impozit = 10;

ostream& operator<<(ostream& output, Apartament a) {
	output << "Adresa-Strada:" << a.adresaStrada << endl;
	output << "Etaj:" << a.etaj << endl;
	output << "Numarul apartamentului:" << a.nrApartament << endl;
	output << "Chirie:" << a.chirie << endl;
	output << "Impozit:" << a.impozit << endl;
	output << "Nr de apartamente:" << a.nrApartamente << ":" << endl;
	for (int i = 0; i < a.nrApartamente; i++) {
		if (a.locuitori != NULL)
		{
			output << a.locuitori[i] << ",";
		}
	}
	return output;
	}

int main() {
	Apartament a1;
	a1.afisare();
	Apartament a2("Mihai Eminescu", 3, 1100);
	a2.afisare();
	Apartament a3("Neptun", 3, 1200, 1, 3, new string[3]{"Ion","Maria","Andrei"});
	a3.afisare();
	cout << endl;
	Apartament a0("Str salcamilor", 4, 1300, 2, 5, new string[5]{ "Popescu","Ionescu" , "Andreescu","Petrescu","Angelescu" });
	
	Apartament a4;
	a4.setAdresaStrada("Strada Avrig");
	a4.setChirie(1111);
	cout << a4 << endl;

	cout << endl;
	cout << a3[1] << endl;
	cout << endl;
	cout << a0[4] << endl;
	cout << endl;

	Apartament a6;
	a6= a6 + 555;
	cout << a6.getChirie() << endl;
	cout << endl;

	Apartament a7;
	a7 = 888 + a7;
	cout << a7.getChirie() << endl;
	cout << endl;

	Apartament a8;
	a8 = a6 + a7;
	cout << a8.getChirie() << endl;
	cout << endl;

	Apartament a5;
	cin >> a5;
	cout << endl;
	a5.afisare();

}