#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class RezervareHotel{
private: 
    static int numarRezervari;
    const int idRezervare;
    char* numeClient;
    string numeHotel;
    int numarNopti;
    double* preturiNopti;
    bool esteConfirmata;
    float reducere;
public:
    //contstructor fara parametri
    RezervareHotel():idRezervare(numarRezervari++){
        this->numeClient = new char[strlen("Anonim")+1];
        strcpy(this->numeClient, "Anonim");
        this->numeHotel = "Necunoscut";
        this->numarNopti = 0;
        this->preturiNopti = nullptr;
        this->esteConfirmata = false;
        this->reducere = 0;
    }
    //constructor cu parametri
    RezervareHotel(const char* _numeClient, string _numeHotel, int _numarNopti, double* _preturiNopti, bool _esteConfirmata, float _reducere):idRezervare(numarRezervari++){
        if (_numeClient != nullptr){
            this->numeClient = new char[strlen(_numeClient)+1];
            strcpy(this->numeClient, _numeClient);
        }
        else{
            this->numeClient = nullptr;
        }
        if (_numeHotel != ""){
            this->numeHotel = _numeHotel;
        }
        else{
            this->numeHotel = "";
        }
        if (_numarNopti > 0 && _preturiNopti != nullptr){
            this->numarNopti = _numarNopti;
            this->preturiNopti = new double[_numarNopti];
            for (int i=0; i<_numarNopti; i++){
                this->preturiNopti[i] = _preturiNopti[i];
            }
        }
        else{
            this->numarNopti = 0;
            this->preturiNopti = nullptr;
        }
        this->esteConfirmata = _esteConfirmata;
        if (_reducere >= 0 && _reducere <= 100){
            this->reducere = _reducere;
        }
        else{
            this->reducere = 0;
        }
    }
    //constructor de copiere
    RezervareHotel(const RezervareHotel& h):idRezervare(numarRezervari++){
        if (h.numeClient != nullptr){
            this->numeClient = new char[strlen(h.numeClient)+1];
            strcpy(this->numeClient, h.numeClient);
        }
        else{
            this->numeClient = nullptr;
        }
        this->numeHotel = h.numeHotel;
        double* copie;
        if (h.numarNopti > 0 && h.preturiNopti != nullptr){
            this->numarNopti = h.numarNopti;
            copie = new double[h.numarNopti];
            for (int i=0; i<h.numarNopti; i++){
                copie[i] = h.preturiNopti[i];
            }
            this->preturiNopti = copie;
        }
        else{
            this->numarNopti = 0;
            this->preturiNopti = nullptr;
        }
        this->esteConfirmata = h.esteConfirmata;
        this->reducere = h.reducere;
    }
    //operator=
    RezervareHotel& operator=(const RezervareHotel& h){
        if (this != &h){
            delete[] this->numeClient;
            char* copie;
            double* copie2;
            if (h.numeClient != 0){
                copie = new char[strlen(h.numeClient)+1];
                strcpy(copie, h.numeClient);
                this->numeClient = copie;
            }
            else{
                this->numeClient = nullptr;
            }
            this->numeHotel = h.numeHotel;
            delete[] this->preturiNopti;
            if (h.numarNopti > 0 && h.preturiNopti != nullptr){
                this->numarNopti = h.numarNopti;
                copie2 = new double[h.numarNopti];
                for (int i=0; i<h.numarNopti; i++){
                    copie2[i] = h.preturiNopti[i];
                }
                this->preturiNopti = copie2;
            }
            else{
                this->numarNopti = 0;
                this->preturiNopti = nullptr;
            }
            this->esteConfirmata = h.esteConfirmata;
            this->reducere = h.reducere;
        }
        return *this;
    }
    //operator <<
    friend ostream& operator<<(ostream& out, const RezervareHotel& h){
        out << "ID rezervare: " << h.idRezervare << endl;
        if (h.numeClient != nullptr){
            out << "Nume client: " << h.numeClient << endl;
        }
        else{
            out << "";
        }
        out << "Nume hotel: " << h.numeHotel << endl;
        out << "Numar nopti: " << h.numarNopti << endl;
        out << "Preturi nopti: " << endl;
        for (int i=0; i<h.numarNopti; i++){
            out << h.preturiNopti[i] << "; ";
        } 
        out << endl;
        out << "Este confirmata rezervarea: " << (h.esteConfirmata ? "DA" : "NU") << endl;
        out << "Reducere: " << h.reducere << endl;
        return out;

    }
    ~RezervareHotel(){
        delete[] this->numeClient;
        delete[] this->preturiNopti;
    }
    void setNumeClient(const char* nume){
        delete[] this->numeClient;
        if (nume != nullptr){
            this->numeClient = new char[strlen(nume)+1];
            strcpy(this->numeClient, nume);
        }
        else{
            this->numeClient = nullptr;
        }
    }
    string getNumeClient(){
        if (this->numeClient != nullptr){
            return this->numeClient;
        }
        else{
            return "";
        }
    }
    void setNumeHotel(string hotel){
        this->numeHotel = hotel;
    }
    string getNumeHotel(){
        return this->numeHotel;
    }
    void setPreturiNopti(const double* preturi, int nrNopti){
        double* copie;
        if (nrNopti > 0 && preturi != nullptr){
            delete[] this->preturiNopti;
            this->numarNopti = nrNopti;
            copie = new double[nrNopti];
            for (int i=0; i<nrNopti; i++){
                copie[i] = preturi[i];
            }
            this->preturiNopti = copie;
        }
        else{
            delete[] this->preturiNopti;
            this->numarNopti = 0;
            this->preturiNopti = nullptr;
        }
    }
    double* getPreturiNopti() const{
        if (this->preturiNopti != nullptr){
            double* copie = new double[this->numarNopti];

            for (int i=0; i<this->numarNopti; i++){
                copie[i] = this->preturiNopti[i];
            }
            return copie;
        }
        else{
            return nullptr;
        }
    }
    double calculeazaPretTotal(){
        double suma = 0;
        double total = 0;
        if (this->numarNopti > 0 && this->preturiNopti != nullptr){
            for (int i=0; i<this->numarNopti; i++){
                suma += this->preturiNopti[i];
            }
            total = suma * (1-this->reducere/100);
            return total;
        }
        else{
            return 0;
        }
    }
    void aplicaReducere(float procent){
        if (procent >= 0 && procent <= 100){
            this->reducere = this->reducere + procent;
        }
    }

};
int RezervareHotel::numarRezervari = 1;

int main(){
    RezervareHotel h;
    RezervareHotel h1;
    cout << h1 << endl;
    
    double pretNopti[] = {100, 200, 300, 250};
    RezervareHotel h2("Stefi", "Abyss", 4, pretNopti, true, 10);
    cout << h2 << endl;
    RezervareHotel h3(h2);
    cout << h3 << endl;
    h3 = h1;
    cout << h3 << endl;
    h3.setNumeClient("Radu");
    cout << "Numele clientului din camera 3 este: " << h3.getNumeClient() << endl;
    h3.setNumeHotel("Azure");
    cout << "Clientul este cazat la hotelul: " << h3.getNumeHotel() << endl;
    double preturiNou[] = {100, 600, 800};
    h3.setPreturiNopti(preturiNou, 3);
    double* preturi = h3.getPreturiNopti();
    cout << "Noile preturi sunt: "; 
    for (int i=0; i<3; i++){
        cout << preturi[i] << " ";
    }
    cout << endl;
    delete[] preturi;
    return 0; 

}