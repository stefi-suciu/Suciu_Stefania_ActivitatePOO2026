#include <iostream>
#include <string>
using namespace std;

class ContBancar{
private:
    string titular;
    float sold = 0;
    bool activ = true;
public:
    void setTitular(string nume){
        titular = nume;
    }
    void depune(float suma){
        if (suma > 0 && activ){
            sold += suma;
        }
    }
    void retrage(float suma){
        if (suma > 0 && activ && sold >= suma){
            sold -= suma;
        }
        else if (suma > sold){
            cout << "Fonduri insuficiente. " << endl;
        }
    }
    void transfera(ContBancar& destinatar, float suma){
        if (destinatar.activ && activ && suma > 0 && sold >= suma){
            destinatar.sold += suma;
            sold -= suma;
        }
    }
    void inchideCont(){
        activ = false;
    }
    void afisare(){
        cout << "Titular: " << titular << endl;
        cout << "Sold: " << sold << endl;
        cout << "Activ/Inactiv: ";
        if (activ){
            cout << "Activ." << endl;
        }
        else{
            cout << "Inactiv." << endl;
        }
    }
};

int main(){
    ContBancar c1;
    ContBancar c2;
    c1.setTitular("Ana");
    c2.setTitular("Maria");

    c1.depune(1500);
    c2.depune(500);

    c1.retrage(200);
    c1.transfera(c2, 400);

    c1.afisare();
    cout << endl;
    c2.afisare();
    cout << endl;
    c1.retrage(2000);
    c2.inchideCont();
    c1.transfera(c2, 100);

    c1.afisare();
    cout << endl;
    c2.afisare();
    cout << endl;

    return 0;
}