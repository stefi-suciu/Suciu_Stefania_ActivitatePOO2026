#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class BiletAvion{
private:
    const int numarBilet;
    char* numePasager;
    int durataZbor;
    double* distante;
    int numarSegmente;
    static int contor;
public:
    BiletAvion(const char* numePasager, int durataZbor):numarBilet(contor++){
        if (numePasager != nullptr && strlen(numePasager) > 0){
            this->numePasager = new char[strlen(numePasager)+1];
            strcpy(this->numePasager, numePasager);
        }
        else{
            this->numePasager = new char [strlen("Necunoscut")+1];
            strcpy(this->numePasager, "Necunoscut");
        }
        if (durataZbor >= 0){
            this->durataZbor = durataZbor;
        }
        else{
            this->durataZbor = 0;
        }
        this->distante = nullptr;
        this->numarSegmente = 0;
    }

    BiletAvion(const BiletAvion& b):numarBilet(contor++){
        this->numePasager = new char [strlen(b.numePasager)+1];
        strcpy(this->numePasager, b.numePasager);

        this->durataZbor = b.durataZbor;
        this->numarSegmente = b.numarSegmente;

        this->distante = new double[this->numarSegmente];
        if (b.distante != nullptr && b.numarSegmente > 0){
            this->distante = new double[this->numarSegmente];

            for (int i=0; i<this->numarSegmente; i++){
                this->distante[i] = b.distante[i];
            }
        }
        else{
            this->distante = nullptr;
            this->numarSegmente = 0;
        }

    }
    //setter
    void setDistante(const double* distanteNoi, int numarNou){
        if (distanteNoi != nullptr || numarNou <= 0){
            return;
        }

        for (int i=0; i<numarNou; i++){
            if (distante[i] <= 0){
                return;
            }
        }

        double* copie = new double[numarNou];
        for (int i=0; i<numarNou; i++){
            copie[i] = distanteNoi[i];
        }
        delete[] this->distante;

        this->distante = copie;
        this->numarSegmente = numarNou;
    }

    BiletAvion& operator=(const BiletAvion& b){
        if (this != &b){
            this->durataZbor = b.durataZbor;
            delete[] this->numePasager;
            this->numePasager = new char[strlen(b.numePasager)+1];
            strcpy(this->numePasager, b.numePasager);

            double* copie = new double [b.numarSegmente];
            for (int i=0; i<b.numarSegmente; i++){
                copie[i] = b.distante[i];
            }
            delete[] this->distante;
            this->distante = copie;
            this->numarSegmente = b.numarSegmente;

        }
        return *this;

    }

    //operator<<:
    friend ostream& operator<<(ostream& out, const BiletAvion& b){
        out << b.numarBilet << " " << b.numePasager << " " << b.durataZbor << " " << b.numarSegmente << " ";
        for (int i=0; i<b.numarSegmente; i++){
            out << b.distante[i] << " ";
        }
        return out;
    }

    //operator>>:
    friend istream& operator>>(istream& in, BiletAvion& b){
        int durataNoua;
        char buffer[100];

        in >> durataNoua;
        in >> buffer;
        if (in && durataNoua >0 && strlen(buffer) > 0){
            char* nume = new char[strlen(buffer)+1];
            strcpy(nume, buffer);

            delete[] b.numePasager;
            b.numePasager = nume;
            b.durataZbor = durataNoua;
        }
        return in;
    }
    ~BiletAvion(){
        delete[] numePasager;
        delete[] distante;
    }
};

int BiletAvion::contor = 1;
