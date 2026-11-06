#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Laptop{
private:
    char* marca;
    float pret;
    int memorieRAM;
    bool esteGaming;
    int nrPrograme;
    string* programe;
    const int id;
    static int contor;
public: 
    //constructor cu parametri
    Laptop():id(contor++){
        this->marca = new char[strlen("Lenovo")+1];
        strcpy(this->marca, "Lenovo");
        this->pret = 3500;
        this->memorieRAM = 16;
        this->esteGaming = false;
        this->nrPrograme = 3;

        this->programe = new string[nrPrograme];
        this->programe[0] = "Chrome";
        this->programe[1] = "Word";
        this->programe[2] = "Excel";

        //this->id = id; nu stiu cum sa fac id generat automat
    }

    Laptop(const char* marca, float pret, int memorieRAM):id(contor++){
        this->marca = new char[strlen(marca)+1];
        strcpy (this->marca, marca);
        this->pret = pret;
        this->memorieRAM = memorieRAM;

        this->esteGaming = false;
        this->nrPrograme = 3;

        this->programe = new string[nrPrograme];
        this->programe[0] = "Chrome";
        this->programe[1] = "Word";
        this->programe[2] = "Excel";

    }

    Laptop(const Laptop& l):id(contor++){
        this->marca = new char[strlen(l.marca)+1];
        strcpy(this->marca, l.marca);
        this->pret = l.pret;
        this->memorieRAM = l.memorieRAM;
        this->esteGaming = l.esteGaming;
        this->nrPrograme = l.nrPrograme;
        
        this->programe = new string[this->nrPrograme];
        for (int i=0; i<l.nrPrograme; i++){
            this->programe[i] = l.programe[i];
        }
        //nu stiu cum sa faca sa primeasca un id nou
    }
    ~Laptop();

    float getPret(){
        return this->pret;
    }
    int getMemorieRAM(){
        return this->memorieRAM;
    }
    int getNrPrograme(){
        return this->nrPrograme;
    }
    static int getContor(){
        return contor;
    }

    void afisare(){
        cout << "Marca: " << marca << endl;
        cout << "Pret: " << pret << endl;
        cout << "Memorie RAM: " << memorieRAM << endl;
        cout << "Este de gaming?: " << (esteGaming ? "DA" : "NU") << endl;
        cout << "Numar programe: " << nrPrograme << endl;
        cout << "Programe: ";
        for (int i=0; i<nrPrograme; i++){
            cout << programe[i] << "; ";
        }
        cout << "Contor: " << contor << endl;
    }

    float pretPerGB(){
        float pret;
        if (this->memorieRAM != 0){
            return pret = this->pret / this->memorieRAM;
        }
        else{
            return 0;
        }
    }
    void modificaMarca(const char* marcaNoua){
        delete[] this->marca;
        this->marca = new char[strlen(marcaNoua)+1];
        strcpy(this->marca, marcaNoua);
    }
};

float calculeazaValoareTotala(Laptop* lp, int nrLaptopuri){
    float suma=0;
    for (int i=0; i<nrLaptopuri; i++){
        suma += lp[i].getPret();
    }
    return suma;
}

float calculeazaMemoriaRAM(Laptop* l, int nrLaptopuri){
    float medie;
    int suma = 0;
    if (nrLaptopuri > 0){
        for (int i=0; i<nrLaptopuri; i++){
            suma += l[i].getMemorieRAM();
        }
        medie = (float)suma/nrLaptopuri;
        return medie;
    }
    
    return 0;
    
    
}
float calculeazaPretPerProgram(Laptop l){
    float ppp;
    if (l.getNrPrograme() > 0){
        ppp = l.getPret() / l.getNrPrograme(); //nu stiu de ce dar nu merge l[i].getPret()
        return ppp;
    }
    
    else{
        return 0;
    }
}

int Laptop::contor = 200; //si aici m am ajutat
Laptop::~Laptop(){ //aici m am ajutat
    delete[] marca;
    delete[] programe;
}

int main(){
    Laptop l1;
    Laptop l2("ASUS", 5200, 32);
    Laptop l3 = l2;

    l1.afisare();
    cout << endl;
    l2.afisare();
    cout << endl;
    l3.afisare();
    cout << endl;

    l1.modificaMarca("HP");
    Laptop* laptopuri = new Laptop[4];
    //am probleme aici la alocarea dinamica a vectorului de laptopuri
    cout << "Valoare totala laptopuri: " << calculeazaValoareTotala(laptopuri, 4) << endl;
    cout << "Media memoriei RAM este: " << calculeazaMemoriaRAM(laptopuri, 4) << endl;
    cout << "Pret per program: " << calculeazaPretPerProgram(l3) << endl;
    cout << "Contor: " << laptopuri->getContor();

    delete[] laptopuri;
    return 0;




}