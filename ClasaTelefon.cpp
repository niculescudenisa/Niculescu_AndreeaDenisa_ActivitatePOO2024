#include<iostream>

using namespace std;

class Telefon {
private:
	string denumire;
	int stoc;
	float pret;
	const int anAparitie;
	static int TVA;
	int nrDistribuitori;
	string* distribuitori;

public:

	// Constructor implicit
	Telefon() :anAparitie(2019) {
		this->denumire = "Samsung A50";
		this->stoc = 5;
		this->pret = 1000;
		this->nrDistribuitori = 3;
		this->distribuitori = NULL;
	}

	// Constructor cu 2 parametrii
	Telefon(string denumire, float pret) :anAparitie(2020) {
		this->denumire = denumire;
		this->pret = pret;
		this->stoc = 0;
		this->nrDistribuitori = 0;
		this->distribuitori = NULL;

	}

	// Constructor cu toti parametrii
	Telefon(string denumire, int stoc, float pret, const int an, int nrDistribuitori, string* distribuitori) :anAparitie(an) {
		this->denumire = denumire;
		this->stoc = stoc;
		this->pret = pret;
		this->nrDistribuitori = nrDistribuitori;
		if (this->distribuitori != NULL)
		{
			delete[]this->distribuitori;
		}
		this->distribuitori = new string[nrDistribuitori];
		for (int i = 0; i < nrDistribuitori; i++)
		{
			this->distribuitori[i] = distribuitori[i];
		}
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

	int getStoc() {
		return stoc;
	}

	void setStoc(int noulStoc) {
		if (stoc > 0)
		{
			this->stoc = noulStoc;
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

	int getNrDistribuitori() {
		return nrDistribuitori;
	}

	void setNrDistribuitori(int nrDistribuitori,string* distribuitori) {
		if (nrDistribuitori > 0)
		{
			this->nrDistribuitori = nrDistribuitori;

			if (this->distribuitori != NULL)
			{
				delete[]this->distribuitori;

				this->distribuitori = new string[nrDistribuitori];
				for (int i = 0; i < nrDistribuitori; i++)
				{
					this->distribuitori[i] = distribuitori[i];
				}
			}
		}
	}


	string* getDistribuitori() {
		return this->distribuitori;
	}



	// Constructor de copiere
	Telefon operator=(const Telefon& t)
	{
		this->denumire = t.denumire;
		this->stoc = t.stoc;
		this->pret = t.pret;
		this->nrDistribuitori = t.nrDistribuitori;
		if (this->distribuitori != NULL) {
			delete[]this->distribuitori;
			this->distribuitori = new string[t.nrDistribuitori];
			for (int i = 0; i < t.nrDistribuitori; i++) {
				this->distribuitori[i] = t.distribuitori[i];
			}
		}
		return *this;

	}


	// Functia de afisare
	void afisare() {
		cout << "Denumirea:" << this->denumire << endl;
		cout << "Nr. stoc:" << this->stoc << endl;
		cout << "Pretul:" << this->pret << endl;
		cout << "An aparitie:" << this->anAparitie << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "Nr distribuitori:" << this->nrDistribuitori << ":" << endl;
		
		for (int i = 0; i < this->nrDistribuitori; i++) {
			if (this->distribuitori != NULL)
			{
				cout << this->distribuitori[i] << ",";
			}
		}
		cout << endl;
	}

	// Supraincarcarea operatorilor

	Telefon operator+(float adaosPret)const {
		Telefon temp = *this;
		temp.pret += adaosPret;
		return temp;
	}

	Telefon operator+(const Telefon& m) const {
		Telefon temp = *this;
		temp.pret = this->pret + m.pret;
		return temp;
	}


	string& operator[](int index) {
		if (index >=0 && index < this->nrDistribuitori)
		{
			return this->distribuitori[index];
		}
		else
		{
			throw " Exceptie.";
		}
	}



	// Destructor
	~Telefon() {
		if (this->distribuitori != NULL)
		{
			delete[]this->distribuitori;
		}
	}


	friend ostream& operator<<(ostream& output, Telefon t);

	friend istream& operator>>(istream& input, Telefon& t) {
		cout << "Denumire:";
		input >> t.denumire;
		cout << "Stoc:";
		input >> t.stoc;
		cout << "Pret:";
		input >> t.pret;
		cout << "Nr distribuitori:";
		input >> t.nrDistribuitori;
		if (t.distribuitori != NULL)
		{
			delete[]t.distribuitori;
		}
		if (t.nrDistribuitori > 0) {
			t.distribuitori = new string[t.nrDistribuitori];
			cout << "Distribuitori:";
			for (int i = 0; i < t.nrDistribuitori; i++)
			{
				input >> t.distribuitori[i];
			}
		}
		else {
			t.distribuitori = NULL;
			}
		return input;
	}



};

int Telefon::TVA = 19;

ostream& operator<<(ostream& output, Telefon t) {
		output << "Denumirea:" << t.denumire << endl;
		output << "Nr. stoc:" << t.stoc << endl;
		output << "Pretul:" << t.pret << endl;
		output << "An aparitie:" << t.anAparitie << endl;
		output << "TVA:" << t.TVA << endl;
		output << "Nr distribuitori:" << t.nrDistribuitori << ":" << endl;
		
		for (int i = 0; i < t.nrDistribuitori; i++) {
			if (t.distribuitori != NULL)
			{
				output << t.distribuitori[i] << ",";
			}
		}
		return output;
	} 

int main() {
	Telefon t1;
	t1.afisare();
	Telefon t2("Samsung A51", 1600);
	t2.afisare();

	Telefon t3("Huawei Pro S21", 5, 2000, 2022, 3, new string[3]{ "Altex","Emag","Flanco" });
	t3.afisare();
	cout << endl;


	Telefon t5;
	t5 = t5 + 3333;   // 1000+3333
	cout << endl;
	cout << t5.getPret() << endl;
	cout << endl;

	Telefon t4 = t4 + 2222;
	cout << t4 << endl;


	Telefon t6("Apple", 5000);
	t6.setDenumire("Apple Pro");
	cout << t6.getDenumire() << endl;

	cout << endl;

	try {
		cout << t3[2] << endl;
	}
	catch (int ex) {

	}
	catch (float ex) {

	}
	catch (string* exceptie)
	{
		cout << exceptie;
	}
	catch (...) {

	}
	cout << endl;

	
	cin >> t5;
	cout << endl;

	t1.setDenumire("SAMSUNG GALAXY S20");
	t1.setPret(1111);
	t1.setStoc(10);
	cout << t1.getDenumire() <<endl<<t1.getPret()<<endl<<t1.getStoc()<< endl;

}