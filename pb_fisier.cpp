#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Fisier{
private:
    const int codFisier;
    string numeFisier;
    int nrAccesari;
    string* editori;
    float dimensiune; //pentru dimensiunea fisierului
    bool fisierText; //pentru a vedea daca fisierul este de tip text sau alt tip
public:
    Fisier():codFisier(100){
        this->numeFisier = "Default";
        this->nrAccesari = 3;

        this->editori = new string[this->nrAccesari];
        this->editori[0] = "Mihai";
        this->editori[1] = "Matei";
        this->editori[2] = "Adrian";
        this->dimensiune = 42.90;
        this->fisierText = true;
    }

    Fisier(string numeFisier, int nrAccesari, string* editori, float dimensiune, bool fisierText):codFisier(100){
        if (numeFisier.length() >= 5){
            this->numeFisier = numeFisier;
        }
        else{
            this->numeFisier = "Default";
        }
        if (nrAccesari > 0 && editori != nullptr){
            this->nrAccesari = nrAccesari;
            this->editori = new string[nrAccesari];
            for (int i=0; i<this->nrAccesari; i++){
                this->editori[i] = editori[i];
            }
        }
        else{
            this->nrAccesari = 0;
            this->editori = nullptr;
        }
        if (dimensiune >= 0){
            this->dimensiune = dimensiune;
        }
        else{
            this->dimensiune = 0;
        }
        this->fisierText = fisierText;
    }

    ~Fisier(){
        delete[] editori;
    }

    Fisier(const Fisier& f):codFisier(f.codFisier){
        this->numeFisier = f.numeFisier;
        this->nrAccesari = f.nrAccesari;

        if (f.nrAccesari > 0 && f.editori != nullptr){
            this->editori = new string[f.nrAccesari];
            for (int i=0; i<f.nrAccesari; i++){
                this->editori[i] = f.editori[i];
            }
        }
        else{
            this->editori = nullptr;
        }
        this->dimensiune = f.dimensiune;
        this->fisierText = f.fisierText;
    }
    void setDimensiunea(float dimensiunea){
        this->dimensiune = dimensiunea;
    }
    float getDimensiunea(){
        return this-> dimensiune;
    }
    void setFisierText(bool fisierText){
        this->fisierText = fisierText;
    }
    bool getFisierText(){
        return this->fisierText;
    }

    Fisier& operator=(const Fisier& f){
        if (this != &f){
            this->numeFisier = f.numeFisier;
            this->nrAccesari = f.nrAccesari;

            delete[] this->editori;
            if (f.nrAccesari > 0 && f.editori != nullptr){
                this->editori = new string[f.nrAccesari];
                for(int i=0; i<f.nrAccesari; i++){
                    this->editori[i] = f.editori[i];
                }
            }
            else{
                this->editori = nullptr;
            }
            this->dimensiune = f.dimensiune;
            this->fisierText = f.fisierText;

        }

        return *this;
    }
    friend ostream& operator<<(ostream& out, const Fisier& f){
        out << f.codFisier << endl;
        out << f.numeFisier << endl;
        out << f.nrAccesari << endl;

        for (int i=0; i<f.nrAccesari; i++){
            out << f.editori[i] << endl;
        }
        out << f.dimensiune << endl;
        out << f.fisierText << endl;
        return out;
    }
    int determinareNumarAccesari(string editor){
        int nr=0;
        for (int i=0; i<nrAccesari; i++){
            if (editori[i] == editor){
                nr++;
            }
        }
        return nr;
    }

};

int main(){
    Fisier f1; //apelez constructor fara parametri
    string editori[] = {"Ana", "Maria", "Andrei"};
    Fisier f2("Document", 3, editori, 25.5, true); //apelez constructor cu parametri
    Fisier f3(f2); //apelez constructor de copiere
    f1.setDimensiunea(50.5); //setez dimensiune fisier 1
    f1.setFisierText(false); //setez false la bool

    cout << "Dimensiunea celui de al doilea fisier este: " << f2.getDimensiunea() << endl;
    cout << "Primul fisier este text? " << (f1.getFisierText() ? "DA" : "NU") << endl;
    f1=f2; //pentru operatorul =

    cout << f1;
    cout << "Mihai a accesat fisierul de " << f1.determinareNumarAccesari("Mihai") << " ori" << endl;




}
