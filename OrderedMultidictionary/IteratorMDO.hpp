#pragma once

#include "MDO.hpp"


class IteratorMDO {
    friend class MDO;
private:

    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    IteratorMDO(const MDO& dictionar);

    //contine o referinta catre containerul pe care il itereaza
    const MDO& dict;
    
    //locatia curenta din tabela
    int curent;
    vector<TElem> ordonat;  //retinem elementele tabelei de dispersie intr-un vector de tip TElement
    Relatie relatie;

    //deplasare iterator pe o pozitie care e ocupata (nu are memorat NIL)
    void deplasare();

    bool relatieIndici(int a, int b);


public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElem element() const;
};
