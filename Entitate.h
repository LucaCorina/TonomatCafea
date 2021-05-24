#pragma once
#include "Exceptie.h"

using namespace std;

class Entitate {
protected:
    int id_entitate;
public:
    Entitate();
    explicit Entitate(int);
    int get_id() const;
};

Entitate::Entitate() {
    this->id_entitate = 0;
}

Entitate::Entitate(int id) {
    this->id_entitate = id;
}

int Entitate::get_id() const {
    return this->id_entitate;
}