#include<iostream>

using namespace std;

class Masina {
public:

	int nrroti;
	string marca;
	char* culoare;
	float pret;
	static int TVA;
	const int anfabricatie;


	Masina():anfabricatie(2024), nrroti(4) {      
		this->marca = "Dacia";
		this->pret = 5000;
	}

	Masina(int _nrroti, string marca, float pret, int an) :anfabricatie(an){
		this->nrroti = _nrroti;
		this->marca = marca;
		this->pret = pret;
		}


	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Numar roti:" << this->nrroti << endl;
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
		if(noulTVA > 0)
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

 };


int Masina::TVA = 19;     // Initializare atribute statice


int main()
{
	Masina m1;
	m1.afisare();

	Masina m2(4, "Audi", 7000, 2020);
	m2.afisare();

	Masina::modificaTVA(21);

	Masina* pointer = new Masina(6, "Volvo", 20000, 2022);
	pointer->afisare();

	cout << "Pretul Total:" << pointer->calculeazaPretTotal();

	int nrMasini = 3;
	Masina* vector;
	vector = new Masina[nrMasini];

	for (int i = 0; i < nrMasini; i++)
	{
		vector[i].afisare();
	}

	cout << "Pretul Total Flota:" << Masina::calculeazaPretTotalVector(nrMasini, vector) << endl;


	delete[]vector;



	// -> - dereferentiere + accesare
	// [] - deplasare + dereferentiere
}