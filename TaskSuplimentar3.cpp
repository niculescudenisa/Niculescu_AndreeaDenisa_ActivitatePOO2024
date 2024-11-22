#include <iostream>
#include <string>

using namespace std;


class Laptop {
    private:
    string brand;
    string model;
    int nrStoc;
    float* preturi;;
    static int garantie;
    const int anFabricatie;
   

public:
    // Constructor fara parametri
    Laptop() : anFabricatie(2024) {
        this->brand = "Dell";
        this->model = "Inspiron";
        this->nrStoc = 0;
        this->preturi = NULL;
    }

    // Constructor cu doi parametri
    Laptop(string brand, int nrStoc) : anFabricatie(2024) {
        this->brand = brand;
        this->nrStoc = nrStoc;
        this->model = "Unknown";
        this->preturi = NULL;
    }

    // Constructor cu toti parametrii
    Laptop(string brand, string model, int an, int nrStoc, float* preturi) : anFabricatie(an) {
        this->brand = brand;
        this->model = model;
        this->nrStoc = nrStoc;
        this->preturi = new float[nrStoc];
        for (int i = 0; i < nrStoc; i++) {
            this->preturi[i] = preturi[i];
        }
    }

    // Functie statica pentru modificarea garantiei
    static void modificaGarantie(int nouaGarantie) {
        if (nouaGarantie > 0) {
            garantie = nouaGarantie;
        }
    }

    void afisare() {
        cout << "Brand: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "An Fabricatie: " << this->anFabricatie << endl;
        cout << "Garantie: " << this->garantie << endl;
        cout << "Nr produse pe stoc: " << this->nrStoc << endl;
        if (nrStoc > 0 && preturi != NULL) {
            for (int i = 0; i < nrStoc; i++) {
                cout << this->preturi[i] << ",";
            }
        }
        else
        {
            this->preturi = NULL;
        }
        
        cout << endl << endl;

    }

    //Getteri si setteri
    string getModel() {
        return this->model;
   }

    string getBrand() {
        return this->brand;
    }

    void setModel(string model) {
        if (model.length() > 1) {
            this->model = model;
        }
    }

    void setBrand(string brand) {
        if (brand.length() > 1) {
            this->brand = brand;
        }
    }

    int getNrStoc() {
        return this->nrStoc;
    }

    void setNrStoc(int nrStoc, float* preturi) {
        if (nrStoc > 0) {
            this->nrStoc = nrStoc;

            if (this->preturi != NULL) {
                delete[]this->preturi;
            }
            this->preturi = new float[nrStoc];
            for (int i = 0; i < nrStoc; i++) {
                this->preturi[i] = preturi[i];
            }
        }
    }

    float* getPreturi() {
        return this->preturi;
    }

    // Functii

    float calculeazaPretMediu(int nrStoc, float* preturi) {
        if (nrStoc > 0 && preturi != NULL) {
            float suma = 0;
            for (int i = 0; i< nrStoc; i++) {
                suma += preturi[i];
            }
            return suma / nrStoc;
        }
    }


    //Destructor
    ~Laptop() {
        if (this->preturi != NULL) {
            delete[]this->preturi;
        }
    }
};

int Laptop::garantie = 2;


class Telefon {
private:
    string brand;
    string model;
    int nrProduse;
    string* distribuitori;
    static int garantie;
    const int anFabricatie;

public:

    // Constructor fara parametri
    Telefon() : anFabricatie(2023) {
        this->brand = "Samsung";
        this->model = "Galaxy S21";
        this->nrProduse = 0;
        this->distribuitori = NULL;
    }

    // Constructor cu doi parametri
    Telefon(string brand, int nrProduse) : anFabricatie(2023) {
        this->brand = brand;
        this->model = "Unknown";
        this->nrProduse = nrProduse;
        this->distribuitori = NULL;
    }

    // Constructor cu toti parametrii
    Telefon(string brand, string model, int an, int nrProduse, string* distribuitori) : anFabricatie(an) {
        this->brand = brand;
        this->model = model;
        this->nrProduse = nrProduse;
        this->distribuitori = new string[nrProduse];
        for (int i = 0; i < nrProduse; i++) {
            this->distribuitori[i] = distribuitori[i];
        }
    }


    static void modificaGarantie(int nouaGarantie) {
        if (nouaGarantie > 0) {
            garantie = nouaGarantie;
        }
    }

    void afisare() {
        cout << "Brandul: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "Anul de Fabricatie: " << this->anFabricatie << endl;
        cout << "Garantie: " << this->garantie << endl;
        cout << "Nr produse:" << this->nrProduse << ":" << endl;
        if (nrProduse > 0 && distribuitori != NULL) {
            for (int i = 0; i < nrProduse; i++) {
                cout << this->distribuitori[i] << ",";
            }
        }
        else
        {
            this->distribuitori = NULL;
        }
        cout << endl << endl;
    }

    // Getteri si setteri

    string getModel() {
        return this->model;
    }

    string getBrand() {
        return this->brand;
    }

    void setModel(string model) {
        if (model.length() > 1) {
            this->model = model;
        }
    }

    void setBrand(string brand) {
        if (brand.length() > 1) {
            this->brand = brand;
        }
    }

    int getNrProduse() {
        return this->nrProduse;
    }

    void setNrProduse(int nrProduse, string* distribuitori) {
        if (nrProduse > 0) {
            this->nrProduse = nrProduse;

            if (this->distribuitori != NULL) {
                delete[]this->distribuitori;
            }
            this->distribuitori = new string[nrProduse];
            for (int i = 0; i < nrProduse; i++) {
                this->distribuitori[i] = distribuitori[i];
            }
        }
    }

