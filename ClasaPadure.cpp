#include<iostream>

using namespace std;

class Padure {
	private:
	string nume;
	int nrCopaci;
	const int id;
	int* varstaCopaci;
	static int gradDefrisare;

	public:

		// Constructor fara parametrii
		Padure():id(100) {
			this->nrCopaci = 0;
			this->nume = "Padure";
			this->varstaCopaci = NULL;

		}

		// Constructor cu 2 parametrii
		Padure(int idNou, string nume) :id(idNou) {
			this->nume = nume;
			this->nrCopaci = nrCopaci;
			this->varstaCopaci = varstaCopaci;
		}

		// Constructor cu 4 parametrii
		Padure(int id, string nume, int nrCopaci, int* varstaCopaci) :id(id) {
			this->nume = nume;
			this->nrCopaci = nrCopaci;
			if (nrCopaci != 0)
			{
				this->varstaCopaci = new int[nrCopaci];
				for (int i = 0; i < nrCopaci; i++)
				{
					this->varstaCopaci[i] = varstaCopaci[i];
				}
			}

			else varstaCopaci = NULL;
		}

		~Padure() {
			if (varstaCopaci != NULL)
			{
				delete[]this->varstaCopaci;
			}

		}


		void afisare() {
			cout << "Id-ul copacului:" << this->id << endl;
			cout << "Numele:" << this->nume << endl;
			cout << "Gradul de defrisare:" << this->gradDefrisare << endl;
			cout << "Numarul de copaci:" << this->nrCopaci << endl;
			cout << "Varsta copacului:" << this->varstaCopaci << endl;

			if (varstaCopaci != NULL)
			{
				for (int i = 0; i < nrCopaci; i++)
				{
					cout << varstaCopaci[i] << ",";
				}
			}
			else { cout << "-";}
		}
};


int Padure::gradDefrisare = 2;

int main() {
	int* varsta;
	varsta = new int[12];
	varsta[0] = 5;
	varsta[1] = 10;

	Padure p1;
	p1.afisare();

	Padure p2(5, "Baneasa");
	p2.afisare();

	Padure p3(101, "Padure2", 2, varsta);
	p3.afisare();
	
}