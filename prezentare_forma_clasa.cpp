#include <iostream>
using namespace std;


class Stefi {
public:
    string Nume;
    string Ora;
    int Varsta;
    float apaConsumata;

    void introducere(){
        cout << "Nume: " << Nume << endl;
        cout << "Ora: " << Ora << endl;
        cout << "Varsta: " << Varsta << endl;
        cout << "Apa consumata (in l) pana la ora " << Ora << ": " << apaConsumata << endl;
    }

    Stefi (string nume, string ora, int varsta, float apa){
        Nume = nume;
        Ora = ora;
        Varsta = varsta;
        apaConsumata = apa;

    }
};

int main (){
    Stefi prezentarea_mea = Stefi ("Stefania", "09:01", 19, 0.4);
    prezentarea_mea.introducere();

}

