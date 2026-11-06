#include <iostream>
#include <string>
using namespace std;

class Biblioteca{
private:
    string numeCarte;
    int exemplareDisponibile = 0;
    int exemplareImprumutate = 0;
public:
    void setNume(string nume){
        numeCarte = nume;
    }
    void adaugareCarti(int numarExemplare){
        if (numarExemplare > 0){
            exemplareDisponibile += numarExemplare;
        }
    }
    void imprumutareExemplar(int numar){
        if (numar > 0 && numar <= exemplareDisponibile){
            exemplareImprumutate += numar;
            exemplareDisponibile -= numar;
        }
    }
    void returnareExemplar(int numar){
        if (numar > 0 && numar <= exemplareImprumutate){
            exemplareDisponibile += numar;
            exemplareImprumutate -= numar;
        }
    }
    void afisareCarte(){
        cout << "Nume: " << numeCarte << endl;
        cout << "Exemplare disponibile: " << exemplareDisponibile << endl;
        cout << "Exemplare imprumutate: " << exemplareImprumutate << endl;
    }
};

int main(){
    Biblioteca c1;
    c1.setNume("Ion");
    c1.adaugareCarti(5);
    c1.imprumutareExemplar(2);
    c1.returnareExemplar(1);
    c1.afisareCarte();

    return 0;
}