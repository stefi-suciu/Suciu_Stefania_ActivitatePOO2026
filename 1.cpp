#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Carte{
private:
    char* titlu;
    float pret;
    int nrPagini;
    bool disponibila;
    int nrAutori;
    string* autori;
    const int id;
    static int contor;
public:
    Carte():id(contor++){
        this->titlu = new char[strlen("Necunoscut")+1];
        strcpy(this->titlu, "Necunoscut");
        this->pret = 50;
        this->nrPagini = 200;
        this->disponibila = true;
        this->nrAutori = 2;
        this->autori = new string[this->nrAutori];
        this->autori[0] = "Ion Popescu";
        this->autori[1] = "Maria Ionescu";
    }
    Carte (const char* titlu, float pret):id(contor++){
        this->titlu = new char[strlen(titlu)+1];
        strcpy(this->titlu, titlu);
        this->pret = pret;
        this->nrPagini = 200;
        this->disponibila = true;
        this->nrAutori = 2;
        this->autori = new string[this->nrAutori];
        this->autori[0] = "Ion Popescu";
        this->autori[1] = "Maria Ionescu";

    }
    Carte (const Carte& c):id(contor++){
        this->titlu = new char [strlen(c.titlu)+1];
        strcpy (this->titlu, c.titlu);
        this->pret = c.pret;
        this->nrPagini = c.nrPagini;
        this->disponibila = c.disponibila;
        this->nrAutori = c.nrAutori;

        this->autori = new string[c.nrAutori];
        for (int i=0; i<c.nrAutori; i++){
            this->autori[i] = c.autori[i];
        }
    }
    ~Carte();
    float getPret() const{
        return this->pret;
    }
    int getNrPagini(){
        return this->nrPagini;
    }
    int getNrAutori(){
        return this->nrAutori;
    }
    static int getContor(){
        return contor;
    }

    void afisare(){
        cout << "Titlu: " << this->titlu << endl;
        cout << "Pret: " << this->pret << endl;
        cout << "Numar pagini: " << this->nrPagini << endl;
        cout << "Disponibila? " << (this->disponibila ? "DA" : "NU") << endl;
        cout << "Numar autori: " << this->nrAutori << endl;
        cout << "Autori: " << endl;
        for (int i=0; i<this->nrAutori; i++){
            cout << this->autori[i] << endl;
        }
        cout << "ID: " << id << endl;

    }
    float costMediuPagina(){
        if (this->nrPagini != 0){
            return this->pret / this->nrPagini;
        }
        else{
            return 0;
        }
    }

    void modificaTitlu(const char* titluNou){
        delete[] this->titlu;
        this->titlu = new char [strlen(titluNou)+1];
        strcpy (this->titlu, titluNou);
    }
};

float calculeazaPretTotal(const Carte* carti, int nrCarti){
    float suma = 0;
    for (int i=0; i<nrCarti; i++){
        suma += carti[i].getPret();
    }
    return suma;
}

float calculeazaPaginiPerAutor(Carte c){
    if (c.getNrAutori() > 0){
        return (float)c.getNrPagini() / c.getNrAutori();
    }
    else{
        return 0;
    }
}

int Carte::contor=100;
Carte::~Carte(){
        delete [] this->titlu;
        delete[] this->autori;
    }


int main(){
    Carte c1;
    Carte c2("Misery", 60.99);
    Carte c3 = c2;
    c1.afisare();
    cout << endl;
    c2.afisare();
    cout << endl;
    c3.afisare();
    cout << endl;
    c1.modificaTitlu("Dune");
    Carte* carti = new Carte[3];
    
    cout << "Pret total: " << calculeazaPretTotal(carti, 3) << endl;
    cout << "Pagini per autor: " << calculeazaPaginiPerAutor(c3) << endl;
    cout << "Contor: " << c1.getContor();

    delete[] carti;

    return 0;
}