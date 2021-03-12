#pragma once

#define MAX 17 //numarul maxim de locatii din tabela
#include <vector>

#define NULL_TCHEIE 0

typedef int TCheie;  // Tcheie va fi considerata de tip intreg, fapt care nu va afecta generalitatea implementarii
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;  //definim tipul TElement, adica o pereche de tipul (cheie, valoare)


using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

/*
 Avem de implementat un Tip Abstract de Date, si anume Multidictionar Ordonat, cu reprezentare sub forma unei Tabele de Dispersie cu rezolvarea coliziunilor prin liste independente.
 */
class MDO {
    friend class IteratorMDO;
private:
    int m; //numarul de locatii din tabela de dispersie
    vector< vector<TElem> > elems; //forma tabelei de dispersie 
    int lg;  //lungimea dictionarului (numarul de TElemente din tabela)

    //functia de dispersie extinsa
    int d(TCheie e) const;

    Relatie relatie;
public:

    // constructorul implicit al MultiDictionarului Ordonat
    MDO(Relatie r);

    // adauga o pereche (cheie, valoare) in MDO
    void adauga(TCheie c, TValoare v);

    //cauta o cheie si returneaza vectorul de valori asociate
    vector<TValoare> cauta(TCheie c) const;

    //sterge o cheie si o valoare
    //returneaza adevarat daca s-a gasit cheia si valoarea de sters
    bool sterge(TCheie c, TValoare v);

    //returneaza numarul de perechi (cheie, valoare) din MDO
    int dim() const;

    //verifica daca MultiDictionarul Ordonat e vid
    bool vid() const;

    // se returneaza iterator pe MDO
    // iteratorul va returna perechile in ordine in raport cu relatia de ordine
    IteratorMDO iterator() const;

    // destructorul
    ~MDO();
    
    // găsește și returnează cheia maximă a multidicționarului
    // Dacă  multidicționarul este vid, se returnează NULL_TCHEIE
    TCheie cheieMaxima() const;


};
