#include<iostream>

using namespace std;

class Masina {
private:

	int nrroti;
	string* producatori;
	string marca;
	char* culoare;
	float pret;
	static int TVA;
	const int anfabricatie;

public:
	Masina() :anfabricatie(2024), nrroti(4) {
		this->marca = "Dacia";
		this->pret = 5000;
		this->producatori = NULL;
	}

	Masina(int _nrroti, string marca, float pret, int an) :anfabricatie(an) {
		this->nrroti = _nrroti;
		this->marca = marca;
		this->pret = pret;
		this->producatori = new string[this->nrroti];
		for (int i = 0; i < this->nrroti; i++)
		{
			this->producatori[i] = "Michelin";
		}
	}

	Masina(const Masina& m) :anfabricatie(m.anfabricatie) {
		this->nrroti = m.nrroti;
		this->marca = m.marca;
		this->pret = m.pret;
		this->producatori = new string[m.nrroti];
		for (int i = 0; i < nrroti; i++)
		{
			this->producatori[i] = m.producatori[i];
		}
	}

	~Masina() {
		if (this->producatori != NULL)
		{
			delete[]this->producatori;
		}
	}


	string getMarca()
	{
		return this->marca;
	}

	void setMarca(string marca) {
		if (marca.length() > 2)
		{
			this->marca = marca;
		}
	}


	float getPret()
	{
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0)
		{
			this->pret = pret;
		}
	}


	string* getProducatori()
	{
		return this->producatori;
	}

	string getProducator(int index) {
		if (index >= 0 && index < this->nrroti)
		{
			return this->producatori[index];
		}
		else
		{
			return "Nu a fost gasit";
		}
	}


	void setNrRoti(int nrroti, string* producatori) {
		if (nrroti > 0) {
			this->nrroti = nrroti;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrroti];
			for (int i = 0; i < nrroti; i++)
			{
				this->producatori[i] = producatori[i];
			}
		}
	}


	friend Masina operator+(float adaosPret, Masina m) {
		Masina temp = m;
		temp.pret += adaosPret;
		return temp;
	}


	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Numar roti:" << this->nrroti << ":" << endl;
		for (int i = 0; i < this->nrroti; i++)
		{
			if (this->producatori != NULL)
			{
				cout << this->producatori[i] << ",";
			}
		}
		cout << endl;

		cout << "Pretul:" << this->pret << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An fabricatie:" << this->anfabricatie << endl;

	}

	float calculeazaPretTotal()
	{
		return this->pret + (this->pret * this->TVA / 100);
	}


	static void modificaTVA(int noulTVA)
	{
		if (noulTVA > 0)
		{
		Masina:TVA = noulTVA;
		}
	}


	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float PretTotal = 0;
		for (int i = 0; i < nrMasini; i++)
		{
			PretTotal += vector[i].calculeazaPretTotal();
		}
		return PretTotal;
	}


	Masina operator=(const Masina& m) {
		if (this != &m) {
			this->nrroti = m.nrroti;
			this->marca = m.marca;
			this->pret = m.pret;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrroti];
			for (int i = 0; i < m.nrroti; i++) {
				this->producatori[i] = m.producatori[i];
			}
		}
		return *this;
	}

	Masina operator+(const Masina& m) const {
		Masina temp = *this;
		temp.pret = this->pret + m.pret;
		return temp;
	}

	Masina operator+=(Masina m) {
		this->pret = this->pret + m.pret;
		return *this;
	}

	Masina operator+=(float adaosPret) {
		this->pret += adaosPret;
		return *this;
	}

	Masina operator+(float adaosPret)const {
		Masina temp = *this;
		temp.pret += adaosPret;
		return temp;
	}



	explicit operator int() {
		return this->nrroti;
	}

	explicit operator float() {
		return calculeazaPretTotal();
	}


	string& operator[](int index) {
		if (index >= 0 && index < this->nrroti)
		{
			return this->producatori[index];
		}

		else
		{
			throw " Index in afara limitelor";
			//throw
			//try
			//catch
		}
	}

	bool operator<(Masina m) {
		return this->pret < m.pret;
	}



	friend istream& operator>>(istream& input, Masina& m) {
		cout << "Marca:";
		input >> m.marca;
		cout << "Numar roti:";
		input >> m.nrroti;
		if (m.producatori != NULL) {
			delete[]m.producatori;
		}
		if (m.nrroti > 0)
		{
			m.producatori = new string[m.nrroti];
			cout << "Producatori:";
			for (int i = 0; i < m.nrroti; i++) {
				input >> m.producatori[i];
			}
		}

		else
		{
			m.producatori = NULL;
		}
		cout << "Pretul:";
		input >> m.pret;

		return input;

	}

	
	friend ostream& operator<<(ostream& output, Masina m);
};

ostream& operator<<(ostream& output, Masina m) {
	output << "Marca:" << m.marca << endl;
	output << "Numar roti:" << m.nrroti << ":" << endl;
	for (int i = 0; i < m.nrroti; i++)
	{
		if (m.producatori != NULL)
		{
			output << m.producatori[i] << ",";
		}
	}
	output << endl;

	output << "Pretul:" << m.pret << endl;
	output << "TVA:" << m.TVA << endl;
	output << "An fabricatie:" << m.anfabricatie << endl;


	return output;
}


int Masina::TVA = 19;     // Initializare atribute statice


int main()
{
	cout << "Seminar 6 - Clasa Masina continuare" << endl;
	cout << endl << endl;;
	Masina m1;
	Masina m2(4, "BMW", 45000, 2021);


	float pretMasina = (float)m2;
	m1 = m2;
	cout << pretMasina << endl;
	int nrroti = (int)m2;
	cout << nrroti << endl;
	cout << (int)m2 << endl;

	try {
		cout << m2[1] << endl;
		m2[1] = "Hankook";
		cout << m2[1] << endl;
	}
	catch (int ex) {

	}
	catch (float ex) {

	}
	catch (const char* exceptie) {
		cout << exceptie;
	}
	catch (...) {

	}

	cout << m2 << endl;
	cin >> m2;
	cout << endl << m2 << endl;

	if (m2 < m1) {

	}


	// -> - dereferentiere + accesare
	// [] - deplasare + dereferentiere
}