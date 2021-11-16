#ifndef __CPP5_ZZ3_HISTOGRAMME__
#define __CPP5_ZZ3_HISTOGRAMME__

#include <vector>
#include <set>
#include <algorithm>
#include <classe.hpp>
#include <echantillon.hpp>
#include <valeur.hpp>

template <typename t>
class ComparateurQuantite {
	public:
		bool operator()(Classe const & a, Classe const & b) const {
			return (a.getQuantite() > b.getQuantite()) || 
			 (a.getQuantite() == b.getQuantite() && a.getBorneInf() < b.getBorneInf());
		}
};

template <class Compare = std::less<Classe>>
class Histogramme {
    private:
        std::set<Classe, Compare> _classes;

    public:
        Histogramme(const double inf, const double sup, const int nb) {
            double delta = (sup - inf) / nb;
            double tmp_inf = inf;
            double tmp_sup = tmp_inf + delta;
            for(int i = 0; i < nb; i++) {
                _classes.insert(Classe(tmp_inf, tmp_sup));
                tmp_inf = tmp_sup;
                tmp_sup = tmp_inf + delta;
            }
        }

        std::set<Classe, Compare> getClasses() { return _classes; }

        void ajouter(const Echantillon e) {
            for(unsigned int i = 0; i < e.getTaille(); i++) {
                Valeur v = e.getValeur(i);
                auto it = std::find_if(
                    _classes.begin(), 
                    _classes.end(), 
                    [&v](const Classe & c) { 
                        return c.is_in(v.getNombre());
                    });
                if (it != _classes.end()) {
                    Classe tmp(*it);
                    _classes.erase(it);
                    tmp.ajouter();
                    _classes.insert(tmp);
                }
            }
        }
};

#endif