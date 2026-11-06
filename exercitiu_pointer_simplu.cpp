#include <iostream>
#include <cstring>
using namespace std;

struct Ghiozdan{
    float lungime;
    int nrBuzunare;
    bool areLaptop;
    char* producator;

};

void modificareGhiozdan(Ghiozdan *g, float lungimeNoua){
    g->lungime = lungimeNoua;
}
void afisareGhiozdan(Ghiozdan& g1){
    cout << "Lungime: " << g1.lungime << endl;
    cout << "Numar buzunare: " << g1.nrBuzunare << endl;
    cout << "Laptop?: " << g1.areLaptop << endl;
    cout << "Producator: " << g1.producator << endl;
}
int main(){
    Ghiozdan g1;
    g1.lungime = 45;
    g1.nrBuzunare = 3;
    g1.areLaptop = true;

    char buffer[100];

    cout << "Producator: ";
    cin >> buffer;

    g1.producator = new char[strlen(buffer)+1];
    strcpy(g1.producator, buffer);
    /*
    cout << "Lungime: " << g1.lungime << endl;
    cout << "Numar buzunare: " << g1.nrBuzunare << endl;
    cout << "Laptop?: " << g1.areLaptop << endl;
    cout << "Producator: " << g1.producator << endl;
    */
    afisareGhiozdan(g1);
    modificareGhiozdan(&g1, 50);
    cout << "Lungime noua: " << g1.lungime << endl;
    delete [] g1.producator;
    return 0;

}