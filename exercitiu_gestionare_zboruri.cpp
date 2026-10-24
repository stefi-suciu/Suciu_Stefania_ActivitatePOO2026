/*
Sistem de gestionare a zborurilor
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Zbor{
    char* destinatie;
    string companie;
    float pretBilet;
    int locuriTotale;
    int locuriOcupate;
    bool anulat;
};

void citesteZbor (Zbor& z){
    cout << "Introduceti destinatia: ";
    char buffer[100];
    cin.width(100);

    cin >> buffer;
    z.destinatie = new char[strlen(buffer)+1];
    strcpy (z.destinatie, buffer);
    
    cout << "Introduceti compania: ";
    cin >> z.companie;
    cout << "Introduceti pretul biletului: ";
    cin >> z.pretBilet;
    cout << "Introduceti numarul de locuri totale: ";
    cin >> z.locuriTotale;
    cout << "Introduceti numarul de locuri ocupate: ";
    cin >> z.locuriOcupate;
    cout << "Este anulat zborul? (1/0): ";
    cin >> z.anulat;
}

void modificaPret(Zbor* z, float pretNou){
    z->pretBilet = pretNou;
    
}

bool rezervaLocuri(Zbor* z, int nrLocuri){
    
    int locuriLibere = z->locuriTotale - z->locuriOcupate;
    if (z->anulat == false && nrLocuri > 0 && locuriLibere >= nrLocuri){
        z->locuriOcupate += nrLocuri;
        return true;
    }
    return false;

}
void afisareZboruri(const Zbor& z){
    cout << "Destinatie: " << z.destinatie << endl;
    cout << "Companie: " << z.companie << endl;
    cout << "Pret bilet: " << z.pretBilet << endl;
    cout << "Locuri totale: " << z.locuriTotale << endl;
    cout << "Locuri ocupate: " << z.locuriOcupate << endl;
    if (z.anulat){
        cout << "Zborul este anulat. " << endl;
    }
    else{
        cout << "Zborul nu este anulat." << endl;
    }
    int locuriLibere;
    locuriLibere = z.locuriTotale - z.locuriOcupate;
    cout << "Locuri libere: " << locuriLibere << endl;
}

float calculeazaPretMediu(const Zbor* v, int n){
    int contor = 0;
    float suma = 0;
    float pretMediu;
    for (int i=0; i<n; i++){
        if (v[i].anulat == false){
            contor++;
            suma += v[i].pretBilet;
        }
    }
    if (contor > 0){
        pretMediu = suma/contor;
        return pretMediu;
    }
    else{
        return 0;
    }
}

int numaraZboruriAnulate(const Zbor* v, int n){
    int contor = 0;
    for (int i=0; i<n; i++){
        if (v[i].anulat){
            contor++;
        }
    }
    return contor;
}



int main(){
    int n; //numar de zboruri
    cout << "Introduceti numarul de zboruri: ";
    cin >> n;
    if (n <= 0){
        return 1;
    }
    Zbor* v = new Zbor[n];

    for (int i=0; i<n; i++){
        citesteZbor(v[i]);
    }
    

    float pretNou;
    cout << "Introduceti noul pret al primului zbor: ";
    cin >> pretNou;
    modificaPret(&v[0], pretNou);
    if (n>=2){
        int nrLocuri;
        cout << "Cate locuri ati dori sa rezervati pentru al doilea zbor?: ";
        cin >> nrLocuri;

        if (rezervaLocuri(&v[1], nrLocuri)){
            cout << "Rezervare reusita! " << endl;
        }
        else{
            cout << "Rezervarea nu a putut fi efectuata. " << endl;
        }
    }
    cout << endl << endl;
    for (int i=0; i<n; i++){
        afisareZboruri(v[i]);
        cout << endl;
    }

    cout << "Pretul mediu al biletelor este: " << calculeazaPretMediu (v, n) << endl;
    cout << "Numarul zborurilor anulate este: " << numaraZboruriAnulate (v, n) << endl;


    for (int i=0; i<n; i++){
        delete[] v[i].destinatie;
    }
    delete []v;
    return 0;

    

}