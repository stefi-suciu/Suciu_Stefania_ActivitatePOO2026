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
    friend class Student;

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
    //aici seminar5


    ~Prajitura(); //declarare destructor
    //seminar5
    Prajitura &operator=(const Prajitura &P1){
        if (this != &P1){
            this->cantitate = P1.cantitate;
            if (this->denumire != NULL){
                delete[] this->denumire;
            }
            this->denumire = new char(strlen(P1.denumire)+1);
            strcpy (this->denumire, denumire);
            this->dePost = P1.dePost;
            this->pret = P1.pret;
            this->nrIngrediente = P1.nrIngrediente;
            if (this->ingrediente != NULL){
                delete [] this->ingrediente;
            }
            this->ingrediente = new string [this->nrIngrediente];
            for (int i=0; i<nrIngrediente; i++){
                this->ingrediente[i] = P1.ingrediente[i];
            }
            
        }
        return *this;
    }
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

    //operatorul plus care aduna doua prajituri
    Prajitura operator+(const Prajitura& p){
        Prajitura result = *this; //apelat constructorul de copiere ca sa adune in rezultat cred?
        result.pret = this->pret + p.pret;
        result.cantitate = this->cantitate + p.cantitate;
        return result;
    }


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
//relatia de 
class Student{
private: 
    string nume;
    Prajitura prajitura; //relatie de hazard
public:
    Student(){
        this->nume = "Andrei";
    }
    Student(string nume, Prajitura p){
        this->nume = nume;
        this->prajitura = p;
    }
    string getNume(){
        return this->nume;
    }
    Prajitura getPrajitura(){
        return this->prajitura;
    }
    void setNume(){
        this->nume = nume;
    }
    void setPrajitura(Prajitura p){
        this->prajitura = p;
    }
    float calculeazaNumarTotalCalorii(float caloriiPerGram){
        float nrTotal = caloriiPerGram *this->prajitura.getCantitate();
        return nrTotal;

    }
    void afiseazaMasa(){
        cout << this->nume << " mananca prajitura " << this->prajitura.denumire;
    }
};
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

   Prajitura P1("Amandina", 20);
   p = P1;
   P1=P1;
   Student s1("Cristian", P1);
   s1.afiseazaMasa(); //nu imi apare ce prajitura mananca
   cout << endl;
   cout << s1.calculeazaNumarTotalCalorii(0.5);
   cout << calculeazaPretPerIngredient(p);

   
}

//operator de rezolutie?
//static constant?
//destructor?
//pt test operatori egal
