#include "IteratorMDO.hpp"
#include "MDO.hpp"
#include <algorithm>
#define NIL -1

//constructorul iteratorului
IteratorMDO::IteratorMDO(const MDO& d) : dict(d) {
    // O(n^2)
    curent = 0;  //curent va referi primul element din dictionarul ordonat

    for(int i = 0; i < d.m; i++){
        for(int j = 0; j < d.elems[i].size(); j++){  //punem toate elementele tabelei in vectorul ordonat
            ordonat.push_back(d.elems[i][j]);
        }
    }

    sort(ordonat.begin(), ordonat.end(), [&](const TElem &first,  //sortam vectorul ordonat (elementele dictionarului) dupa cheie
        const TElem &second){
        return d.relatie(first.first, second.first);
    });
}

void IteratorMDO::prim() {
    // Theta(1)
    //se determina prima locatie ocupata
    curent = 0;
}

void IteratorMDO::urmator(){
    // Theta(1)
    if(valid() == false){  //verificam daca pozitia e valida
        throw std::exception();
    }

    curent++;  //si ne mutam la urmatoarea pozitie 
}

bool IteratorMDO::valid() const {
    // Theta(1)
    return (curent < dict.dim()); //un element este valid daca nu am depasit lungimea dictionarului
}

TElem IteratorMDO::element() const {
    // Theta(1)
    return ordonat[curent];   //returnam elementul aflat la pozitia curent din vectorul ordonat 
}
