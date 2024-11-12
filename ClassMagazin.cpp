#include<iostream>

using namespace std;

class Magazin {
private:
	const int anDeschidere;
	static int impozit;
	string oras;
	float suprafata;
	int nrAngajati;
	float* salarii;

public:

	// Constrcutor fara parametrii

	Magazin() :anDeschidere(2018) {
		this->oras = "Bucuresti";
		this->suprafata = 30;
		this->nrAngajati = 0;
		this->salarii = NULL;
	}

	// Constructor cu toti parametriii
	Magazin(string oras, float suprafata, const int an, int nrAngajati, float* salarii) :anDeschidere(an) {
		this->oras = oras;
		this->suprafata = suprafata;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = salarii[i];
		}
	}



	// Constructor de copiere
	Magazin(const Magazin& m) :anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->suprafata = m.suprafata;
		this->nrAngajati = m.nrAngajati;
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
	}

	~Magazin() {
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}

	Magazin operator=(const Magazin& m) {
		if (&m != this) {
			this->oras = m.oras;
			this->suprafata = m.suprafata;
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

	string getOras() {
		return this->oras;
	}

	void setOras(string noulOras) {
		if (oras.length() > 1)
		{
			this->oras = noulOras;
		}
	}

	float getSuprafata() {
		return this->suprafata;
	}

	void setSuprafata(float nouaSuprafata) {
		if (suprafata > 0)
		{
			this->suprafata = nouaSuprafata;
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

	// Opefrator index
	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	// Functia de afisare
	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit:" << this->impozit << endl;
		cout << "Nr angajati:" << this->nrAngajati << ":" << endl;
		if (this->salarii != NULL) {
			for (int i = 0; i < nrAngajati; i++) {
				cout << this->salarii[i] << ",";
			}
		}
		cout << endl << endl;
	}


	static void modificaImpozit(int noulImpozit) {
		if (noulImpozit > 0) {
			Magazin::impozit = noulImpozit;
		}
	}


	// Supraincarcare operatori

	Magazin operator+(float adaosSuprafata) {
		Magazin temp = *this;
		temp.suprafata = this->suprafata + adaosSuprafata;
		return temp;
	}

	/*friend Magazin operator+(float adaosSuprafata, Magazin magazin) {
		Magazin temp = magazin;
		temp.suprafata = magazin.suprafata + adaosSuprafata;
		return temp;
	} */ 
	
	/*Magazin operator+(const Magazin& magazin)const {
		Magazin temp = *this;
		temp.suprafata = this->suprafata + magazin.suprafata;
		return temp;
	}*/

	// Supraincarcare peratori alocati dinamic, adaugare de salarii

	friend Magazin operator+(float salariu, Magazin m) {
		Magazin temp = m;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < m.nrAngajati; i++) {
			temp.salarii[i] = m.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
   }


	/*Magazin operator+(float salariu)const {
				Magazin temp = *this;
				if (temp.salarii != NULL) {
					delete[]temp.salarii;
				}
				temp.salarii = new float[temp.nrAngajati ];
				for (int i = 0; i < this->nrAngajati; i++) {
					temp.salarii[i] = this->salarii[i];
				}
				temp.salarii[temp.nrAngajati]=salariu;
				temp.nrAngajati++;
				return temp;
			}*/

	// Supraincarcarea operatorului + pentru a11=a22+a33
	Magazin operator+(Magazin m2)const{
		Magazin temp = *this;
		temp.nrAngajati = this->nrAngajati + m2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < m2.nrAngajati; i++) {
			aux[i + this->nrAngajati] = m2.salarii[i];
		}
		if (temp.salarii != NULL)
		{
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}
	friend ostream& operator<<(ostream& output, Magazin m);

	friend istream& operator>>(istream& input, Magazin& m) {
		cout << "Oras:";
		input >> m.oras;
		cout << "Suprafata:";
		input >> m.suprafata;
		cout << "Nr angajati:";
		input >> m.nrAngajati;
		if (m.salarii != NULL) {
			delete[]m.salarii;
		}
		if (m.nrAngajati > 0)
		{
			m.salarii = new float[m.nrAngajati];
			cout << "Salarii:";
			for (int i = 0; i < m.nrAngajati; i++)
			{
				input >> m.salarii[i];
			}
		}
		else {
			m.salarii = NULL;
		}
		cout << endl << endl;
		return input;
	}


	// Functie care calculeaza salariul mediu

	float CalculeazaSalariulMediu(int nrAngajati, float* salarii) {
		if (nrAngajati > 0 && salarii != NULL) {
			int SumaSalarii = 0;
			for (int i = 0; i < nrAngajati; i++) {
				SumaSalarii = SumaSalarii + salarii[i];
			}
			return SumaSalarii / nrAngajati;
		}
	}


	// Supraincarcare operator ++, mai adaug un angajat, preincrementare
	Magazin operator++() {
		this->nrAngajati++;   // this->nrAngajati=this->nrAngajati+1;
		return *this;
	}
     // postincrementare, mai adaug un angajat
	Magazin operator++(int) {
		Magazin copie = *this;
		this->nrAngajati++;
		return copie;
	}

	// Supraincarcarea operatorului --
	Magazin operator--() {
		this->nrAngajati--;
		return *this;
	}

	Magazin operator--(int) {
		Magazin copie = *this;
		this->nrAngajati--;
		return copie;
	}

};

int Magazin::impozit = 2;


ostream& operator<<(ostream& output, Magazin m) {
	output << "Oras:" << m.oras << endl;
	output << "Suprafata:" << m.suprafata << endl;
	output << "An deschidere:" << m.anDeschidere << endl;
	output << "Impozit:" << m.impozit << endl;
	output << "Nr angajati:" << m.nrAngajati << ":" << endl;
	if (m.nrAngajati>0) {
		for (int i = 0; i <m.nrAngajati; i++) {
			cout << m.salarii[i] << ",";
		}
	}
	cout << endl << endl;
	return output;
}

int main() {
	Magazin m1;
	m1.afisare();
	Magazin m2("Brasov", 50, 2019, 5, new float[5] {5000, 5500, 3000, 4500, 4000});
	cout << m2;

	cout << "Salariul angajatului 1 din magazinul m2 este:" << m2[1] << endl << endl; //5500


	// adaugare suprafata
	Magazin a1;
	a1.setSuprafata(50);
	a1 = a1 + 55;   //105
	cout << a1.getSuprafata() << endl;


   /* a1.setSuprafata(50);
	a1 = 65 + a1;
	cout << a1.getSuprafata() << endl;*/


	Magazin a2;
	Magazin a3;
	a2.setSuprafata(15);
	a3.setSuprafata(30);
	//a1 = a2 + a3; // 45
	cout << a1.getSuprafata() << endl << endl;

	m1.modificaImpozit(5);
	cout << m1;

	cout << "Salariul mediu pentru angajatii magazinului m2 este: " << m2.CalculeazaSalariulMediu(5, new float[5] {5000, 5500, 3000, 4500, 4000}) << endl << endl; // 4400
	cout << endl << endl;


	cout << endl << endl << "Supraincarcare operator +, pt a11=1000+a11 sau a11=a11+1000" << endl << endl;
	Magazin a11("Sibiu", 50, 2019, 3, new float[3] {5000, 5500, 3000});
	cout << a11;
	cout << a11.getNrAngajati() << endl << endl;
	a11 = 1000 + a11;
	for (int i = 0; i < a11.getNrAngajati(); i++) {
		cout << a11.getSalarii()[i] << ",";
		cout << endl;
	}
	cout << endl;

	a11 = a11 + 1000;
	for (int i = 0; i < a11.getNrAngajati(); i++) {
		cout << a11.getSalarii()[i] << ",";
		cout << endl;
	}



	Magazin a22("Sibiu", 50, 2019, 1, new float[1] {5000});
	Magazin a33("Sibiu", 50, 2019, 2, new float[2] {2000,3000});
	cout << " Nr angajati a11:"<<a11.getNrAngajati() << endl;

	cout << endl << endl << "Supraincarcare operator +, a11=a22+a33" << endl << endl;   
	a11 = a22 + a33;
	for (int i=0; i < a11.getNrAngajati(); i++) {
		cout << a11.getSalarii()[i] << ",";
		cout << endl;
	}
	cout << endl << endl;

	cout << "Operatorul de incrementare ++" << endl;
	a22.setNrAngajati(6,new float[6]{1000,2000,3000,4000,5000,6000});
	for (int i = 0; i < a22.getNrAngajati(); i++) {
		cout << a22.getSalarii()[i] << ",";
		cout << endl;
	}
	a22++;
	cout << a22.getNrAngajati() << endl;   // 6+1=7
	++a22;
	cout << a22.getNrAngajati() << endl;   // afiseaza 8

	cout << endl << endl;
	cout << "Operatorul -- " << endl;
	a22.setNrAngajati(6, new float[6] {1000, 2000, 3000, 4000, 5000, 6000});
	a22--;  //5
	cout << a22.getNrAngajati() << endl;
	--a22;  //4
	cout << a22.getNrAngajati() << endl;


	//Magazin m3;
	//cin >> m3;
	//cout << m3;




}