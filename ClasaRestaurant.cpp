#include<iostream>

using namespace std;

class Restaurant {
private:
	string nume;
	string tip;
	int nrMese;
	const int anDeschidere;
	static string numeManager;
	bool servesteMancareVegana;
	int nrPreparate;
	float* preturi;

public:
	Restaurant() :anDeschidere(2017) {
		this->nume = "Vivo";
		this->tip = "Italienesc";
		this->nrMese = 10;
		this->servesteMancareVegana = false;
		this->nrPreparate = 3;
		this->preturi = new float[nrPreparate];
		preturi[0] = 50;
		preturi[1] = 60;
		preturi[2] = 70;
	}

	Restaurant(string nume, string tip, int nrMese) :anDeschidere(2018) {
		this->nume = nume;
		this->tip = tip;
		this->nrMese = nrMese;
		this->servesteMancareVegana = false;
		this->nrPreparate = 5;
		this->preturi = NULL;
	}

	Restaurant(string nume, string tip, int nrMese, bool servesteMancareVegana, const int an, int nrPreparate, float* preturi) :anDeschidere(an) {
		this->nume = nume;
		this->tip = tip;
		this->nrMese = nrMese;
		this->servesteMancareVegana = true;
		this->nrPreparate = nrPreparate;
		if (this->preturi != NULL)
		{
			delete[]this->preturi;
		}
		this->preturi = new float[nrPreparate];
		for (int i = 0; i < nrPreparate; i++)
		{
			this->preturi[i] = preturi[i];
		}
	}

	Restaurant operator=(const Restaurant& r) {
		this->nume = r.nume;
		this->tip = r.tip;
		this->nrMese = r.nrMese;
		this->servesteMancareVegana = r.servesteMancareVegana;
		this->nrPreparate = r.nrPreparate;
		if (this->preturi != NULL)
		{
			delete[]this->preturi;
		}
		this->preturi = new float[r.nrPreparate];
		for (int i = 0; i < r.nrPreparate; i++)
		{
			this->preturi[i] = r.preturi[i];
		}
		return *this;
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Tip:" << this->tip << endl;
		cout << "Nr mese:" << this->nrMese << endl;
		cout << "Serveste mancare vegana:" << this->servesteMancareVegana << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Nume manager:" << this->numeManager << endl;
		cout << "Nr preparate:" << this->nrPreparate << ":" << endl;
		for (int i = 0; i < nrPreparate; i++)
		{
			if (this->preturi != NULL)
			{
				cout << this->preturi[i] << ",";
			}
		}
		cout << endl << endl;
	}

	string getNume() {
		return nume;
	}

	void setNume(string noulNume)
	{
		if (nume.length() > 0) {
			this->nume = noulNume;
		}
	}

	string getTip() {
		return tip;
	}

	void setTip(string noulTip) {
		if (tip.length() > 0) {
			this->tip = noulTip;
		}
	}

	int getNrMese() {
		return nrMese;
	}

	void setNrMese(int noulNrMese) {
		if (nrMese > 0)
		{
			this->nrMese = noulNrMese;
		}
	}

	int getNrPreparate() {
		return nrPreparate;
	}

	void setNrPreoarate(int noulNrPreparate, float* preturi) {
		if (nrPreparate > 0)
		{
			this->nrPreparate = noulNrPreparate;
			if (this->preturi != NULL)
			{
				delete[]this->preturi;
			}
			this->preturi = new float[noulNrPreparate];
			for (int i = 0; i < noulNrPreparate; i++)
			{
				this->preturi[i] = preturi[i];
			}
		}
	}

	float* getPreturi() {
		return this->preturi;
	}

	float operator[](int index) {
		if (index >= 0 && index < nrPreparate) {
			return preturi[index];
		}
	}

	Restaurant operator+(int adaosMese) {
		Restaurant temp = *this;
		temp.nrMese += adaosMese;
		return temp;

	}

	friend Restaurant operator+(int adaosMese, Restaurant restaurant) {
		Restaurant temp = restaurant;
		temp.nrMese = restaurant.nrMese + adaosMese;
		return temp;
	}

	Restaurant operator+(const Restaurant& r)const {
		Restaurant temp = *this;
		temp.nrMese = this->nrMese + r.nrMese;
		return temp;

	}

	friend ostream& operator<<(ostream& output, Restaurant r);

	friend istream& operator>>(istream& input, Restaurant& r) {
		cout << "Nume:";
		input >> r.nume;
		cout << "Tip:";
		input >> r.tip;
		cout << "Nr mese:";
		input >> r.nrMese;
		cout << "Serveste mancare vegana:";
		input >> r.servesteMancareVegana;
		cout << "Nr preparate:";
		input >> r.nrPreparate;
		if (r.preturi != NULL) {
			delete[]r.preturi;
		}
		r.preturi = new float[r.nrPreparate];
		for (int i = 0; i < r.nrPreparate; i++) {
			input >> r.preturi[i];
		}
		cout << endl;
		return input;
		
	}
};


string Restaurant::numeManager = "Andreescu Ioan";


ostream& operator<<(ostream& output, Restaurant r)
{
	output << "Nume:" << r.nume << endl;
	output << "Tip:" << r.tip << endl;
	output << "Nr mese:" << r.nrMese << endl;
	output << "Serveste mancare vegana:" << r.servesteMancareVegana << endl;
	output << "An deschidere:" << r.anDeschidere << endl;
	output << "Nume manager:" << r.numeManager << endl;
	output << "Nr preparate:" << r.nrPreparate << ":" << endl;
	for (int i = 0; i < r.nrPreparate; i++)
	{
		if (r.preturi != NULL)
		{
			output << r.preturi[i] << ",";
		}
	}
	output << endl;
	return output;
	output << endl;
	
}


int main() {
	Restaurant r1;
	r1.afisare();
	Restaurant r2("Sakura", "Japonez", 15);
	cout << r2;
	Restaurant r3("CurrySpot", "Indian", 20, true, 2020, 6, new float[6] {55, 75, 85, 65, 90, 80});
	cout << r3;

	cout << endl;
	cout << r3[0] <<endl<< r3[1]<<endl << r3[2] << endl << endl;

	Restaurant r6;
	Restaurant r7;
	Restaurant r8;
	r6.setNrMese(10);
	r6 = r6 + 9;  // 10+9
	cout << r6.getNrMese() << endl;

	r6.setNrMese(10);
	r6 = 11 + r6;  //+10
	cout << r6.getNrMese() << endl;

	r6.setNrMese(15);
	r7.setNrMese(16);
	r8 = r6 + r7;  // 15+16
	cout << r8.getNrMese() << endl;


	Restaurant r4;
	cout << endl;
	cin >> r4;
	cout << endl;
	cout << r4 << endl;

}