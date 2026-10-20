#include <iostream>
#include <string>
using namespace std;

struct telefon{
    string marca;
    float pret;
    int memorie;
    bool are5G;
};

void citireInformatii1(telefon &t){
    cout << "Informatii telefon: " << endl << "Marca: ";
    cin >> t.marca;
    cout << "Pret: ";
    cin >> t.pret;
    cout << "Memorie: ";
    cin >> t.memorie;
    cout << "Are 5G? (1/0): ";
    cin >> t.are5G;
}


void afisareInformatii1(telefon t){
    cout << t.marca << endl;
    cout << t.pret << endl;
    cout << t.memorie << endl;
    cout << t.are5G << endl;

}

void comparatieTelefoane(telefon t1, telefon t2){
    if (t2.pret > t1.pret){
        cout << "Telefonul " << t2.marca << " e mai scump.";
    }
    else if (t1.pret > t2.pret){
        cout << "Telefonul " << t1.marca << " e mai scump.";
    }
    else {
        cout << "Telefoanele au acelasi pret.";
    }
}

int main(){
    telefon t1;
    telefon t2;
    citireInformatii1(t1);
    citireInformatii1(t2);
    cout << "Afisare informatii telefon 1: ";
    afisareInformatii1(t1);
    cout << "Afisare informatii telefon 2: ";
    afisareInformatii1(t2);

    comparatieTelefoane(t1, t2);
    return 0;


}