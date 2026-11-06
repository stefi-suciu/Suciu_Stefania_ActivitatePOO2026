#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class CartelaTransport{
private:
    const string serieCartela;
    string numePosesor;
    char* producatorCartela;
    int nrZileUtilizare;
    float sumaPortofel;
    int nrCalatorii;
    float* valoriCalatorii;
    static float valoareMinCalatorie;
public:
    //1.constructor fara parametri
    CartelaTransport():serieCartela("IT2026"){
        this->numePosesor = "Stefi";
        this->producatorCartela = new char[strlen("Metrorex")+1];
        strcpy(this->producatorCartela, "Metrorex");
        this->nrZileUtilizare = 5;
        this->sumaPortofel = 12.90;
        this->nrCalatorii = 2;
        this->valoriCalatorii = new float[this->nrCalatorii];
        this->valoriCalatorii[0] = 10.99;
        this->valoriCalatorii[1] = 6.99;
        

    }
    //2.constructor cu parametri
    CartelaTransport(string numePosesor, float sumaPortofel, int nrCalatorii, float* valoriCalatorii):serieCartela("IT2026"){
        this->numePosesor = numePosesor;
        this->producatorCartela = new char[strlen("Necunoscut")+1];
        strcpy(this->producatorCartela, "Necunoscut");
        this->nrZileUtilizare = 0;
        if (sumaPortofel > 0){
            this->sumaPortofel = sumaPortofel;
        }
        else{
            this->sumaPortofel = 0;
        }
        if (nrCalatorii > 0){
            this->nrCalatorii = nrCalatorii;
        }
        else{
            this->nrCalatorii = 0;
        }
        if (nrCalatorii > 0 && valoriCalatorii != nullptr){
            this->valoriCalatorii = new float[this->nrCalatorii];
            for (int i=0; i<this->nrCalatorii; i++){
                this->valoriCalatorii[i] = valoriCalatorii[i];
            }
        }
        else{
            this->valoriCalatorii = nullptr;
            this->nrCalatorii = 0;
        }
    }
    //3.destructor;
    ~CartelaTransport(){
        delete[] producatorCartela;
        delete[] valoriCalatorii;
    }
    //4.getter si setter nume si valori
    void setNumePosesor(string numePosesor){
        if (numePosesor.length() > 0){
            this->numePosesor = numePosesor;
        }
        else{
            this->numePosesor = "Invalid";
        }
    }
    void setValoriCalatorii(float* valoriCalatorii, int nrCalatorii){
        if (nrCalatorii > 0 && valoriCalatorii != nullptr){
            float* copie = new float[nrCalatorii];
            for (int i=0; i<nrCalatorii; i++){
                copie[i] = valoriCalatorii[i];
            }
            delete[] this->valoriCalatorii;
            this->valoriCalatorii = copie;
            this->nrCalatorii = nrCalatorii;
        }
        
    }
    string getNumePosesor(){
        return this->numePosesor;
    }
    float* getValoriCalatorii(){
        return this->valoriCalatorii;
        
    }
    //5.constructor de copiere
    CartelaTransport(const CartelaTransport& c):serieCartela(c.serieCartela){
        this->numePosesor = c.numePosesor;

        if (c.producatorCartela != nullptr){
            this->producatorCartela = new char[strlen(c.producatorCartela)+1];
            strcpy(this->producatorCartela, c.producatorCartela);
        }
        else{
            this->producatorCartela = nullptr;
        }
        this->nrZileUtilizare = c.nrZileUtilizare;
        this->sumaPortofel = c.sumaPortofel;
        this->nrCalatorii = c.nrCalatorii;

        if (c.valoriCalatorii != nullptr){
            this->valoriCalatorii = new float[c.nrCalatorii];
            for (int i=0; i<c.nrCalatorii; i++){
                this->valoriCalatorii[i] = c.valoriCalatorii[i];
            }
        }
        else{
            this->valoriCalatorii = nullptr;
        }
    }
    //6.operator = 
    CartelaTransport& operator=(const CartelaTransport& c){
        if (this != &c){
            this->numePosesor = c.numePosesor;
            this->nrZileUtilizare = c.nrZileUtilizare;
            delete[] this->producatorCartela;

            if (c.producatorCartela != nullptr){
                this->producatorCartela = new char[strlen(c.producatorCartela)+1];
                strcpy(this->producatorCartela, c.producatorCartela);
            }
            else{
                this->producatorCartela = nullptr;
            }
            this->sumaPortofel = c.sumaPortofel;
            this->nrCalatorii = c.nrCalatorii;
            delete[] this->valoriCalatorii;

            if (c.nrCalatorii > 0 && c.valoriCalatorii != nullptr){
                this->valoriCalatorii = new float[this->nrCalatorii];
                for (int i=0; i<c.nrCalatorii; i++){
                    this->valoriCalatorii[i] = c.valoriCalatorii[i];
                }
            }
            else{
                this->valoriCalatorii = nullptr;
            }

        }
        return *this;
    }
    //7.operator<<
    friend ostream& operator<<(ostream& out, const CartelaTransport& c){
        out << c.serieCartela << endl;
        out << c.numePosesor << endl;
        out << c.producatorCartela << endl;
        out << c.nrZileUtilizare << endl;
        out << c.sumaPortofel << endl;
        out << c.nrCalatorii << endl;
        for (int i=0; i<c.nrCalatorii; i++){
            out << c.valoriCalatorii[i] << endl;
        }
        return out;
    }


};
float CartelaTransport::valoareMinCalatorie = 9.99;

int main(){
    CartelaTransport c;
    CartelaTransport c1;
    float calatorii[] = {10.99, 35.99, 11.99, 21.99};
    CartelaTransport c2("Delia", 100, 4, calatorii);
    CartelaTransport c3(c1);
    c2=c1;
    cout << c1;
    cout << endl;
    cout << c2;
    cout << endl;
    cout << c3;
    cout << "Numele posesorului pentru a doua cartela este: " << c2.getNumePosesor() << endl;
    cout << "Valorile calatoriilor pentru a treia cartela sunt: ";
    float* valori = c3.getValoriCalatorii();
    for (int i=0; i<2; i++){
        cout << valori[i] << endl;
    }
    return 0;

}