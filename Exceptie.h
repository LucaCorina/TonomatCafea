#pragma once
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <Windows.h>
#include <random>
using namespace std;

class Exceptie : exception {
private:
    string msg_;
public:
    explicit Exceptie(string msg) : msg_(move(msg)) {}
    ~Exceptie() override = default;

    [[nodiscard]] string getMessage() const {return(msg_);}
};