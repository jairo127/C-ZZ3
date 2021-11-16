#ifndef __CPP5_ZZ3_CLASSE__
#define __CPP5_ZZ3_CLASSE__

class Classe {
    private:
        double _inf;
        double _sup;
        unsigned int _quantite;
    
    public:
        Classe(const double inf = 0, const double sup = 0) : _inf(inf), _sup(sup), _quantite(0u) {}

        double getBorneInf() const { return _inf; }
        void setBorneInf(const double inf) { _inf = inf; }
        double getBorneSup() const { return _sup; }
        void setBorneSup(const double sup) { _sup = sup; }
        unsigned int getQuantite() const { return _quantite; }
        void setQuantite(unsigned int quantite) { _quantite = quantite; }
        bool is_in(const double value) const { return (value >= _inf && value < _sup); }
        void ajouter() { _quantite++; }

        bool operator<(Classe const & r) const {
            return this->getBorneInf() < r.getBorneInf();
        }

        bool operator>(Classe const & r) const {
            return this->getBorneInf() > r.getBorneInf();
        }
};

#endif