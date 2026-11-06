#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Vapor{
private:
    int capacitate;
    int nrPersoaneImbarcate;
    int* varstePasageri;
    char* numeCapitan;
    float pretBilete;
public: 
    Vapor(){
        this->capacitate = 250;
        this->nrPersoaneImbarcate = 2;
        
        this->varstePasageri = new int[this->nrPersoaneImbarcate];
        this->varstePasageri[0] = 18;
        this->varstePasageri[1] = 30;

        this->numeCapitan = new char[strlen("Sergiu")+1];
        strcpy(this->numeCapitan, "Sergiu");
        this->pretBilete = 99.90;

    }
    Vapor(int capacitate, int nrPersoaneImbarcate, int* varstePasageri, const char* numeCapitan, float pretBilete){
        if (capacitate > 0){
            this->capacitate = capacitate;
        }
        else{
            this->capacitate = 0;
        }
        if (nrPersoaneImbarcate >= 0 && nrPersoaneImbarcate <= this->capacitate){
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
        else{
            this->nrPersoaneImbarcate = 0;
        }
        if (varstePasageri != nullptr){
            this->varstePasageri = new int[this->nrPersoaneImbarcate];
            for (int i=0; i<this->nrPersoaneImbarcate; i++){
                this->varstePasageri[i] = varstePasageri[i];
            }
        }
        else{
            this->varstePasageri = nullptr;
            this->nrPersoaneImbarcate = 0;
        }
        if (numeCapitan != nullptr){
            this->numeCapitan = new char[strlen(numeCapitan)+1];
            strcpy(this->numeCapitan, numeCapitan);
        }
        else{
            this->numeCapitan = nullptr;
        }
        if (pretBilete >= 0){
            this->pretBilete = pretBilete;
        }
        else{
            this->pretBilete = 0;
        }
    }
    ~Vapor(){
        delete[] this->varstePasageri;
        delete[] this->numeCapitan;
    }
    Vapor(const Vapor& v){
        this->capacitate = v.capacitate;
        this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;

        this->varstePasageri = new int[this->nrPersoaneImbarcate];
        for (int i=0; i<this->nrPersoaneImbarcate; i++){
            this->varstePasageri[i] = v.varstePasageri[i];
        }
        this->numeCapitan = new char[strlen(v.numeCapitan)+1];
        strcpy(this->numeCapitan, v.numeCapitan);
        this->pretBilete = v.pretBilete;
    }

    void setNumeCapitan(const char* numeCapitanNou){
        if (numeCapitanNou != nullptr){
            char* copie = new char[strlen(numeCapitanNou)+1];
            strcpy(copie, numeCapitanNou);
            delete[] this->numeCapitan;

            this->numeCapitan = copie;
        }
    }
    void setPretBilete (float pretNouBilete){
        if (pretNouBilete >= 0){
            this->pretBilete = pretNouBilete;
        }
    }
    string getNumeCapitan(){
        return this->numeCapitan != nullptr ? this->numeCapitan : "";
    }
    float getPretBilete(){
        return this->pretBilete;
    }
    Vapor& operator=(const Vapor& v){
        if (this != &v){
            delete[] this->varstePasageri;
            delete[] this->numeCapitan;

            this->capacitate = v.capacitate;
            this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;

            if (v.varstePasageri != nullptr){
                this->varstePasageri = new int[this->nrPersoaneImbarcate];
                for (int i=0; i<this->nrPersoaneImbarcate; i++){
                    this->varstePasageri[i] = v.varstePasageri[i];
                }
            }
            else{
                this->varstePasageri = nullptr;
            }
            if (v.numeCapitan != nullptr){
                this->numeCapitan = new char[strlen(v.numeCapitan)+1];
                strcpy(this->numeCapitan, v.numeCapitan);
            }
            else{
                this->numeCapitan = nullptr;
            }
            this->pretBilete = v.pretBilete;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Vapor& v){
        out << v.capacitate << ", " << v.nrPersoaneImbarcate << ", ";
        for (int i=0; i<v.nrPersoaneImbarcate; i++){
            out << v.varstePasageri[i] << ", ";
        }
        out << (v.numeCapitan != nullptr ? v.numeCapitan : "Necunoscut") << ", " << v.pretBilete << ";";
        return out;
    }
    float calculeazaVarstaMedie(){
        float varstaMedie;
        int suma = 0;
        if (this->nrPersoaneImbarcate > 0 && this->varstePasageri != nullptr){
            for (int i=0; i<this->nrPersoaneImbarcate; i++){
                suma += this->varstePasageri[i];
            }
            varstaMedie = (float)suma/this->nrPersoaneImbarcate;
            return varstaMedie;
        }
        else return 0;
    }
};

int main(){
    Vapor v;
    Vapor v1;
    int varste[] = {12, 24, 67, 30, 20};
    Vapor v2(200, 5, varste, "Alexandru", 110.99);
    Vapor v3(v2);
    v2 = v1;
    v1.setNumeCapitan("Marian");
    v1.setPretBilete(60.99);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    cout << "Numele capitanului din al doilea vapor este: " << v2.getNumeCapitan() << endl;
    cout << "Pretul biletelor din al treilea vapor este: " << v3.getPretBilete() << endl;

    return 0;
}