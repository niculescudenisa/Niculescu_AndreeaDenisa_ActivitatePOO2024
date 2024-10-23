#include <iostream>
#include <string>

using namespace std;


class Laptop {
public:
    string brand;
    string model;
    float pret;
    static int garantie;
    const int anFabricatie;

    // Constructor fara parametri
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

    // Constructor cu toti parametrii
    Laptop(string brand, float pret, string model, int an) : anFabricatie(an) {
        this->brand = brand;
        this->pret = pret;
        this->model = model;
    }

    // Func?ie statica pentru modificarea garantiei
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

int Laptop::garantie = 2; 


class Telefon {
public:
    string brand;
    string model;
    float pret;
    static int garantie;
    const int anFabricatie;

    // Constructor fara parametri
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

    // Constructor cu toti parametrii
    Telefon(string brand, float pret, string model, int an) : anFabricatie(an) {
        this->brand = brand;
        this->pret = pret;
        this->model = model;
    }

    
    static void modificaGarantie(int nouaGarantie) {
        if (nouaGarantie > 0) {
            garantie = nouaGarantie;
        }
    }

    void afisare() {
        cout << "Brandul: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "Pretul : " << this->pret << endl;
        cout << "Anul de Fabricatie: " << this->anFabricatie << endl;
        cout << "Garantie: " << this->garantie << endl;
    }
};

int Telefon::garantie = 1; 

// Clasa Televizor
class Televizor {
public:
    string brand;
    string model;
    float pret;
    static int garantie;
    const int anFabricatie;

    // Constructor fara parametri
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

    // Constructor cu toti parametrii
    Televizor(string brand, float pret, string model, int an) : anFabricatie(an) {
        this->brand = brand;
        this->pret = pret;
        this->model = model;
    }

    
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

int Televizor::garantie = 3;



int main() {
    
    Laptop l1;
    l1.afisare();

    Laptop l2("HP", 4200.0f);
    l2.afisare();

    Laptop l3("Apple", 8000.0f, "MacBook Pro", 2021);
    l3.afisare();


    Telefon t1;
    t1.afisare();

    Telefon t2("Apple", 5000.0f);
    t2.afisare();

    Telefon t3("Google", 3000.0f, "Pixel 6", 2021);
    t3.afisare();



    Televizor tv1;
    tv1.afisare();

    Televizor tv2("Sony", 5000.0f);
    tv2.afisare();

    Televizor tv3("Samsung", 6000.0f, "QLED85", 2023);
    tv3.afisare();




    Laptop::modificaGarantie(3);
    Telefon::modificaGarantie(2);
    Televizor::modificaGarantie(4);

 


    cout << "\nDupa modificarea garantiilor:\n";
    l1.afisare();
    t1.afisare();
    tv1.afisare();

    return 0;
}
