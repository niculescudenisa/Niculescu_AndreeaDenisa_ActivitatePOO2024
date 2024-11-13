#include<iostream>

using namespace std;

class Tablou {
private:
	string nume;
	string artist;
	float pretEstimat;  // pret in euro
	bool restauratRecent;
	int nrLicitanti;
	float* preturiLicitatii;
	const int anCreatie;
	static int nrTablouri;

public:

	// Constructor implicit

	Tablou() :anCreatie(1980) {
		this->nume = "Cantec de toamna";
		this->artist = "Maria Ionescu";
		this->pretEstimat = 500;
		this->restauratRecent = false;
		this->nrLicitanti = 1;
		this->preturiLicitatii = new float[1] {300};

		nrTablouri++;
	}

	// Constructor cu toti parametrii
	Tablou(string nume, string artist, float pretEstimat, bool restauratRecent, const int an, int nrLicitanti, float* preturiLicitatii) :anCreatie(an) {
		this->nume = nume;
		this->artist = artist;
		this->pretEstimat = pretEstimat;
		this->restauratRecent = restauratRecent;
		this->nrLicitanti = nrLicitanti;
		if (nrLicitanti > 0) {
			this->preturiLicitatii = new float[nrLicitanti];
			for (int i = 0; i < nrLicitanti; i++) {
				this->preturiLicitatii[i] = preturiLicitatii[i];
			}
		}
		nrTablouri++;
	}

	// Constructor de copiere

	Tablou(const Tablou& t) :anCreatie(t.anCreatie) {
		this->nume = t.nume;
		this->artist = t.artist;
		this->pretEstimat = t.pretEstimat;
		this->restauratRecent = t.restauratRecent;
		this->nrLicitanti = t.nrLicitanti;
			this->preturiLicitatii = new float[t.nrLicitanti];
			for (int i = 0; i < t.nrLicitanti; i++) {
				this->preturiLicitatii[i] = t.preturiLicitatii[i];
			}
		nrTablouri++;
	}

	// Operatorul =
	Tablou operator=(const Tablou& t) {
		if (&t!= this) {
			this->nume = t.nume;
			this->artist = t.artist;
			this->pretEstimat = t.pretEstimat;
			this->nrLicitanti = t.nrLicitanti;
			if (this->preturiLicitatii != NULL) {
				delete[]this->preturiLicitatii;
			}
			this->preturiLicitatii = new float[t.nrLicitanti];
			for (int i = 0; i < t.nrLicitanti; i++) {
				this->preturiLicitatii[i] = t.preturiLicitatii[i];
			}
		}
		return *this;
	}

	// Functia de afisare
	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Artist:" << this->artist << endl;
		cout << "Pret estimativ:" << this->pretEstimat << endl;
		cout << "Restaurat recent:" << this->restauratRecent << endl;
		cout << "Anul de creatie:" << this->anCreatie << endl;
		cout << "Nr total de tablouri:" << this->nrTablouri << endl;
		cout << "Nr licitanti:" << this->nrLicitanti << ":" << endl;
		if (this->preturiLicitatii != NULL) {
			for (int i = 0; i < nrLicitanti; i++) {
				cout << this->preturiLicitatii[i] << ",";
			}
		}
		cout << endl << endl;
	}

	// Getteri si setteri

	string getNume() {
		return this->nume;
	}

	string getArtist() {
		return this->artist;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}
	

	void setArtist(string artist) {
		if (artist.length() > 1) {
			this->artist = artist;
		}
	}
	 
	int getPretEstimativ() {
		return this->pretEstimat;
	}

	void setPretEstimativ(float noulPret) {
		if (pretEstimat > 0) {
			this->pretEstimat = noulPret;
		}
	}

	int getNrLicitanti() {
		return this->nrLicitanti;
	}

	void setNrLicitanti(int nrLicitanti, float* preturiLicitatii) {
		if (nrLicitanti > 0) {
			this->nrLicitanti = nrLicitanti;

			if (this->preturiLicitatii != NULL)
			{
				delete[]this->preturiLicitatii;
			}

			this->preturiLicitatii = new float[nrLicitanti];
			for (int i = 0; i < nrLicitanti; i++) {
				this->preturiLicitatii[i] = preturiLicitatii[i];
			}
		}
	}

	float* getPreturiLicitatii() {
		return this->preturiLicitatii;
	}


	// Operatorul ++, se adauga o noua persoana la numarul de licitanti

	Tablou operator++() {
		this->nrLicitanti++;
		return *this;
	}

	Tablou operator++(int) {
		Tablou copie = *this;
		this->nrLicitanti++;
		return copie;
	}

	Tablou operator--() {
		this->nrLicitanti--;
		return *this;
	}


	Tablou operator--(int) {
		Tablou copie = *this;
		this->nrLicitanti--;
		return copie;
	}


	//// Oeratorul +

	//Tablou operator+(float adaosPret) {
	//	Tablou temp = *this;
	//	temp.pretEstimat = this->pretEstimat + adaosPret;
	//	return temp;
	//}

	//friend Tablou operator+(float adaosPret, Tablou t) {
	//	Tablou temp = t;
	//	temp.pretEstimat = t.pretEstimat + adaosPret;
	//	return temp;
	//}
	//
	//Tablou operator+(const Tablou& t)const {
	//	Tablou temp = t;
	//	temp.pretEstimat = this->pretEstimat + temp.pretEstimat;
	//	return temp;
	//}

	
	// Operatorul index

	float& operator[](int index) {
		if (index >= 0 && index < nrLicitanti) {
			return preturiLicitatii[index];
		}
	}


	// Operatorul +, adaugare la vectorul alocat dinamic

	friend Tablou operator+(float pret, Tablou t) {
		Tablou temp = t;
		if (temp.preturiLicitatii != NULL) {
			delete[]temp.preturiLicitatii;
		}

		temp.preturiLicitatii = new float[temp.nrLicitanti+1];
		for (int i = 0; i < t.nrLicitanti; i++) {
			temp.preturiLicitatii[i] = t.preturiLicitatii[i];
		}

		temp.preturiLicitatii[temp.nrLicitanti] = pret;
		temp.nrLicitanti++;
		return temp;
	}

	Tablou operator+(Tablou& tt)const {
		Tablou temp = *this;
		temp.nrLicitanti = this->nrLicitanti + tt.nrLicitanti;

		float* aux = new float[temp.nrLicitanti];

		for (int i = 0; i < this->nrLicitanti;i++) {
			aux[i] = this->preturiLicitatii[i];
		}

		for (int i = 0; i < tt.nrLicitanti; i++) {
			aux[i + this->nrLicitanti] = tt.preturiLicitatii[i];
		}

		if (temp.preturiLicitatii != NULL) {
			delete[]temp.preturiLicitatii;
		}
		temp.preturiLicitatii = aux;
		return temp;
	}


	

	// Detructor
	~Tablou() {
		if (this->preturiLicitatii != NULL) {
			delete[]this->preturiLicitatii;
		}
	}

	friend ostream& operator<<(ostream& output, Tablou t);

	friend istream& operator>>(istream& input, Tablou& t) {
		cout << "Nume:";
		input >> t.nume;
		cout << "Artist:";
		input >> t.artist;
		cout << "Pret estimativ:";
		input >> t.pretEstimat;
		cout << "Nr licitanti:";
		input >> t.nrLicitanti;

		if (t.preturiLicitatii != NULL) {
			delete[]t.preturiLicitatii;
		}
		if (t.nrLicitanti > 0 )
		{
			t.preturiLicitatii = new float[t.nrLicitanti];
			cout << "Preturi licitatii:";
			for (int i = 0; i < t.nrLicitanti; i++) {
				input >> t.preturiLicitatii[i];
			}
		}
		else {
			t.preturiLicitatii = NULL;
		}
		cout << endl << endl;
		return input;

	}

	// Functia care calculeaza pretul mediu al licitatiei
	float CalculeazaPretMediuLicitatie(int nrLicitanti, float* preturiLicitatii) {
		if (nrLicitanti > 0 && preturiLicitatii != NULL) {
			float SumaPreturi = 0;
			for (int i = 0; i < nrLicitanti; i++) {
				SumaPreturi = SumaPreturi + preturiLicitatii[i];
			}

			return SumaPreturi / nrLicitanti;
		}
		
	}
};

