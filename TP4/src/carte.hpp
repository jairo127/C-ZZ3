#ifndef __ZZ3_CPP4_CARTE__
#define __ZZ3_CPP4_CARTE__

class Carte {
    private:
        int valeur;
        Carte(int i = 0) : valeur(i) {}
    
    public:
        Carte(Carte & c) = delete;
        Carte & operator=(Carte & c) = delete;

        int getValeur() {
            return valeur;
        }

        friend class UsineCarte;
};

#endif