    string* getDistribuitori() {
        return this->distribuitori;
     }



  

    ~Telefon() {
        if (this->distribuitori != NULL) {
            delete[]this->distribuitori;
        }
    }
};

int Telefon::garantie = 1;

// Clasa Televizor

class Televizor {
    private:
    string brand;
    string model;
    int nrStoc;
    float* preturi;
    static int garantie;
    const int anFabricatie;


public:

    // Constructor fara parametri
    Televizor() : anFabricatie(2022) {
        this->brand = "LG";
        this->model = "OLED55";
        this->nrStoc = 0;
        this->preturi = NULL;
    }

    // Constructor cu doi parametri
    Televizor(string brand, int nrStoc) : anFabricatie(2022) {
        this->brand = brand;
        this->model = "Unknown";
        this->nrStoc = nrStoc;
        this->preturi = NULL;
    }

    // Constructor cu toti parametrii
    Televizor(string brand, string model, int an, int nrStoc, float* preturi) : anFabricatie(an) {
        this->brand = brand;
        this->model = model;
        this->nrStoc = nrStoc;

        this->preturi = new float[nrStoc];
        for (int i = 0; i < nrStoc; i++) {
            this->preturi[i] = preturi[i];
        }
    }


    static void modificaGarantie(int nouaGarantie) {
        if (nouaGarantie > 0) {
            garantie = nouaGarantie;
        }
    }

    void afisare() {
        cout << "Brandul televizorului: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "An Fabricatie: " << this->anFabricatie << endl;
        cout << "Garantie: " << this->garantie << endl;
        cout << "Nr produse pe stoc:" << this->nrStoc << ":" << endl;
        
        if (nrStoc > 0 && preturi != NULL) {
            for (int i = 0; i < nrStoc; i++) {
                cout << this->preturi[i] << ",";
            }
        }
        else
        {
            this->preturi = NULL;
        }
        cout << endl << endl;
    }

    //Getteri si setteri
    string getModel() {
        return this->model;
    }

    string getBrand() {
        return this->brand;
    }

    void setModel(string model) {
        if (model.length() > 1) {
            this->model = model;
        }
    }

    void setBrand(string brand) {
        if (brand.length() > 1) {
            this->brand = brand;
        }
    }

    int getNrStoc() {
        return this->nrStoc;
    }

    void setNrStoc(int nrStoc, float* preturi) {
        if (nrStoc > 0) {
            this->nrStoc = nrStoc;

            if (this->preturi != NULL) {
                delete[]this->preturi;
            }
            this->preturi = new float[nrStoc];
            for (int i = 0; i < nrStoc; i++) {
                this->preturi[i] = preturi[i];
            }
        }
    }

    float* getPreturi() {
        return this->preturi;
    }

    // Functia care calculeaza pretul mediu 

    float CalculeazaPretMediu(int nrStoc, float* preturi) {
        if (nrStoc > 0 && preturi != NULL) {
            float suma = 0;
            for (int i = 0; i < nrStoc; i++)
            {
                suma += preturi[i];
            }
            return suma / nrStoc;
        }
    }

    // Destructor

    ~Televizor() {
        if (this->preturi != NULL) {
            delete[]this->preturi;
        }
    }
};

int Televizor::garantie = 3;



int main() {

    Laptop l1;
    l1.afisare();

    Laptop l2("HP","S23",2023,4,new float[4]{3000,3300,3600,3900});
    l2.afisare();

    Laptop l3("Apple",5);
    l3.afisare();


    Telefon t1;
    t1.afisare();

    Telefon t2("Apple",5);
    t2.afisare();

    Telefon t3("Samsung","S22",2021,3,new string[3]{"Altex","Emag","Flanco"});
    t3.afisare();



    Televizor tv1;
    tv1.afisare();

    Televizor tv2("Sony", 4);
    tv2.afisare();

    Televizor tv3("Samsung", "Smart6", 2021, 5, new float[5]{ 2500,3000,3500,4000,4500 });
    tv3.afisare();

    cout << "Brandul,modelul si nr produselor de pe stoc pt laptopul l1:" << endl;
    cout << l2.getBrand() << "," << l2.getModel() << "," << l2.getNrStoc() << endl;
    for (int i = 0; i < l2.getNrStoc(); i++) {
        cout << l2.getPreturi()[i] << ",";
    }
    cout << endl << endl;

    cout << "Brandul, modelul si nr produselor pt telefonul t3:" << endl;
    cout << t3.getBrand() << "," << t3.getModel() << "," << t3.getNrProduse() << endl;
    for (int i = 0; i < t3.getNrProduse(); i++) {
        cout << t3.getDistribuitori()[i] << ",";
    }
    cout << endl << endl;

    cout << "Brandul,modelul si nr produselor de pe stoc pt televizorul t3:" << endl;
    cout << tv3.getBrand() << "," << tv3.getModel() << "," << tv3.getNrStoc() << endl;
    for (int i = 0; i < tv3.getNrStoc(); i++) {
        cout << tv3.getPreturi()[i] << ",";
    }
    cout << endl << endl;
   


    cout << "Pretul mediu pt laptopul l2 este:" << l2.calculeazaPretMediu(4, new float[4] {3000, 3300, 3600, 3900}) << endl << endl;
    cout << "Pretul mediu pentru televizorul tv3 este:" << tv3.CalculeazaPretMediu(5, new float[5] { 2500, 3000, 3500, 4000, 4500}) << endl << endl;

    Laptop::modificaGarantie(3);
    Telefon::modificaGarantie(2);
    Televizor::modificaGarantie(4);




    cout << "\nDupa modificarea garantiilor:\n";
    l1.afisare();
    t1.afisare();
    tv1.afisare();

  
}