int Tablou::nrTablouri = 0;


ostream& operator<<(ostream& output, Tablou t) {
	output << "Nume:" << t.nume << endl;
	output << "Artist:" << t.artist << endl;
	output << "Pret estimativ:" << t.pretEstimat << endl;
	output << "Restaurat recent:" << t.restauratRecent << endl;
	output << "Anul de creatie:" << t.anCreatie << endl;
	output << "Nr total de tablouri:" << t.nrTablouri << endl;
	output << "Nr licitanti:" << t.nrLicitanti << ":" << endl;
	if (t.nrLicitanti > 0 ) {
		for (int i = 0; i < t.nrLicitanti; i++) {
			output << t.preturiLicitatii[i] << ",";
		}
	}

	cout << endl << endl;
	return output;
}



int main() {

	Tablou t1;
	t1.afisare();
	Tablou t2("Umbre in gradina", "Raluca Dumitru", 650, true, 1995, 5, new float[5] {400, 450, 500, 550, 600});
	cout << t2;

	
	t2++;  // se adauga 1
	cout << t2.getNrLicitanti() << endl << endl; //6
	--t2; // prefixare, t2 va avea 4 nrLicitanti
	cout << t2.getNrLicitanti() << endl << endl; //5

	Tablou t4("Umbre in gradina", "Raluca Dumitru", 600, true, 1995, 5, new float[5] {300, 450, 500, 550, 600});
	//t4 = 55 + t4;
	//cout << t4.getPretEstimativ() << endl << endl;
	//t4 = t4 + 45; // 700
	//cout << t4.getPretEstimativ() << endl << endl;

	//t4 = t1 + t2; //500+650
	//cout << t4.getPretEstimativ() << endl << endl;

	cout << "Suma licitata pt tabloul 4 de catre a doua persoana:" << t4[1] << endl << endl;  // 450

	t4 = 1000 + t4;
	cout << t4.getNrLicitanti() << endl;
	for (int i = 0; i < t4.getNrLicitanti(); i++) {
		cout << t4.getPreturiLicitatii()[i] << ",";
	}
	cout << endl << endl;

	Tablou t5("a", "b", 700, true, 2000, 2, new float[2] {2222, 3333});
	t1 = t4 + t5;

	cout << t1.getNrLicitanti() << endl;
	for (int i = 0; i < t1.getNrLicitanti(); i++) {
		cout << t1.getPreturiLicitatii()[i] << ",";
	}
	cout << endl << endl;

	Tablou a("A", "B", 700, true, 2000, 5, new float[5] {500,750,800,400,200});
	cout << "Pretul mediu pt licitatia tabloului t1 a fost:" << a.CalculeazaPretMediuLicitatie(5, new float[5] {500, 750, 800, 400, 200}) << endl << endl; //530

	a.setNrLicitanti(2, new float[2] {111, 222});
	cout << t1.getNrLicitanti() << endl << endl;
	for (int i = 0; i < a.getNrLicitanti(); i++) {
		cout << a.getPreturiLicitatii()[i] << ",";
	}
	cout << endl << endl;


	Tablou t3;
	cin >> t3;
	cout << t3;

}