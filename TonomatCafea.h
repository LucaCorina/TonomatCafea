#pragma once
#include "RepoT.h"
#include "Entitate.h"
using namespace std;

class TonomatCafea: public Entitate{
private:
    int pret;
    string nume;
public:;
    TonomatCafea()=default;
    TonomatCafea(int id, int pret, string& nume);
    TonomatCafea(const TonomatCafea& g);
    ~TonomatCafea()=default;
    int getPret();
    string getNume();
    void set_pret(int pret);
    void set_nume(string nume);
    void set_id(int id);

    TonomatCafea& operator=(const TonomatCafea& sb);
    bool operator==(const TonomatCafea& sb);
    friend istream& operator>>(istream& is, TonomatCafea& sb);
    friend ostream& operator<<(ostream& os, TonomatCafea& sb);


};


TonomatCafea::TonomatCafea(int id , int pret, string& nume)
{
    this->id_entitate=id;
    this->pret=pret;
    this->nume = nume;
}

TonomatCafea::TonomatCafea(const TonomatCafea& g) : Entitate(g)
{
    this->id_entitate=g.id_entitate;
    this->pret=g.pret;
    this->nume = g.nume;

}
string TonomatCafea::getNume()
{
    return this->nume;
}
void TonomatCafea::set_nume(string nume) {
    this->nume = nume;
}
void TonomatCafea::set_pret(int pret)
{
    this->pret = pret;
}
int TonomatCafea::getPret()
{
    return this->pret;
}

TonomatCafea& TonomatCafea::operator=(const TonomatCafea& g)
{
    Entitate::operator=(g);
    this->nume = g.nume;
    this->pret=g.pret;
    return *this;
}

bool TonomatCafea::operator==(const TonomatCafea& g)
{
    return this->nume == g.nume && this->pret == g.pret ;
}

istream& operator>>(istream& is, TonomatCafea& g)
{
    int id;
    int pret;
    string nume;
    if (&is == &cin)
    {   cout<<"Dati id-ul";
        cout<<"Dati pretul";
        cout << "Dati numele: ";


    }
    is >>id>>pret>>nume;
    g.set_nume(nume);
    g.set_pret(pret);
    return is;
}

ostream& operator<<(ostream& os, TonomatCafea& g)
{
    os << g.id_entitate<< " " << g.pret << " "<<g.nume<<"\n";
    return os;
}

