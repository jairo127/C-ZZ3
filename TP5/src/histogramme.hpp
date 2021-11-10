#ifndef __CPP5_ZZ3_HISTOGRAMME__
#define __CPP5_ZZ3_HISTOGRAMME__

#include <vector>
#include <set>
#include <algorithm>
#include <classe.hpp>
#include <echantillon.hpp>
#include <valeur.hpp>

class Histogramme {
    private:
        std::set<Classe> _classes;

    public:
        Histogramme(const double inf, const double sup, const int nb) {
            double delta = (sup - inf) / nb;
            double tmp_inf = inf;
            double tmp_sup = tmp_inf + delta;
            for(int i = 0; i < nb; i++) {
                _classes.push_back(Classe(tmp_inf, tmp_sup));
                tmp_inf = tmp_sup;
                tmp_sup = tmp_inf + delta;
            }
        }

        std::set<Classe> getClasses() { return _classes; }

        void ajouter(const Echantillon e) {
            for(unsigned int i = 0; i < e.getTaille(); i++) {
                Valeur v = e.getValeur(i);
                for(unsigned int j = 0; j < _classes.size(); j++) {
                    if (v.getNombre() >= _classes[j].getBorneInf() && 
                        v.getNombre() < _classes[j].getBorneSup()) {
                            Classe tmp = _classes[j];
                            tmp.ajouter();
                            std::erase();
                            break;
                    }
                }
            }

        }
};

#endif