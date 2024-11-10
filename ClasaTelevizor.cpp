#include<iostream>

using namespace std;

class Televizor {
private:
	string marca;
	float pret;
	float dimensiuneEcran;
	bool esteSmart;
	const int anFabricare;
	static int TVA;
	int nrTelevizoare;
	string* distribuitori;

public:

	Televizor() :anFabricare(2020) {
		this->marca = "LG";
		this->pret = 2000;
		this->dimensiuneEcran = 50;
		this->esteSmart = false;
		this->nrTelevizoare = 2;
		this->distribuitori =NULL;
	}

	Televizor(string marca, float pret, float dimensiuneEcran, bool esteSmart) :anFabricare(2019) {
		this->marca = marca;
		this->dimensiuneEcran = dimensiuneEcran;
		this->pret = pret;
		this->esteSmart = false;
	}

	Televizor(string marca, float pret, float dimensiuneEcran, bool esteSmart, const int an, int nrTelevizoare, string* distribuitori) :anFabricare(an) {
		this->marca = marca;
		this->pret = pret;
		this->dimensiuneEcran = dimensiuneEcran;
		this->esteSmart = true;
		this->nrTelevizoare = nrTelevizoare;
		if (this->distribuitori != NULL) {
			delete[]this->distribuitori;
		}
		this->distribuitori = new string[nrTelevizoare];
		for (int i = 0; i < nrTelevizoare; i++)
		{
			this->distribuitori[i] = distribuitori[i];
		}
	}

	Televizor operator=(const Televizor& t) {
		this->marca = t.marca;
		this->pret = t.pret;
		this->dimensiuneEcran = t.dimensiuneEcran;
		this->esteSmart = false;
		this->nrTelevizoare = t.nrTelevizoare;
		if (this->distribuitori != NULL)
		{
			delete[]this->distribuitori;
			this->distribuitori = new string[nrTelevizoare];
			for (int i = 0; i < t.nrTelevizoare; i++)
			{
				this->distribuitori[i] = t.distribuitori[i];
			}
		}
		return *this;
	}

	string getMarca() {
		return marca;
	}

	void setMarca(string nouaMarca) {
		if (marca.length() > 1) {
			this->marca = nouaMarca;
		}
	}

	float getPret() {
		return pret;
	}

	void setPret(float noulPret) {
		if (pret > 0) {
			this->pret = noulPret;
		}
	}

	float getDimensiuneEcran() {
		return dimensiuneEcran;
	}

	void setDimensiuneEcran(float nouaDimensiuneEcran) {
		if (dimensiuneEcran > 0)
		{
			this->dimensiuneEcran = nouaDimensiuneEcran;
		}
	}


	bool getEsteSmart() {
		return esteSmart;
	}

	void setEsteSmart(bool esteSmart) {
		this->esteSmart = esteSmart;
	}

	int getNrTelevizoare() {
		return nrTelevizoare;
	}

	void setNrTelevizoare(int noulnrTelevizoare, string* noiidistribuitori) {
		if (nrTelevizoare > 0) {
			this->nrTelevizoare = noulnrTelevizoare;

			if (this->distribuitori != NULL)
			{
				delete[]this->distribuitori;
			}
			this->distribuitori = new string[noulnrTelevizoare];
			for (int i = 0; i < nrTelevizoare; i++) {
				this->distribuitori[i] = noiidistribuitori[i];
			}
		}
	}

	string* getDistribuitori() {
		return this->distribuitori;
	}

	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Pretul:" << this->pret << endl;
		cout << "Dimensiune ecran:" << this->dimensiuneEcran << endl;
		cout << "An fabricatie:" << this->anFabricare << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "Este smart:" << this->esteSmart << endl;
		cout << "Nr televizoare:" << this->nrTelevizoare << ":";
		for (int i = 0; i < this->nrTelevizoare; i++)
		{
			if (this->distribuitori != NULL)
			{
				cout << this->distribuitori[i] << ",";
			}
		}
		cout << endl << endl;

	}

	string operator[](int index) {
		if (index >= 0 && index < nrTelevizoare)
		{
			return distribuitori[index];
		}
	}


	Televizor operator+(float adaosPret) {
		Televizor temp = *this;
		temp.pret = temp.pret + adaosPret;
		return temp;
	}

	friend Televizor operator+(float adaosPret, Televizor t) {
		Televizor temp = t;
		temp.pret = t.pret + adaosPret;
		return temp;
	}

	Televizor operator+(const Televizor& t)const {
		Televizor temp = *this;
		temp.pret = this->pret + t.pret;
		return temp;
	}

	~Televizor() {
		if (this->distribuitori != NULL)
		{
			delete[]this->distribuitori;
		}
	}

	friend ostream& operator<<(ostream& output, Televizor t);


	friend istream& operator>>(istream& input, Televizor& t) {
		cout << "Marca:";
		input >> t.marca;
		cout << "Pretul:";
		input >> t.pret;
		cout << "Dimensiune ecran:";
		input >> t.dimensiuneEcran;
		cout << "Nr televizoare:";
		input >> t.nrTelevizoare;
		if (t.distribuitori != NULL)
		{
			delete[]t.distribuitori;
		}
		if (t.nrTelevizoare > 0)
		{
			t.distribuitori = new string[t.nrTelevizoare];
			cout << "Distribuitori:";
			for (int i = 0; i < t.nrTelevizoare; i++)
			{
				input >> t.distribuitori[i];
			}
		}
		return input;
	}


};

int Televizor::TVA = 19;


ostream& operator<<(ostream& output, Televizor t) {
	output << "Marca:" << t.marca << endl;
	output << "Pretul:" << t.pret << endl;
	output << "Dimensiune ecran:" << t.dimensiuneEcran << endl;
	output << "An fabricatie:" << t.anFabricare << endl;
	output << "TVA:" << t.TVA << endl;
	output << "Este smart:" << t.esteSmart << endl;
	output << "Nr televizoare:" << t.nrTelevizoare << ":";
	for (int i = 0; i < t.nrTelevizoare; i++)
	{
		if (t.distribuitori != NULL)
		{
			output << t.distribuitori[i] << ",";
		}
	}
	return output;

}



int main() {
	Televizor t1;
	t1.afisare();
	Televizor t2("Samsung", 3000, 45, false);
	t2.afisare();
	Televizor t3("Philips", 5000, 60, true, 2023, 3, new string[3]{ "Altex","Flanco","Emag" });
	t3.afisare();

	Televizor t4;
	t4.setMarca("Sony");
	t4.setPret(7000);
	t4.setEsteSmart(true);
	cout << t4 << endl << endl;

	cout << t3[1] << endl << endl;

	Televizor t6;
	Televizor t7;
	Televizor t8;
	t8 = t8 + 555; // 2000+555
	cout << t8.getPret() << endl << endl;
	t8.setPret(3000);
	t8 = 666 + t8; //666+3000
	cout << t8.getPret() << endl << endl;

	t7.setPret(3300);
	t8.setPret(3400);
	t6 = t7 + t8;  // 3300+3400
	cout << t6.getPret() << endl << endl;

	Televizor t5;
	cin >> t5;
	cout << endl << endl;
	t5.afisare();

	

}