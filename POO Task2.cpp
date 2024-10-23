#include <iostream>
#include <string>

using namespace std;

// Clasa Laptop
class Laptop {
public:
    string brand;
    string model;
    float pret;
    static int garantie;
    const int anFabricatie;

    // Constructor fără parametri
    Laptop() : anFabricatie(2024) {
        this->brand = "Dell";
        this->pret = 3500.0f;
        this->model = "Inspiron";
    }

    // Constructor cu doi parametri
    Laptop(string brand, float pret) : anFabricatie(2024) {
        this->brand = brand;
        this->pret = pret;
        this->model = "Unknown";
    }

    // Constructor cu toți parametrii
    Laptop(string brand, float pret, string model, int an) : anFabricatie(an) {
        this->brand = brand;
        this->pret = pret;
        this->model = model;
    }

    // Funcție statică pentru modificarea garanției
    static void modificaGarantie(int nouaGarantie) {
        if (nouaGarantie > 0) {
            garantie = nouaGarantie;
        }
    }

    void afisare() {
        cout << "Brand: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "Pretul: " << this->pret << endl;
        cout << "An Fabricatie: " << this->anFabricatie << endl;
        cout << "Garantie: " << this->garantie << endl;
        
    }
};

int Laptop::garantie = 2; // Inițializare atribut static

// Clasa Telefon
class Telefon {
public:
    string brand;
    string model;
    float pret;
    static int garantie;
    const int anFabricatie;

    // Constructor fără parametri
    Telefon() : anFabricatie(2023) {
        this->brand = "Samsung";
        this->pret = 2000.0f;
        this->model = "Galaxy S21";
    }

    // Constructor cu doi parametri
    Telefon(string brand, float pret) : anFabricatie(2023) {
        this->brand = brand;
        this->pret = pret;
        this->model = "Unknown";
    }

    // Constructor cu toți parametrii
    Telefon(string brand, float pret, string model, int an) : anFabricatie(an) {
        this->brand = brand;
        this->pret = pret;
        this->model = model;
    }

    // Funcție statică pentru modificarea garanției
    static void modificaGarantie(int nouaGarantie) {
        if (nouaGarantie > 0) {
            garantie = nouaGarantie;
        }
    }

    void afisare() {
        cout <<"Brandul: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout <<"Pretul : " << this->pret << endl;
        cout <<"Anul de Fabricatie: " << this->anFabricatie << endl;
        cout <<"Garantie: " << this->garantie << endl;
    }
};

int Telefon::garantie = 1; // Inițializare atribut static

// Clasa Televizor
class Televizor {
public:
    string brand;
    string model;
    float pret;
    static int garantie;
    const int anFabricatie;

    // Constructor fără parametri
    Televizor() : anFabricatie(2022) {
        this->brand = "LG";
        this->pret = 4000.0f;
        this->model = "OLED55";
    }

    // Constructor cu doi parametri
    Televizor(string brand, float pret) : anFabricatie(2022) {
        this->brand = brand;
        this->pret = pret;
        this->model = "Unknown";
    }

    // Constructor cu toți parametrii
    Televizor(string brand, float pret, string model, int an) : anFabricatie(an) {
        this->brand = brand;
        this->pret = pret;
        this->model = model;
    }

    // Funcție statică pentru modificarea garanției
    static void modificaGarantie(int nouaGarantie) {
        if (nouaGarantie > 0) {
            garantie = nouaGarantie;
        }
    }

    void afisare() {
        cout << "Brandul televizorului: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "Pret: " << this->pret << endl;
        cout << "An Fabricatie: " << this->anFabricatie << endl; 
        cout << "Garantie: " << this->garantie << endl; 
    }
};

int Televizor::garantie = 3; // Inițializare atribut static

// Funcția main
int main() {
    // Creare și afișare obiecte Laptop
    Laptop l1;
    l1.afisare();

    Laptop l2("HP", 4200.0f);
    l2.afisare();

    Laptop l3("Apple", 8000.0f, "MacBook Pro", 2021);
    l3.afisare();

    // Creare și afișare obiecte Telefon
    Telefon t1;
    t1.afisare();

    Telefon t2("Apple", 5000.0f);
    t2.afisare();

    Telefon t3("Google", 3000.0f, "Pixel 6", 2021);
    t3.afisare();

    // Creare și afișare obiecte Televizor
    Televizor tv1;
    tv1.afisare();

    Televizor tv2("Sony", 5000.0f);
    tv2.afisare();

    Televizor tv3("Samsung", 6000.0f, "QLED85", 2023);
    tv3.afisare();

    // Modificare garanții folosind funcțiile statice
    Laptop::modificaGarantie(3);
    Telefon::modificaGarantie(2);
    Televizor::modificaGarantie(4);

    // Afișare din nou după modificarea garanțiilor
    cout << "\nDupa modificarea garanțiilor:\n";
    l1.afisare();
    t1.afisare();
    tv1.afisare();

    return 0;
}
