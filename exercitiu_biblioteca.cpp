/*
Gestionarea unei biblioteci.
Biblioteca are mai multe carti, iar utilizatorul poate introduce informatii despre ele, modifica pretul si vedea statstici.
Campuri: titlu, autor, pret, nr. pagini, disponibila
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Carte{
    char* titlu;
    string autor;
    float pret;
    int nrPagini;
    bool disponibila;
};

void citesteCarte(Carte& c){
    char buffer[100];
    cout << "Titlu: ";
    cin >> buffer;

    c.titlu = new char[strlen(buffer)+1];
    strcpy (c.titlu, buffer);

    cout << "Autor: ";
    cin >> c.autor;
    cout << "Pret: ";
    cin >> c.pret;
    cout << "Numar pagini: ";
    cin >> c.nrPagini;
    cout << "Disponibila? (1/0): ";
    cin >> c.disponibila;
}

void modificaPret(Carte* c, float pretNou){
    c->pret = pretNou;
}

void afisareCarte(const Carte& c){
    cout << "Titlu: " << c.titlu << endl;
    cout << "Autor: " << c.autor << endl;
    cout << "Pret: " << c.pret << endl;
    cout << "Numar pagini: " << c.nrPagini << endl;
    if (c.disponibila){
        cout << "Disponibila." << endl;
    }
    else{
        cout << "Indisponibila." << endl;
    }
}

float calculeazaPretulMediu(const Carte* v, int n){
    float suma = 0;
    for (int i=0; i<n; i++){
        suma += v[i].pret;
    }
    float pretMediu = suma/n;
    return pretMediu;
    
}

int numarDisponibile(const Carte* v, int n){
    int contor = 0;
    for (int i=0; i<n; i++){
        if (v[i].disponibila){
            contor += 1;
        }
    }
    return contor;
}

int main(){

    int n; //numar carti
    cout << "Introduceti numarul de carti: ";
    cin >> n;
    if (n <= 0){
        return 1;
    }
    Carte* v = new Carte[n];   
    for (int i=0; i<n; i++){
        citesteCarte(v[i]);
    }
    modificaPret(&v[0], 100);
    cout << endl;

    for (int i=0; i<n; i++){
        afisareCarte(v[i]);
        cout << endl;
    }

    //calculeazaPretulMediu (v,n);

    cout << "Pretul mediu este: " << calculeazaPretulMediu (v,n) << endl; 
    cout << "Numarul cartilor disponibile este: " << numarDisponibile (v, n) << endl;

    for (int i=0; i<n; i++){
        delete [] v[i].titlu;
    }
    delete [] v;
    return 0;
}