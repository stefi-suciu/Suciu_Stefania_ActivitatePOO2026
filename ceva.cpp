#include <iostream>
#include <string>
using namespace std;

class Telefon{
private:
    string marca;
    int baterie = 100;
    bool pornit = false;
public:
    void setMarca(string m){
        marca = m;
    }
    void porneste(){
        if (baterie > 0){
            pornit = true;
        }
    }
    void opreste(){
        pornit = false;
    }
    void foloseste(int minute){
        int aux;
        if (pornit && minute>0 && baterie > 0){
            baterie -= minute;
        }
        if (baterie < 0){
            baterie = 0;
        }
        if (baterie == 0){
            pornit = false;
        }
    }
    void incarca(int procent){
        int aux;
        if (procent > 0){
            baterie += procent;
        }
        if (baterie > 100){
            aux = baterie - 100;
            baterie = baterie - aux;
        }
        //nu stiu cum sa fac aia ca bateria nu poate depasi 100
    }
    void afisare(){
        cout << "Marca: " << marca << endl;
        cout << "Bateria: " << baterie << endl;
        cout << "Pornit/Oprit: ";
        if (pornit){
            cout << "Pornit" << endl; 
        }
        else{
            cout << "Oprit" << endl;
        }
    }
};

int main(){
    Telefon t1;
    t1.setMarca("Samsung");
    t1.afisare();
    cout << endl;

    t1.porneste();
    t1.foloseste(35);
    t1.afisare();
    cout << endl;

    t1.incarca(50);
    t1.afisare();
    cout << endl;

    t1.foloseste(120);
    t1.afisare();
    cout << endl;
    
}