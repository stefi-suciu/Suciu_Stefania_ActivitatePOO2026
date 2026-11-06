#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Prajitura{
private:
    char* denumire;
    float pret;
    int cantitate;
    bool dePost;
    int nrIngrediente;
    string* ingrediente;
    const int id;
    static int contor;
public: 
    Prajitura():id(contor++){
        this->denumire = new char[strlen("Tiramisu")+1];
        strcpy(this->denumire, "Tiramisu"); 
        this->pret = 15;
        this->cantitate = 250;
        this->dePost = true;
        this->nrIngrediente = 3;
        this->ingrediente = new string[this->nrIngrediente];
        this->ingrediente[0] = "Piscoturi";
        this->ingrediente[1] = "Vanilie";
        this->ingrediente[2] = "Cafea";
        
    }
    Prajitura(const char* denumire, float pret):id(contor++){
        this->denumire = new char [strlen(denumire)+1];
        strcpy(this->denumire, denumire);
        this->pret = pret;
        this->cantitate = 250;
        this->dePost = true;
        this->nrIngrediente = 3;
        this->ingrediente = new string[this->nrIngrediente];
        this->ingrediente[0] = "Piscoturi";
        this->ingrediente[1] = "Vanilie";
        this->ingrediente[2] = "Cafea";
    }
    Prajitura(const Prajitura& p):id(contor++){
        this->denumire = new char [strlen(p.denumire)+1];
        strcpy (this->denumire, p.denumire);
        this->pret = p.pret;
        this->cantitate = p.cantitate;
        this->dePost = p.dePost;
        this->nrIngrediente = p.nrIngrediente;
        
        this->ingrediente = new string[this->nrIngrediente];
        for (int i=0; i<this->nrIngrediente; i++){
            this->ingrediente[i] = p.ingrediente[i];
        }
    }
    ~Prajitura(){
        delete[] denumire;
        delete[] ingrediente;
    }
    int getCantitate(){
        return this->cantitate;
    }
    int getNrIngrediente(){
        return this->nrIngrediente;
    }
    float getPret(){
        return this->pret;
    }
    static int getContor(){
        return contor;
    }

    void afisare(){
        cout << "Denumire: " << this->denumire << endl;
        cout << "Pret " << this->pret << endl;
        cout << "Cantitate " << this->cantitate << endl;
        cout << "De post?: " << (this->dePost ? "DA" : "NU") << endl;
        cout << "Numar ingrediente: " << this->nrIngrediente << endl;
        cout << "Ingrediente: ";
        for (int i=0; i<this->nrIngrediente; i++){
            cout << this->ingrediente[i] << endl;
        }
    }

    float costMediuGram(){
        if (this->cantitate == 0){
            return 0;
        }
        else{
            return this->pret/this->cantitate;
        }
    }
    void modificaDenumire(const char* denumire){
        delete [] this->denumire;
        this->denumire = new char[strlen(denumire)+1];
        strcpy(this->denumire, denumire);
    }

};
int Prajitura::contor = 100;

float calculeazaCantitateaTotala(Prajitura* prajituri, int nr_prajituri){
    float total = 0;
    for (int i=0; i<nr_prajituri; i++){
        total += prajituri[i].getCantitate();
    }
    
    return total;
}
float calculezaPretulPerIngredient(Prajitura p){
    
}

int main(){

}