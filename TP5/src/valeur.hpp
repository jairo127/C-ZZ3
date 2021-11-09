#ifndef __CPP5_ZZ3_VALEUR__
#define __CPP5_ZZ3_VALEUR__

class Valeur {
    private:
        double _valeur;

    public:
        Valeur(double valeur = 0) : _valeur(valeur) {}

        void setNombre(const double valeur) {
            _valeur = valeur;
        }

        double getNombre() const {
            return _valeur;
        }

        bool operator<(Valeur const & r) const {
            return this->getNombre() < r.getNombre();
        }
};

#endif