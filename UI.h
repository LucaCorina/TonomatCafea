#pragma once
#include "ServiceTonomat.h"
#include<cstring>
class UI {
private:
    ServiceTonomat service;
    void displayMenu();
    void uiAddEntitate();
    void uiUpdateEntitatiById();
    void uiDeleteEntitateById();
    void uiShowEntitati();
    void uiArataRest();
    void add_once();
    void uiTranzactie();
    void modificaSumaTonomat();
    void uiShowEntitati1();
    int isnumber(const string &s);

public:
    UI();
    UI(ServiceTonomat& service);
    ~UI();
    void runMenu();
};

using namespace std;

void UI::displayMenu()
{
    cout<<"************MENIU COFFEE************"<<endl;
    cout<< "I.   COD:32 ---5 lei ---Expresso"<<endl;
    cout<< "II.  COD:43 ---12 lei---Cinnamon cafe latte"<<endl;
    cout<< "III. COD:654---12 lei---Ice coffee"<<endl;
    cout<< "IV.  COD:123---15 lei---Italian coffee"<<endl;
    cout<< "V.   COD:89 ---11 lei---Irish coffee"<<endl;
    cout<< "VI.  COD:43 ---10 lei---Mochaccino "<<endl;
    cout<< "VII. COD:42 ---20 lei---MINT CAFÉ LATTE"<<endl;
    cout<< "VIII.COD:54 ---13 lei---Coconut cafe latte"<<endl;
    cout<<endl<<endl;
    cout<<"************CRUD**************"<<endl;
    cout << "TONOMATU NU ARE BANI LA INCEPUTU PROGRAMULUI!"<<endl;
    cout << "1. Adauga cafea (personalizata :) " << endl;
    cout << "2. Modifica cafea :)" << endl;
    cout<<  "3. Sterge cafea dupa id :)"<<endl;
    cout<< "4. Show all cafele-->meniu"<<endl;
    cout<< "5. Modifica suma tonomat (acesta nu are bani)"<<endl;
    cout<< "6. Realizeaza tranzactie cu ajutorul meniului"<<endl;
    cout<<endl;
    cout << "a. Afiseaza toate cafelele personalizate"<<endl;
    cout << "x. Iesire" << endl;
    cout<<"**************************************************************"<<endl;
}

void UI::uiAddEntitate()
{try{
        cout<<"\ngimme parametrii pt add\n";
        string i;
        string pret;
        string nume;
        cout<<"Dati id: "<<endl;
        cin>>i;
        if (!isnumber(i))throw Exceptie("ATENTIE!! Id ul trebuie sa fie int!");
        cout<<"Dati suma introdusa "<<endl;
        cin>>pret;
        if (!isnumber(pret))throw Exceptie("ATENTIE!! Pretul trebuie sa fie int!");
        cout<<"Dati numele cafelei "<<endl;
        cin>>nume;
        if(isnumber(nume)==1)throw Exceptie("ATENTIE!! Numele nu trebuie sa fie int!");
        this->service.addEntitate(stoi(i),stoi(pret),nume);}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}
}

int UI:: isnumber(const string &s){
    for(char c:s)
    {if(!isdigit(c)){return 0;}}
    return 1;
}

void UI::uiUpdateEntitatiById()
{   try {
        cout << "\nDati id pt update si parametrii aferenti\n";
        string  pret;
        int id;
        string nume;
        cout << "Dati id: " << endl;
        cin >> id;
        if (!this->service.indcheck(id)) {
            cout << "\nNu exista entitate cu id-ul acesta";
            cout << endl;
        }
        else {
            cout << "Dati pretul nou " << endl;
            cin >> pret;
            if (!isnumber(pret))throw Exceptie("ATENTIE!! Pretul trebuie sa fie int!");
            cout << "Dati numele produsului nou: " << endl;
            cin >> nume;
            if(isnumber(nume)==1)throw Exceptie("ATENTIE!! Numele nu trebuie sa fie int!");

            this->service.updateEntitateById(id, stoi(pret), nume);
        }}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}
}

