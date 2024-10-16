#include<iostream>

using namespace std;
class Marker {
public:
		string culoare;
		float greutate;
		int lungime;

		void afisare()
		{
			this->culoare;
			this->lungime;
			this->greutate;
}


		// CONSTRUCTOR IN CLASA


		Marker() {
			this->culoare = "Albstru";
			this->greutate = 45;
			this->lungime = 12;
		}


};



void afisare(Marker m)
{
	cout << "Culoare:" << m.culoare << endl;
	cout << "Lungimea:" << m.lungime << endl;
	cout << "Greutatea:" << m.greutate << endl;

}

int main()
{
	Marker marker1;   // definirea unui obiect
	marker1.lungime = 12;
	marker1.greutate = 45;
	marker1.culoare = "Albastru";

	afisare(marker1);

	marker1.afisare();    // Apelul facut din calsa

	
	
}