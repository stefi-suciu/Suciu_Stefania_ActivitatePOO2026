#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Utilaj{
private:
    static int nrObiecte;
    string denumire;
    int ore;
    char* serie;
    int nrMasuratori;
    long* masuratori;
public: 
    Utilaj(){
        nrObiecte++;
        this->denumire = "Tractor";
        this->ore = 4;
        this->serie = new char[strlen("ASX2009")+1];
        strcpy(this->serie, "ASX2009");

        this->nrMasuratori = 3;
        this->masuratori = new long[this->nrMasuratori];
        this->masuratori[0] = 12;
        this->masuratori[1] = 15;
        this->masuratori[2] = 67;
    }
    Utilaj(string denumire, int ore){
        nrObiecte++;
        this->denumire = denumire;
        this->ore = ore;

        this->serie = new char[strlen("Necunoscuta")+1];
        strcpy(this->serie, "Necunoscuta");
        this->nrMasuratori = 0;
        this->masuratori = nullptr;
    }
    Utilaj(string denumire, int ore, const char* serie, int nrMasuratori, long* masuratori){
        nrObiecte++;
        this->denumire = denumire;
        this->ore = ore;

        this->serie = new char[strlen(serie)+1];
        strcpy(this->serie, serie);
        this->nrMasuratori = nrMasuratori;
        this->masuratori = new long[this->nrMasuratori];
        for (int i=0; i<this->nrMasuratori; i++){
            this->masuratori[i] = masuratori[i];
        }

    }
    Utilaj(const Utilaj& u){
        nrObiecte++;
        this->denumire = u.denumire;
        this->ore = u.ore;

        this->serie = new char[strlen(u.serie)+1];
        strcpy (this->serie, u.serie);
        this->nrMasuratori = u.nrMasuratori;
        this->masuratori = new long[u.nrMasuratori];
        for (int i=0; i<this->nrMasuratori; i++){
            this->masuratori[i] = u.masuratori[i];
        }
    }
    Utilaj& operator=(const Utilaj& u){
        if (this != &u){
            this->denumire = u.denumire;
            this->ore = u.ore;

            delete[] this->serie;
            this->serie = new char[strlen(u.serie)+1];
            strcpy(this->serie, u.serie);
            this->nrMasuratori = u.nrMasuratori;

            delete[] this->masuratori;
            this->masuratori = new long[this->nrMasuratori];
            for (int i=0; i<this->nrMasuratori; i++){
                this->masuratori[i] = u.masuratori[i];
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Utilaj& u){
        out << u.denumire << endl;
        out << u.ore << endl;
        out << u.serie << endl;
        out << u.nrMasuratori << endl;
        for (int i=0; i<u.nrMasuratori; i++){
            out << u.masuratori[i] << "; " << endl;
        }
        return out;
    }
    ~Utilaj(){
        delete[] serie;
        delete[] masuratori;
    }
    int getOreFunctionare(){
        return this->ore;
    }
    void setDeumire(string denumire){
        this->denumire = denumire;
    }
    long masuratoareMinima(){
        if (this->nrMasuratori == 0){
            return 0;
        }
        long min = this->masuratori[0];
        for (int i=1; i<this->nrMasuratori; i++){
            if (this->masuratori[i] < min){
                min = this->masuratori[i];
            }
        }
        return min;
    }
};
int Utilaj::nrObiecte = 0;

int main(){
    Utilaj u;
    Utilaj u1;
    cout << u1;
    long masuratori[] = {50,20, 14};
    Utilaj u2("Buldozer", 4, "POI9088", 3, masuratori);
    cout << u2;
    Utilaj u3(u2);
    u3=u1;
    cout << "Orele de functionare ale primului utilaj sunt: " << u1.getOreFunctionare() << endl;
    u2.setDeumire("Camion");
    cout << "Masuratoarea minima pentru primul utilaj este: " << u1.masuratoareMinima() << endl;

    return 0;
}