void UI::uiArataRest() {
    cout<<"Se da restul in monezi "<<endl;
}

void UI::uiDeleteEntitateById(){
    try{
    int id;
    cout<<"Dati id care se sterge";
    cin>>id;
    if(!this->service.indcheck(id)) {cout<<"\nNu exista entitate cu id-ul acesta";
    cout<<endl;}
    else
    this->service.deleteEntitateById(id);}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}

};

void UI::uiShowEntitati()
{
    vector<TonomatCafea> entitati = this->service.getAll();
    for (int i = 0; i < entitati.size(); i++)
    {
        cout << entitati[i];
    }
}
void UI::uiShowEntitati1()
{
    vector<TonomatCafea> entitati = this->service.getAll();
    for (int i = 8; i < entitati.size(); i++)
    {
        cout << entitati[i];
    }
}

void UI::add_once() {
    string nume1="Expresso",nume2="CinnamonCafeLatte",nume3="IceCoffee",nume4="ItalianCoffee",
            nume5="IrishCoffee",nume6="Mochaccino",nume7="MintCafeLatte",nume8="CoconutCafeLatte";

    this->service.addEntitate(32,5,nume1);
    this->service.addEntitate(43,12,nume2);
    this->service.addEntitate(654,12,nume3);
    this->service.addEntitate(123,15,nume4);
    this->service.addEntitate(89,11,nume5);
    this->service.addEntitate(43,10,nume6);
    this->service.addEntitate(42,20,nume7);
    this->service.addEntitate(54,13,nume8);

}

void UI::modificaSumaTonomat() {
    try{
    int suma;
    cout<<"\nSuma data pt Tonomat: ";
    cin>>suma;
    if(suma<=0)throw Exceptie("ATENTIE!! Suma trebuie sa fie strict pozitiva!");
    ServiceTonomat::sumaTonomat = suma;}
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}
}

void UI::uiTranzactie() {
    int id, suma, rest;
    cout<<"\nId cafea care se cumpara: ";
    while(true) {
        cin >> id;
        if(!this->service.indcheck(id)) {cout<<"\nNu exista entitate cu id-ul dat";}
        else{break;}
    }
    cout<<"\nSuma data: ";
    cin>>suma;
    if (suma<=0)throw Exceptie("Suma trebuie sa fie strict pozitiva!!");
    try{rest = this->service.realizeaza_tranzactie(id, suma);
        printf("Tranzactie realizata cu succes, suma data = %d, rest = %d", suma, rest);
    cout<<endl;
    }
    //, new suma tonomat= %d  ServiceTonomat::sumaTonomat
    catch(Exceptie& e) {printf("\n%s\n", e.getMessage().c_str());}
}

UI::UI()
{
}

UI::UI(ServiceTonomat& service)
{
    this->service = service;
}

UI::~UI()
{
}

void UI::runMenu()
{
    add_once();
    char cmd[20];
    while (true) {
        this->displayMenu();
        cin >> cmd;

        if (strcmp(cmd, "1") == 0)
        {
            this->uiAddEntitate();
        }
        else if (strcmp(cmd, "2") == 0)
        {
            this->uiUpdateEntitatiById();
        }
        else if (strcmp(cmd,"3")==0)
        {
            this->uiDeleteEntitateById();
        }
        else if (strcmp(cmd, "4")==0)
        {
            this->uiShowEntitati();
        }
        else if (strcmp(cmd, "5")==0)
        {
            this->modificaSumaTonomat();
        }
        else if (strcmp(cmd, "6")==0)
        {
            this->uiTranzactie();
        }
        else if (strcmp(cmd, "a") == 0)
        {
            this->uiShowEntitati1();
        }
        else if (strcmp(cmd, "x") == 0)
        {
            return;
        }
        else {
            cout << "Optiune gresita, reincercati! ";
        }
    }
}
