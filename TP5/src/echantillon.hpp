#ifndef __CPP5_ZZ3_ECHANTILLON__
#define __CPP5_ZZ3_ECHANTILLON__

#include <iostream>
#include <vector>
#include <algorithm>
#include <valeur.hpp>
#include <exception>

class Echantillon {
    private:
        std::vector<Valeur> _valeurs;
    
    public:
        Echantillon() {}

        Echantillon(double v) : _valeurs(std::vector<Valeur>(1)) {
			_valeurs.push_back(Valeur(v));
		}

        unsigned int getTaille() const {
            return _valeurs.size();
        }

        void ajouter(const double valeur) {
            _valeurs.push_back(Valeur(valeur));
        }

        Valeur getMinimum() const {
            if (getTaille() == 0)
                throw std::domain_error("Vector is empty");
            return *(std::min_element(_valeurs.begin(), _valeurs.end()));
        }

        Valeur getMaximum() const {
            if (getTaille() == 0)
                throw std::domain_error("Vector is empty");
            return *(std::max_element(_valeurs.begin(), _valeurs.end()));
        }

        Valeur getValeur(unsigned int indice) const {
            if (indice >= getTaille())
                throw std::out_of_range("Indice is out of range");
            return _valeurs[indice];
        }

        auto const & getValeurs() const{
			return _valeurs;
		}
};

std::ostream & operator<<(std::ostream & o, Echantillon const & e){
	auto v = e.getValeurs();
	o << "Echantillon = ";
	std::for_each(v.begin(), v.end(),
		[&o](Valeur const v) mutable {
			o << v << " ";
		}
	);
	return o;
}

#endif