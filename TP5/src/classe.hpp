#ifndef __CPP5_ZZ3_CLASSE__
#define __CPP5_ZZ3_CLASSE__

class Classe {
    private:
        double _inf;
        double _sup;
        unsigned int _quantite;
    
    public:
        Classe(const double inf, const double sup) : _inf(inf), _sup(sup), _quantite(0u) {}

        double getBorneInf() const { return _inf; }
        void setBorneInf(const double inf) { _inf = inf; }
        double getBorneSup() const { return _sup; }
        void setBorneSup(const double sup) { _sup = sup; }
        unsigned int getQuantite() const { return _quantite; }
        void setQuantite(unsigned int quantite) { _quantite = quantite; }
        void ajouter() { _quantite++; }

        bool operator<(Classe const & r) const {
            return this->getQuantite() < r.getQuantite();
        }
};

#endif