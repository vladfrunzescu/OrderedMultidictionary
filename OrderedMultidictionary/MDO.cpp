#include "IteratorMDO.hpp"
#include "MDO.hpp"
#include <iostream>
#include <vector>
#include <math.h>

#include <exception>
using namespace std;

//constanta simbolica NIL indica o locatie libera in tabela
//consideram ca TElem este intreg
#define NIL -1

//functia care de <hasCode>-ul unui element
int hashCode(TCheie e) {
    return abs(e);
}

//functia de dispersie, o alegem pe cea %m care va avea valori intre 0 si m-1
int MDO::d(TCheie e) const{
    return hashCode(e) % m;
}

//constructorul clasei MDO
MDO::MDO(Relatie r) {
    m = MAX; //initializam m cu o valoare predefinita
    elems.resize(m); //construim vectorul corespunzator locatiilor hashcode-urilor cheilor
    relatie = r;  //definim relatia dintre elemente
    lg = 0;  //initializam lungimea dictionarului (la inceput nu contine niciun element)
}

//functia de adaugare
void MDO::adauga(TCheie c, TValoare v) {
    //complexitate Theta(1)
    TElem elem;  //construim perechea TElem atribuind cheia si valoarea
    elem.first = c;
    elem.second = v;
    int pos = d(c);  //determinam pozitia in tabela de dispersie in functie de hascode-ul asociat cheii
    elems[pos].push_back(elem); //adaugam in lista de pe pozitia asociata valorii de dispersie
    lg++;  //incrementam lungimea dictionarului
}

//cautare dupa cheie
vector<TValoare> MDO::cauta(TCheie c) const {
    //complexitate medie Theta(1)
    vector<TValoare> result; //lista rezultat in care vom retine valorile TElementelor coresp cheii
    int pos = d(c);  //determinam valoarea de dispersie

    for(int i = 0; i < elems[pos].size(); i++){  //parcurgem lista asociata valorii de dispersie
        if(elems[pos][i].first == c){  //daca cheile corespund
            result.push_back(elems[pos][i].second);  //retinem valorile
        }
    }

    return result;
}


//sterge un TElement
bool MDO::sterge(TCheie c, TValoare v) {
    //complexitate medie Theta(1)
    int pos = d(c); //determinam valoarea de dispersie
    
    for(int i = 0; i < elems[pos].size(); i++){  //parcurgem elementele liste asociate valorii
        if(elems[pos][i].first == c && elems[pos][i].second == v){  //daca am gasit un element cu cheie si valoarea corepunzatoare
            elems[pos].erase(elems[pos].begin() + i);  //il stergem
            lg--;  //decrementam lungimea dictionarului
            return true;
        }
    }

    return false;
}

//returneaza lungimea
int MDO::dim() const {
    // Theta(1)
    return lg;
}

//verifica daca dictionarul e vid
bool MDO::vid() const {
    // Theta(1)
    if (lg == 0) {
        return true;
    }
    return false;
}

IteratorMDO MDO::iterator() const {
    return IteratorMDO(*this);
}

MDO::~MDO() {
    // stergerea obiectului se realizeaza automat deoarece folosim vector din STL
}

//functionalitate noua
TCheie  MDO::cheieMaxima() const{
    TElem rez;
    IteratorMDO it1 = iterator();
    IteratorMDO it2 = iterator();
    if(vid())
        return NULL_TCHEIE;
    
    it2.prim();
    it2.urmator();
    it1.prim();
    
    while(it2.valid()){
        it2.urmator();
        it1.urmator();
    }
    
    rez=it1.element();
    return rez.first;
}

