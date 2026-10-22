#include <iostream>
using namespace std;

//si seminar 4 aici in continuarea semiarului 3

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
        //implementare inline 
        this->denumire = new char [strlen("Tiramisu")+1];
        strcpy(denumire, "Tiramisu");
        this->pret = 15;
        this->cantitate = 250;
        this->dePost = true;
        this->nrIngrediente = 3;
        this->ingrediente = new string[this->nrIngrediente];
        this->ingrediente[0]="Piscoturi";
        this->ingrediente[1]="Vanilie";
        this->ingrediente[2]="Cafea";

    }
    

    Prajitura(const char* denumire, float pret):id(contor++){
        //implementare inline 
        this->denumire = new char [strlen("Tiramisu")+1];
        strcpy(this->denumire, denumire);
        this->pret = 15;
        this->cantitate = 250;
        this->dePost = true;
        this->nrIngrediente = 3;
        this->ingrediente = new string[this->nrIngrediente];
        this->ingrediente[0]="Piscoturi";
        this->ingrediente[1]="Vanilie";
        this->ingrediente[2]="Cafea";
    }
    //seminar4
    Prajitura(const Prajitura& p):id(contor++){
        this->denumire = new char[strlen(p.denumire)+1];
        strcpy(this->denumire, p.denumire);

        this->pret = p.pret;
        this->cantitate = p.cantitate;
        this->dePost = p.dePost;
        this->nrIngrediente = p.nrIngrediente;
    
        this->ingrediente = new string[this->nrIngrediente];
        for (int i=0; i< this->nrIngrediente; i++){
            this->ingrediente[i] = p.ingrediente[i];
        }
    }

    ~Prajitura(); //declarare destructor
    //getter si setter
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
    
    //operatorul de rezolutie



    void afisare(){
        cout << "Denumire: " << this->denumire << endl;
        cout << "Pret: " << this->pret << endl;
        cout << "Cantitate: " << this->cantitate << endl;
        cout << "De post? (0/1): " << (this->dePost ? "Da":"Nu") << endl;
        cout << "Numar ingrediente: " << this->nrIngrediente << endl;
        cout << "Ingredientele sunt: ";
        for (int i=0; i<this->nrIngrediente; i++){
            cout << this->ingrediente[i] << "; ";
        }
        cout << endl;
    }
    float costMediuGram(){
        if (cantitate == 0){
            return 0;
        }
        else {
            return this->pret/this->cantitate;
        }
    }

    void modificaDenumire(const char* denumire){
        delete this->denumire;
        
        this->denumire = new char [strlen(denumire)+1];
        strcpy(this->denumire, denumire);
    }
};

int Prajitura::contor = 100; 
//destructorul:
Prajitura::~Prajitura(){ //implementare destructor
    delete[] denumire;
    delete[] ingrediente;
}

float calculeazaCantitateaTotala (Prajitura* prajituri, int nr_prajituri){
    float greutate = 0;
    for (int p=0; p<nr_prajituri; p++){
        greutate += prajituri[p].getCantitate();
    }
    return greutate;
}

float calculeazaPretPerIngredient(Prajitura p){
    if (p.getNrIngrediente() != 0){
        return p.getPret() / p.getNrIngrediente();
    }
    return 0;
}



int main(){
    /*Prajitura p;
    Prajitura p2("Amandina", 40);
    p2.afisare();
    p.afisare();
    cout << p.costMediuGram();
    Prajitura* prajituri;
    prajituri = new Prajitura[3]; //eroarea asta cand comentez primul constructor implicit
    prajituri[2].afisare();
    prajituri[1].pret = 50;
    prajituri[2].cantitate = 70;

    prajituri[0].modificaDenumire("tort");
    prajituri[1].modificaDenumire("ecler");

    for (int i=0; i<3; i++){
        //cout << prajituri[i].costMediuGram() << endl;
        cout << prajituri[i].denumire << ' ' << prajituri[i].costMediuGram() << endl;
    }

    float greutate_totala = calculeazaCantitateaTotala(prajituri, 3);
    cout << "Total: " << greutate_totala << endl;
    */
   Prajitura p;
   p.afisare();
   Prajitura::getContor();

   cout << calculeazaPretPerIngredient(p);

   
}

//operator de rezolutie?
//static constant?
//destructor?