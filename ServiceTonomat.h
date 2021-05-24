#pragma once
#include "TonomatCafea.h"

class ServiceTonomat {
private:
    RepoSTLTemplate<TonomatCafea> repo;
public:
    inline static int sumaTonomat;
    ServiceTonomat() = default;
    ServiceTonomat(RepoSTLTemplate<TonomatCafea>& repo);
    ~ServiceTonomat();

    int indcheck(int i);
    void setRepo(RepoSTLTemplate<TonomatCafea>& repo);

    vector<TonomatCafea> getAll();
    RepoSTLTemplate<TonomatCafea> returnrepo();
    void addEntitate(int, int, string&);
    void updateEntitateById(int, int,string&);
    void deleteEntitateById(int);
    int realizeaza_tranzactie(int id, int suma);
};

RepoSTLTemplate<TonomatCafea> ServiceTonomat::returnrepo()
{
    return repo;
}

ServiceTonomat::ServiceTonomat(RepoSTLTemplate<TonomatCafea>& repo)
{
    this->repo = repo;
}

ServiceTonomat::~ServiceTonomat()
{
}

void ServiceTonomat::setRepo(RepoSTLTemplate<TonomatCafea>& repo)
{
    this->repo = repo;
}

vector<TonomatCafea> ServiceTonomat::getAll()
{
    return this->repo.getAll();
}

void ServiceTonomat::addEntitate(int i, int pret,  string& nume)
{
    TonomatCafea t(i, pret,nume);
    this->repo.addElem(t);
}

void ServiceTonomat::updateEntitateById(int id,  int pret,  string& nume) {
    TonomatCafea t(id,pret, nume);
    this->repo.updateElem(t);
}

void ServiceTonomat::deleteEntitateById(int id){
//    if(id<=0){throw(Exceptie("\nId-ul trebbuie sa fie pozitiv!\n"));}
    repo.deleteElem(id);
}

int ServiceTonomat::realizeaza_tranzactie(int id, int suma)
{
    TonomatCafea tC = this->repo.findbyid(id);

    if(suma < tC.getPret()) {throw(Exceptie("\nSuma data < pretul cafelei\n"));}

    else if(suma - tC.getPret() > sumaTonomat) {throw(Exceptie("\nNu pot sa dau rest"));}

    else if(suma == tC.getPret()) {sumaTonomat+=suma; return 0;}

    else if(suma > tC.getPret()) {sumaTonomat+=suma; return suma-tC.getPret();}

}

int ServiceTonomat::indcheck(int i) {
    return this->repo.checkIDexists(i);
}
