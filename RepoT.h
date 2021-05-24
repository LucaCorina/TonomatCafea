#pragma once
#include <fstream>
#include <utility>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <windows.h>
#include <ostream>
#include <cstring>
#include"Exceptie.h"
using namespace std;

template <class T>
class RepoSTLTemplate {
private:
    vector<T> elements;
    char* fileName;

public:
    RepoSTLTemplate();
    RepoSTLTemplate(const char* fileName);
    ~RepoSTLTemplate();


    char* getFileName();
    void setFileName(const char* fileName);

    vector<T> getAll();
    int getSize();

    void addElem(const T&);
    void updateElem(const T&);
    void deleteElem(int);
    T findbyid(int );
    // private:
    void loadFromFile();
    void saveToFile();
    int checkIDexists(int);
};

template <class T>
RepoSTLTemplate<T>::RepoSTLTemplate()
{
    this->fileName = NULL;
}

template <class T>
RepoSTLTemplate<T>::RepoSTLTemplate(const char* fileName)
{
    if (this->fileName != NULL)
    {
        this->fileName = new char[strlen(fileName) + 1];
        strcpy_s(this->fileName, strlen(fileName) + 1, fileName);

        this->loadFromFile();
    }
}

template <class T>
RepoSTLTemplate<T>::~RepoSTLTemplate()
{
    this->elements.clear();
    if (this->fileName != NULL)
    {
        delete[] this->fileName;
    }
}

template <class T>
char* RepoSTLTemplate<T>::getFileName()
{
    return this->fileName;
}

template <class T>
void RepoSTLTemplate<T>::setFileName(const char* fileName)
{
    if (this->fileName != NULL)
    {
        delete[] this->fileName;
    }
    this->fileName = new char[strlen(fileName) + 1];
    strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
}

template <class T>
void RepoSTLTemplate<T>::addElem(const T& elem)
{
    this->elements.push_back(elem);
    this->saveToFile();

}

template <class T>
void RepoSTLTemplate<T>::updateElem(const T& element)
{
    for (auto& elem:elements)
    {
        if (elem.get_id() == element.get_id()) { elem = element; }
    }
    this->saveToFile();

}


template <class T>
void RepoSTLTemplate<T>::deleteElem(int id)
{
    for(int i=0; i<this->getSize(); i++)
    {
        if(elements[i].get_id()==id)
        {
            elements.erase(elements.begin()+i);
        }
    }
    this->saveToFile();

}
template <class T>
T RepoSTLTemplate<T>::findbyid(int j)
{
    for (int i = 0; i < this->elements.size(); i++)
        if(elements[i].get_id() == j)
            return elements[i];
}
// finbyid(1).getPret()

template <class T>
void RepoSTLTemplate<T>::saveToFile()
{
    if (this->fileName != NULL)
    {
        ofstream f(this->fileName);
        for (int i = 0; i < this->elements.size(); i++)
        {
            f << this->elements[i] << endl;
        }
        f.close();
    }
}

template <class T>
vector<T> RepoSTLTemplate<T>::getAll()
{
    return this->elements;
}

template <class T>
int RepoSTLTemplate<T>::getSize()
{
    return this->elements.size();
}


template<class T>
void RepoSTLTemplate<T>::loadFromFile()
{
    if (this->fileName != NULL)
    {
        this->elements.clear();
        ifstream f(this->fileName);
        T t;
        while (f >> t)
        {
            this->elements.push_back(t);
        }
        f.close();
    }
}

template<class T>
int RepoSTLTemplate<T>::checkIDexists(int i) {
    for(auto e:elements)
    {if(e.get_id() == i) return 1;}
    return 0;
}
