#ifndef __ZZ3_CPP4_USINECARTE__
#define __ZZ3_CPP4_USINECARTE__

#include "carte.hpp"

class UsineCarte {
    private:
        int max_carte;
        int next_carte;
    
    public:
        UsineCarte(int nb_carte = 52) : max_carte(nb_carte), next_carte(0) {}
        UsineCarte(UsineCarte & u) = delete;
        UsineCarte & operator=(UsineCarte & u) = delete;

        Carte* getCarte() {
            if (next_carte >= 0 && next_carte < max_carte)
                return new Carte((next_carte++));
            else
                return nullptr;
        }
};

#endif