#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Biblioteca{
private:
    const int codBiblioteca; //codul unic al bibliotecii
    string numeBiblioteca; //numele bibliotecii
    char* numeBibliotecar; //numele bibliotecarului alocat dinamic
    int nrCarti; //numarul de carti
    float* preturiCarti; //vector dinamix cu preturile cartilor
    int nrAngajati; //numarul angajatilor
    float buget; //bugetul disponibil
    static float taxaMinima; //taxa minima pentru imprumutul unei carti 
    /*
    Constructor fără parametri
    Inițializați toate atributele. Biblioteca va avea implicit 2 cărți, cu prețurile 35 și 50 lei. 
    Inițializați codBiblioteca cu valoarea 100.
    */
public:
    Biblioteca():codBiblioteca(100){
        this->numeBiblioteca = "Necunoscut";
        
        this->numeBibliotecar = new char[strlen("Necunoscut")+1];
        strcpy(this->numeBibliotecar, "Necunoscut");
        this->nrCarti = 2;
        
        this->preturiCarti = new float[2];
        this->preturiCarti[0] = 35;
        this->preturiCarti[1] = 50;

        this->nrAngajati = 0;
        this->buget = 0;

    }
    /*
    Constructor cu parametri
    Primiți ca parametri numeBiblioteca, numeBibliotecar, nrCarti, preturiCarti și buget. Validați numărul de cărți, prețurile și bugetul. 
    Inițializați și celelalte atribute.
    */
    Biblioteca(string numeBiblioteca, const char* numeBibliotecar, int nrCarti, float* preturiCarti, float buget):codBiblioteca(100){
        this->numeBiblioteca = numeBiblioteca;

        if (numeBibliotecar != nullptr){
            this->numeBibliotecar = new char[strlen(numeBibliotecar)+1];
            strcpy(this->numeBibliotecar, numeBibliotecar);
        }
        else{
            this->numeBibliotecar = nullptr;
        }
        if (nrCarti > 0 && preturiCarti != nullptr){
            this->nrCarti = nrCarti;
            this->preturiCarti = new float[nrCarti];
            for (int i=0; i<nrCarti; i++){
                if (preturiCarti[i] > 0){
                    this->preturiCarti[i] = preturiCarti[i];
                }
                else{
                    this->preturiCarti[i] = 0;
                }
            }
        }
        else{
            this->nrCarti = 0;
            this->preturiCarti = nullptr;
        }
        this->nrAngajati = 0;
        if (buget >= 0){
            this->buget = buget;
        }
        else{
            this->buget = 0;
        }
    }
    /*
    Destructor și constructor de copiere
    Eliberați memoria dinamică și implementați copierea profundă a obiectelor.
    */
    ~Biblioteca(){
    delete[] this->numeBibliotecar;
    delete[] this->preturiCarti;
    }
    Biblioteca(const Biblioteca& b):codBiblioteca(b.codBiblioteca){
    this->numeBiblioteca = b.numeBiblioteca;
    if (b.numeBibliotecar != nullptr){
        this->numeBibliotecar = new char[strlen(b.numeBibliotecar)+1];
        strcpy(this->numeBibliotecar, b.numeBibliotecar);
    }
    else{
        this->numeBibliotecar = nullptr;
    }
    this->nrCarti = b.nrCarti;
    if (b.nrCarti > 0 && b.preturiCarti != nullptr){
        float* copie = new float[b.nrCarti];
        for (int i=0; i<b.nrCarti; i++){
            copie[i] = b.preturiCarti[i];
        }
        this->preturiCarti = copie;
    }
    else{
        this->preturiCarti = nullptr;
    }
    this->nrAngajati = b.nrAngajati;
    this->buget = b.buget;

   }
   /*
   Implementați metode de acces pentru numeBiblioteca, numeBibliotecar și buget, cu validări unde este necesar.
   */
   void setNumeBiblioteca(string numeBiblioteca){
    this->numeBiblioteca = numeBiblioteca;
   }
   string getNumeBiblioteca(){
    return this->numeBiblioteca;
   }
   void setNumeBibliotecar(const char* numeBibliotecar){
    
    if (numeBibliotecar != nullptr){
        delete[] this->numeBibliotecar;
        this->numeBibliotecar = new char[strlen(numeBibliotecar)+1];
        strcpy(this->numeBibliotecar, numeBibliotecar);
    }
    else{
        this->numeBibliotecar = nullptr;
    }
   }
   string getNumeBibliotecar(){
    if (this->numeBibliotecar != nullptr){
        return this->numeBibliotecar;
    }
    else{
        return ""; //nu stiu daca pot sa returnez pointer gol sau trebuia sa pun 0
    }
   }
   void setBuget(float buget){
    if (buget >= 0){
        this->buget = buget;
    }
    }
   float getBuget(){
    return this->buget;
    
   }
   /*
   Supraîncărcați operatorul de atribuire fără pierderi de memorie.
   Respectați atributele const și static.
   */
    Biblioteca& operator=(const Biblioteca& b){
    if (this != &b){
        this->numeBiblioteca = b.numeBiblioteca;
        delete[] this->numeBibliotecar;

        if (b.numeBibliotecar != nullptr){
            this->numeBibliotecar = new char[strlen(b.numeBibliotecar)+1];
            strcpy(this->numeBibliotecar, b.numeBibliotecar);
        }
        else{
            this->numeBibliotecar = nullptr;
        }
        
        delete[] this->preturiCarti;
        if (b.nrCarti > 0 && b.preturiCarti != nullptr){
            this->nrCarti = b.nrCarti;
            this->preturiCarti = new float[this->nrCarti];
            for (int i=0; i<this->nrCarti; i++){
                this->preturiCarti[i] = b.preturiCarti[i];
            }
        }
        else{
            this->nrCarti = 0;
            this->preturiCarti = nullptr;
        }
        this->nrAngajati = b.nrAngajati;
        this->buget = b.buget;

    }
    return *this;
  }
  /*
  Permiteți afișarea și citirea obiectelor Biblioteca, inclusiv a șirurilor cu spații. 
  Codul constant nu se modifică la citire.
  */
  friend ostream& operator<<(ostream& out, const Biblioteca& b){
    out << b.codBiblioteca << endl;
    out << b.numeBiblioteca << endl;
    out << (b.numeBibliotecar != nullptr ? b.numeBibliotecar : "Necunoscut") << endl;
    out << b.nrCarti << endl;
    for (int i=0; i<b.nrCarti; i++){
        out << b.preturiCarti[i] << "; ";
    }
    out << endl;
    out << b.nrAngajati << endl;
    out << b.buget << endl;
    return out;
    }
    //friend istream& operator>>(istream& in, Biblioteca& b){

    //}
    //Returnați media aritmetică a prețurilor cărților. 
    //Dacă nu există cărți, returnați 0.
    float medieAritmetica(){
        float suma = 0;
        float medie;
        if (this->nrCarti > 0 && this->preturiCarti != nullptr){
            for (int i=0; i<this->nrCarti; i++){
                suma += this->preturiCarti[i];
            }
            medie = suma/this->nrCarti;
            return medie;
        }
        else{
            return 0;
        }
    }
};
float Biblioteca::taxaMinima = 10.0f;

int main(){
    Biblioteca b;
    Biblioteca b1;
    cout << b1;
    cout << endl;
    float preturiCarti[] = {12.99, 10.50, 16.80, 19};
    Biblioteca b2("Nationala", "Radu", 4, preturiCarti, 2000);
    cout << b2;
    cout << endl;
    Biblioteca b3(b1);
    cout << b3;
    cout << endl;
    b3=b2;
    cout << b3 << endl;
    b2.setNumeBiblioteca("Brasov");
    b2.setNumeBibliotecar("Mircea");
    cout << "Numele celei de a doua biblioteci este: " << b2.getNumeBiblioteca() << ", iar bibliotecarul ei este: " << b2.getNumeBibliotecar() << endl;
    
    return 0;
}