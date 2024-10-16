#include<iostream>

using namespace std;

struct Tara {
	char* denumirea;
	int nrlocuitori;
	string capitala;
	bool areIesireLaMare;
};


void AfisarePointeriLaTara(Tara* pt) {
	cout << "Nume:" << pt->denumirea << endl;
	cout << "Capitala:" << pt->capitala << endl;
	cout << "Numarul de locuitori:" << pt->nrlocuitori << endl;
	cout << "Are Iesire La Mare:" << (pt->areIesireLaMare ? "DA" : "NU");
	cout << "\n";



	if (pt->areIesireLaMare)
	{
		cout << "DA" << endl;
	}

	else
	{
		cout << "NU" << endl;
	}

}


Tara* citirePointerLaTara()
{
	Tara* p = new Tara();  // Alocare in Heap
	cout << "Capitala:";
	cin >> p->capitala;

	cout << "Denumirea:";

	char buffer[100];
	cin >> buffer;
	p->denumirea = new char[strlen(buffer) + 1];   // Alocare in Heap
	strcpy_s(p->denumirea, strlen(buffer) + 1, buffer);

	cout << "Numarul de locuitori:";
	cin >> p->nrlocuitori;

	cout << "Are Iesire La Mare ? (0-Nu;1-Da)";
	cout << "\n";
	cin >> p->areIesireLaMare;

	return p;
}



int main()
{
	Tara tara;
	tara.areIesireLaMare = false;

	Tara* pTara;
	pTara = new Tara();

	pTara->areIesireLaMare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumirea = new char[strlen("Romania") + 1];
	strcpy_s(pTara->denumirea, strlen("Romania") + 1, "Romania");
	pTara->nrlocuitori = 200;


	AfisarePointeriLaTara(pTara);
	delete[]pTara->denumirea;

	delete pTara;

	Tara* p2Tara = citirePointerLaTara();    // Citirea Pointeri La Tara
	AfisarePointeriLaTara(p2Tara);			// Afisarea Pointeri La Tara



	Tara* vector;
	vector = new Tara[2];        // Alocare dinamica in Heap
	delete[]vector;

	int nrPointeri = 2;
	//Declarare vector de pointeri

	//Vector de pointeri

	Tara** pointeri;
	pointeri = new Tara * [nrPointeri];

	for (int i = 0; i < nrPointeri; i++)
	{
		pointeri[i] = citirePointerLaTara();
	}

	//  Procesare
	for (int i = 0; i < nrPointeri; i++)
	{
		AfisarePointeriLaTara(pointeri[i]);
	}

	for (int i = 0; i < nrPointeri; i++)
	{

		delete[]pointeri[i]->denumirea;
		delete pointeri[i];

	}


	delete[]pointeri;


}