#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Laptop{
private:
    const int idLaptop;
    char* producator;
    string model;
    int nrComponente;
    float* preturiComponente;
    int* cantitatiComponente;
    bool esteDisponibil;
    float reducere;
    static float taxaTransport;
public:
    //constructor fara parametri
    Laptop():idLaptop(100){
        this->producator = new char[strlen("Necunoscut")+1];
        strcpy(this->producator, "Necunoscut");
        this->model = "Necunoscut";
        this->nrComponente = 0;
        this->preturiComponente = nullptr;
        this->cantitatiComponente = nullptr;
        this->esteDisponibil = false;
        this->reducere = 0;
    }
    //constructor cu parametri
    Laptop(int _idLaptop, const char* _producator, string _model, int _nrComponente, float* _preturiComponente, int* _cantitatiComponente, bool _esteDisponibil, float _reducere):idLaptop(_idLaptop){
        if (_producator != nullptr){
            this->producator = new char[strlen(_producator)+1];
            strcpy(this->producator, _producator);
        }
        else{
            this->producator = nullptr;
        }
        this->model = _model;
        if (_nrComponente > 0 && _preturiComponente != nullptr && _cantitatiComponente != nullptr){
            this->nrComponente = _nrComponente;
            this->cantitatiComponente = new int[_nrComponente];
            for (int i=0; i<_nrComponente; i++){
                if (_cantitatiComponente[i] > 0){
                    this->cantitatiComponente[i] = _cantitatiComponente[i];
                }
                else{
                    this->cantitatiComponente[i] = 0;
                }
            }
            this->preturiComponente = new float[_nrComponente];
            for (int i=0; i<_nrComponente; i++){
                if (_preturiComponente[i] > 0){
                    this->preturiComponente[i] = _preturiComponente[i];
                }
                else{
                    this->preturiComponente[i] = 0; 
                }
            }
        }
        else{
            this->nrComponente = 0;
            this->preturiComponente = nullptr;
            this->cantitatiComponente = nullptr;
        }
        this->esteDisponibil = _esteDisponibil;
        if (_reducere >= 0 && _reducere <= 100){
            this->reducere = _reducere;
        }
        else{
            this->reducere = 0;
        }
    }
    //constructor de copiere
    Laptop (const Laptop& l):idLaptop(l.idLaptop){
        if (l.producator != nullptr){
            this->producator = new char[strlen(l.producator)+1];
            strcpy(this->producator, l.producator);
        }
        else{
            this->producator = nullptr;
        }
        this->model = l.model;
            if (l.nrComponente > 0){
                this->nrComponente = l.nrComponente;
                this->preturiComponente = new float[l.nrComponente];
                for (int i=0; i<l.nrComponente; i++){
                    this->preturiComponente[i] = l.preturiComponente[i];
                }
                this->cantitatiComponente = new int[l.nrComponente];
                for (int i=0; i<l.nrComponente; i++){
                    this->cantitatiComponente[i] = l.cantitatiComponente[i];
                }
            }
            else{
                this->nrComponente = 0;
                this->preturiComponente = nullptr;
                this->cantitatiComponente = nullptr;
            }
        
        this->esteDisponibil = l.esteDisponibil;
        this->reducere = l.reducere;
    }
    ~Laptop(){
        delete[] this->producator;
        delete[] this->preturiComponente;
        delete[] this->cantitatiComponente;
    }
    void setProducator(const char* producator){
        char* copie = nullptr;
        if (producator != nullptr){
            copie = new char[strlen(producator)+1];
            strcpy(copie, producator);
        }
        delete[] this->producator;
        this->producator = copie;
    }
    string getProducator(){
        if (this->producator != nullptr){
            return this->producator;
        }
        else{
            return "";
        }
    }
    void setReducere(float reducere){
        if (reducere >= 0 && reducere <=100){
            this->reducere = reducere;
        }
        else{
            this->reducere = 0;
        }
    }
    float getReducere(){
        return this->reducere;
    }
    void setEsteDisponibil(bool esteDisponibil){
        this->esteDisponibil = esteDisponibil;
    }
    bool getEsteDisponibil(){
        return this->esteDisponibil;
    }
    //operator =
    Laptop& operator=(const Laptop& l){
        if (this != &l){
            delete[] this->producator;
            if (l.producator != nullptr){
                this->producator = new char[strlen(l.producator)+1];
                strcpy(this->producator, l.producator);
            }
            else{
                this->producator = nullptr;
            }
            this->model = l.model;
            delete[] this->cantitatiComponente;
            delete[] this->preturiComponente;
            if (l.nrComponente > 0 && l.preturiComponente != nullptr && l.cantitatiComponente != nullptr){
                this->nrComponente = l.nrComponente;
                this->cantitatiComponente = new int[l.nrComponente];
                for (int i=0; i<l.nrComponente; i++){
                    this->cantitatiComponente[i] = l.cantitatiComponente[i];
                }
                this->preturiComponente = new float[l.nrComponente];
                for (int i=0; i<l.nrComponente; i++){
                    this->preturiComponente[i] = l.preturiComponente[i];
                }
            }
            else{
                this->nrComponente = 0;
                this->cantitatiComponente = nullptr;
                this->preturiComponente = nullptr;
            }
            
            this->esteDisponibil = l.esteDisponibil;
            this->reducere = l.reducere;
        }
        return *this;
    }
    //operator <<
    friend ostream& operator<<(ostream& out, const Laptop& l){
        out << l.idLaptop << endl; 
        if (l.producator != nullptr){
            out << l.producator << endl;
        }
        else{
            out << "Necunoscut" << endl;
        } 
        out << l.model << endl << l.nrComponente << endl;
        out << "Preturi componente: " << endl;
        for (int i=0; i<l.nrComponente; i++){
            out << l.preturiComponente[i] << "; ";
        }
        out << endl;
        out << "Cantitati componente: " << endl;
        for (int i=0; i<l.nrComponente; i++){
            out << l.cantitatiComponente[i] << "; ";
        }
        out << endl;
        out << (l.esteDisponibil ? "DA" : "NU") << endl << l.reducere << endl << l.taxaTransport << endl;
        return out;

    }
    float calculeazaPretTotal(){
        float total = 0;
        float inmultire = 0;
        float red;
        if (nrComponente > 0 && preturiComponente != nullptr && cantitatiComponente != nullptr){
            for (int i=0; i<nrComponente; i++){
                inmultire += preturiComponente[i] * cantitatiComponente[i];
            }
            red = 1 - reducere/100;
            total += inmultire * red + taxaTransport;
        }
        else{
            total = 0;
        }
        return total;
    }
};
float Laptop::taxaTransport = 25.0f;
int main(){
    Laptop l;
    Laptop l1;
    cout << l1;
    float preturiComponente[] = {101.99, 200.99, 500};
    int cantitatiComponente[] = {1, 2, 3};
    Laptop l2(101, "Lenovo", "Zenbook", 3, preturiComponente, cantitatiComponente, true, 10);
    cout << l2;
    Laptop l3(l2);
    cout << l3;
    l3=l1;
    cout << l3;
    l2.setEsteDisponibil(false);
    l2.setProducator("ASUS");
    l2.setReducere(30);
    cout << "Al doilea laptop este disponibil? " << (l2.getEsteDisponibil() ? "DA" : "NU") << endl;
    cout << "Producator laptop 2: " << l2.getProducator() << endl;
    cout << "Reducere laptop 2: " << l2.getReducere() << endl;
    cout << "Pret total laptop 2: " << l2.calculeazaPretTotal() << endl;

    return 0;
}