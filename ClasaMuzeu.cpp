#include<iostream>

using namespace std;

class Muzeu {
private:
	string nume;
	string oras;
	int nrExponate;
	float pretBilet;
	const int anInfiintare;
	static int nrZileVizitare;
	int nrAngajati;
	float* salarii; 

public:

	// Constructor fara parametrii
	Muzeu() :anInfiintare(2005) {
		this->nume = "Muzeul de Istorie ";
		this->oras = "Bucuresti";
		this->nrExponate = 70;
		this->pretBilet = 50;
		this->nrAngajati = 7;
		this->salarii = NULL;
	}

	// Constructor cu toti parametrii
	Muzeu(string nume, string oras, int nrExponate, float pretBilet, const int an, int nrAngajati, float* salarii) :anInfiintare(an) {
		this->nume = nume;
		this->oras = oras;
		this->nrExponate = nrExponate;
		this->pretBilet = pretBilet;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = salarii[i];
		}
	}

	// Destructor
	~Muzeu()
	{
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}

	// Constructor de copiere
	Muzeu(const Muzeu& m) :anInfiintare(m.anInfiintare) {
		this->nume = m.nume;
		this->oras = m.oras;
		this->nrExponate = m.nrExponate;
		this->pretBilet = m.pretBilet;
		this->nrAngajati = m.nrAngajati;
		if (m.nrAngajati > 0 && m.salarii != NULL) {

			this->salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++) {
				this->salarii[i] = m.salarii[i];
			}
		}
		else {
			this->salarii = NULL;
		}
	}

	// Operatorul de atribuire 
	Muzeu operator=(const Muzeu& m){
		if (&m != this) {
			this->nume = m.nume;
			this->oras = m.oras;
			this->nrExponate = m.nrExponate;
			this->pretBilet = m.pretBilet;
			this->nrAngajati = m.nrAngajati;
			
				if (this->salarii != NULL) {
					delete[]this->salarii;
				}
				this->salarii = new float[m.nrAngajati];
				for (int i = 0; i < m.nrAngajati; i++) {
					this->salarii[i] = m.salarii[i];
				}
			

		}
		return *this;
	}

	// Getteri si Setteri

	string getNume() {
		return this->nume;
	}

	string getOras() {
		return this->oras;
	}

	int getNrExponate() {
		return this->nrExponate;
	}

	float getPretBilet() {
		return this->pretBilet;
	}

	void setNume(string noulNume) {
		if (nume.length() > 1) {
			this->nume = noulNume;
		}
	}

	void setOras(string oras) {
		if (oras.length() > 1) {
			this->oras = oras;
		}
	}

	void setNrExponate(int noulNrExponate) {
		if (nrExponate > 0) {
			this->nrExponate = noulNrExponate;
		}
	}

	void setPretBilet(float noulPret) {
		if (pretBilet > 0) {
			this->pretBilet = noulPret;
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
			for (int i = 0; i < nrAngajati; i++)
			{
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}


	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Oras:" << this->oras << endl;
		cout << "Nr exponate" << this->nrExponate << endl;
		cout << "Pret bilet:" << this->pretBilet << endl;
		cout << "Anul infiintarii" << this->anInfiintare << endl;
		cout << "Nr zile vizitare/saptamana:" << this->nrZileVizitare << endl;
		cout << "Nr angajati:" << this->nrAngajati << ":" << endl;
		
			if (this->salarii != NULL) {
				for (int i = 0; i < nrAngajati; i++){
				cout << this->salarii[i] << ",";
			}
		}
			cout << endl << endl;
	}

	friend ostream& operator<<(ostream& output, Muzeu m);

	friend istream& operator>>(istream& input, Muzeu& m) {
		cout << "Nume:";
		input >> m.nume;
		cout << "Oras:";
		input >> m.oras;
		cout << "Nr exponate:";
		input >> m.nrExponate;
		cout << "Pret bilet:";
		input >> m.pretBilet;
		cout << "Nr angajati:";
		input >> m.nrAngajati;
		if (m.salarii != NULL) {
			delete[]m.salarii;
		 }
		m.salarii = new float[m.nrAngajati];
		cout << "Salarii:";
		for (int i = 0; i < m.nrAngajati; i++) {
			input >> m.salarii[i];
		}
		cout << endl << endl;
		return input;
	}

	// Operatorul de index
	float& operator[](int index) {
		if (index >= 0 && index < nrAngajati) {
			return salarii[index];
		}
	}

	// Operatorul ++, prefixare si postfixare, adaugare de un nou exponat
	Muzeu operator++() {
		this->nrExponate++;
		return *this;
	}
	Muzeu operator--(int) {
		Muzeu copie = *this;
		this->nrExponate--;
		return copie;
	}

	// Modificare nr zile vizitare pe saptamana

	void ModificaNrZileVizitare(int noulNrZileVizitare) {
		if (noulNrZileVizitare > 0) {
			Muzeu::nrZileVizitare = noulNrZileVizitare;
		}
	}

	// Functia care calzuleaza salariul mediu
	float CalculeazaSalariulMediu(int nrAngajati, float* salarii) {
		if (nrAngajati > 0 && salarii != NULL) {
			int SumaSalarii = 0;
			for (int i = 0; i < nrAngajati; i++) {
				SumaSalarii = SumaSalarii + salarii[i];
			}
			return SumaSalarii / nrAngajati;
		}
	}

	//// Operatorul +, pentru adaos la pretul biletului
	//Muzeu operator+(float adaosPret) {
	//	Muzeu temp = *this;
	//	temp.pretBilet = this->pretBilet + adaosPret;
	//	return temp;
	//}
	//
	//friend Muzeu operator+(float adaosPret, Muzeu muzeu) {
	//	Muzeu temp = muzeu;
	//	temp.pretBilet = muzeu.pretBilet + adaosPret;
	//	return temp;
	//}

	//Muzeu operator+(const Muzeu& muzeu)const {
	//	Muzeu temp = *this;
	//	temp.pretBilet = this->pretBilet + muzeu.pretBilet;
	//	return temp;
	//}


	// Operator + ,pentru vectorul alocat dinamic

	friend Muzeu operator+(float salariul, Muzeu m) {
		Muzeu temp = m;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}

		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < m.nrAngajati; i++) {
			temp.salarii[i] = m.salarii[i];
		}

		temp.salarii[temp.nrAngajati] = salariul;
		temp.nrAngajati++;
		return temp;
	}

	Muzeu operator+(float salariul) {
		Muzeu temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}

		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}

		temp.salarii[temp.nrAngajati] = salariul;
		temp.nrAngajati++;
		return temp;
	}


	


	Muzeu operator+(Muzeu muzeu)const {
		Muzeu temp = *this;
		temp.nrAngajati = this->nrAngajati + muzeu.nrAngajati;
		float* aux = new float[temp.nrAngajati];

		for(int i=0;i<this->nrAngajati;i++){
			aux[i] = this->salarii[i];
		}

		for (int i = 0; i < muzeu.nrAngajati; i++) {
			aux[i + this->nrAngajati] = muzeu.salarii[i];
		}

		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}

		temp.salarii = aux;
		return temp;

	}






};

