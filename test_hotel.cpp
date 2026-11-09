#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Comanda{
private:
    const int idComanda; //id comanda
    char* numeClient; //numele clientului alocat dinamic
    string magazin; //numele magazinului
    int nrProduse; //numarul produselor
    int* cantitati; //cantitatea comandata
    float* preturi; //pretul unitar al fiecarui produs
    bool livrata; //daca a fost livrata comanda
    float discount; //reducerea procentuala intre 0-100
    static float taxaLivrare; //taxa comuna tuturor produselor;
public:
    //constructor fara parametri
    Comanda():idComanda(100){
        this->numeClient = new char[strlen("Anonim")+1];
        strcpy(this->numeClient, "Anonim");
        this->magazin = "Necunoscut";
        this->nrProduse = 0;
        this->cantitati = nullptr;
        this->preturi = nullptr;
        this->livrata = false;
        this->discount = 0;
    }
    //constructor cu parametri
    Comanda(int idComanda, const char* numeClient, string magazin, int nrProduse, int* cantitati, float* preturi, bool livrata, float discount):idComanda(idComanda){
        if (numeClient != nullptr){
            this->numeClient = new char[strlen(numeClient)+1];
            strcpy(this->numeClient, numeClient);
        }
        else{
            this->numeClient = nullptr;
        }
        this->magazin = magazin;
        if (nrProduse > 0 && cantitati != nullptr && preturi != nullptr){
            this->nrProduse = nrProduse;
            this->cantitati = new int[nrProduse];
            this->preturi = new float[nrProduse];
            for (int i=0; i<nrProduse; i++){
                if (cantitati[i] > 0){
                    this->cantitati[i] = cantitati[i];
                }
                else{
                    this->cantitati[i] = 0;
                }
                if (preturi[i] > 0){
                    this->preturi[i] = preturi[i]; 
                }
                else{
                    this->preturi[i] = 0;
                }
            }
        
        }
        else{
            this->nrProduse = 0;
            this->cantitati = nullptr;
            this->preturi = nullptr;
        }
        this->livrata = livrata;
        if (discount >= 0 && discount <= 100){
            this->discount = discount;
        }
        else{
            this->discount = 0;
        }
    }
    //constructor de copiere
    Comanda (const Comanda& c):idComanda(c.idComanda){
        if (c.numeClient != nullptr){
            this->numeClient = new char[strlen(c.numeClient)+1];
            strcpy(this->numeClient, c.numeClient);
        }
        else{
            this->numeClient = nullptr;
        }
        this->magazin = c.magazin;
        if (c.nrProduse > 0 && c.cantitati != nullptr && c.preturi != nullptr){
            this->nrProduse = c.nrProduse;
            int* copie = new int[c.nrProduse];
            for (int i=0; i<c.nrProduse; i++){
                copie[i] = c.cantitati[i];
            }
            this->cantitati = copie;

            float* copie2 = new float[c.nrProduse];
            for (int i=0; i<nrProduse; i++){
                copie2[i] = c.preturi[i];
            }
            this->preturi = copie2;
        }
        else{
            this->nrProduse = 0;
            this->cantitati = nullptr;
            this->preturi = nullptr;
        }
        this->livrata = c.livrata;
        this->discount = c.discount;
    }
    //operator =
    Comanda& operator=(const Comanda& c){
        if (this != &c){
            delete[] this->numeClient;

            if (c.numeClient != nullptr){
                this->numeClient = new char[strlen(c.numeClient)+1];
                strcpy(this->numeClient, c.numeClient);

            }
            else{
                this->numeClient = nullptr;
            }
            this->magazin = c.magazin;
            delete[] this->cantitati;
            delete[] this->preturi;
            if (c.nrProduse > 0 && c.cantitati != nullptr && c.preturi != nullptr){
                this->nrProduse = c.nrProduse;
                int* copie = new int[c.nrProduse];
                for (int i=0; i<c.nrProduse; i++){
                    copie[i] = c.cantitati[i];
                }
                this->cantitati = copie;
                float* copie2 = new float[c.nrProduse];
                for (int i=0; i<nrProduse; i++){
                    copie2[i] = c.preturi[i];
                }
                this->preturi = copie2;
            }
            else{
                this->nrProduse = 0;
                this->cantitati = nullptr;
                this->preturi = nullptr;
            }
            this->livrata = c.livrata;
            this->discount = c.discount;
        }
        return *this;
    }
    ~Comanda(){
        delete[] this->numeClient;
        delete[] this->cantitati;
        delete[] this->preturi;
    }
    void setNumeClientNou(const char* numeClientNou){
        char* copie = nullptr;
        if (numeClientNou != nullptr){
            copie = new char[strlen(numeClientNou)+1];
            strcpy(copie, numeClientNou);
        }
        
        delete[] this->numeClient;
        this->numeClient = copie;
        
    }
    void setDiscountNou(float discountNou){
        if (discountNou >= 0 && discountNou <= 100){
            this->discount = discountNou;
        }
        else{
            this->discount = 0;
        }
    }
    void setLivrataNou(bool livrataNou){
        this->livrata = livrataNou;
    }
    string getNumeClientNou(){
        if (this->numeClient != nullptr){
            return this->numeClient;
        }
        else{
            return "";
        }
    }
    float getDiscountNou(){
        return this->discount;
    }
    bool getLivrataNou(){
        return this->livrata;
    }
    friend ostream& operator<<(ostream& out, const Comanda& c){
        out << c.idComanda << endl;
        out << (c.numeClient != nullptr ? c.numeClient : "") << endl << c.magazin << endl << c.nrProduse << endl;
        for (int i=0; i<c.nrProduse; i++){
            out << c.cantitati[i] << "; ";
        }
        out << endl;
        for (int i=0; i<c.nrProduse; i++){
            out << c.preturi[i] << "; ";
        }
        out << endl;
        out << c.discount << endl << c.livrata << endl;
        out << c.taxaLivrare << endl;
        return out;
    }
    float calculeazaTotal(){
        float sumacant = 0;
        float disc;
        float sumaTotala = 0;
        if (nrProduse > 0){
            for (int i=0; i<this->nrProduse; i++){
                sumacant += this->cantitati[i]*this->preturi[i];
            }
            disc = this->discount/100;
            sumaTotala = sumacant * (1 - this->discount/100) + this->taxaLivrare;

        }   
        else if (nrProduse <= 0){
            sumaTotala = 0;
        }
        return sumaTotala;
    }
};
float Comanda::taxaLivrare = 15.0f;
int main(){
    Comanda c1;
    cout << c1;
    int cantitati[] = {12, 2, 5};
    float preturi[] = {12.99, 20, 17.99};
    Comanda c2(100, "Marian", "Mobex", 3, cantitati, preturi, true, 12.99);
    cout << c2;
    Comanda c3(c2);
    cout << c3;
    c3 = c2;
    c1.setNumeClientNou ("Stefi");
    cout << "Numele noului client din prima comanda este: " << c1.getNumeClientNou() << endl;
    c1.setDiscountNou(20);
    cout << "Discountul nou din prima comanda este: " << c1.getDiscountNou() << endl;
    c1.setLivrataNou(true); 
    cout << "Prima comanda este sau nu livrata: " << c1.getLivrataNou() << endl;
    cout << "Totalul pentru a treia comanda este: " << c3.calculeazaTotal() << endl;
    return 0;


}