int Muzeu::nrZileVizitare = 6;

ostream& operator<<(ostream& output, Muzeu m) {
	output << "Nume:" << m.nume << endl;
	output << "Oras:" << m.oras << endl;
	output << "Nr exponate:" << m.nrExponate << endl;
	output << "Pret bilet:" << m.pretBilet << endl;
	output << "Anul infiintarii:" << m.anInfiintare << endl;
	output << "Nr zile vizitare/saptamana:" << m.nrZileVizitare << endl;
	output << "Nr angajati:" << m.nrAngajati << ":" << endl;

	if (m.salarii != NULL) {
		for (int i = 0; i < m.nrAngajati; i++) {
			output << m.salarii[i] << ",";
		}
	}
	cout << endl << endl;
	return output;
}

int main() {
	Muzeu m1;
	m1.afisare();
	Muzeu m2("Muzeul de Cultura", "Brasov", 60, 80, 2005, 6, new float[6] {2500, 3000, 3500, 4000, 4500, 5000 });
	cout << m2;

	cout << "Salariul angajatului din m2 de pe pozitia 1:" << m2[1] << endl << endl; //3000
	++m2; //prefixat
	cout << m2.getNrExponate() << endl << endl; //61
	m2.setNrExponate(60);
	m2--; //postfixat
	cout << m2.getNrExponate() << endl << endl; // 59

	Muzeu m3;
	++m3;;
	cout << m3.getNrExponate() << endl << endl; //71
	m3.ModificaNrZileVizitare(7);
	cout << m3;

	Muzeu m5("Muzeul de Cultura", "Brasov", 60, 50, 2005, 6, new float[6] {2500, 3000, 3500, 4000, 4500, 5000});
	cout <<"Salariul mediu al angajatilor din m5 este:"<< m5.CalculeazaSalariulMediu(6, new float[6] {2500, 3000, 3500, 4000, 4500, 5000}) << endl << endl; //3750

	//m5 = m5 + 15;  //50+15
	//cout << m5.getPretBilet() << endl;
	//m5 = 10 + m5;  // 10+65
	//cout << m5.getPretBilet() << endl << endl;
	
	cout << m5.getNrAngajati() << endl;
	for (int i = 0; i < m5.getNrAngajati(); i++) {
		cout << m5.getSalarii()[i] << ",";
	}
	cout << endl << endl;

	cout << endl << endl;
	Muzeu m6("Muzeul de Arta", "Brasov", 50, 85, 2020, 5, new float[5] {3000, 3200, 3400, 3600, 3800});
	cout << m6.getNrAngajati() << endl;
	for (int i = 0; i< m6.getNrAngajati(); i++) {
		cout << m6.getSalarii()[i] << ",";
	}
	cout << endl << endl;


	m6 = 2000 + m6;
	m6 = m6 + 5000;
	cout << m6.getNrAngajati() << endl;
	for (int i = 0; i < m6.getNrAngajati(); i++) {
		cout << m6.getSalarii()[i] << ",";
	}
	cout << endl << endl;

	Muzeu m7("Muzeul de Arta", "Brasov", 50, 85, 2020, 5, new float[5] {3000, 3200, 3400, 3600, 3800});
	Muzeu m8("Muzeul de Arta", "Brasov", 50, 85, 2020, 6, new float[6] {4000, 4200, 4400, 4600, 4800, 5000});
	m6 = m7 + m8;
	cout << m6.getNrAngajati() << endl;
	for (int i = 0; i < m6.getNrAngajati(); i++) {
		cout << m6.getSalarii()[i] << ",";
	}

	cout << endl << endl;


	Muzeu m4;
	cin >> m4;
	cout << m4;

	cout << endl << endl;

}