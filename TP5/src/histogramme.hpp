#ifndef __CPP5_ZZ3_HISTOGRAMME__
#define __CPP5_ZZ3_HISTOGRAMME__

#include <iostream>
#include <vector>
#include <set>
#include <map>
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

class CompareHetero{
	public:
		bool operator()(Classe const & c, std::pair<Classe,Valeur> const & p){
			return c.getBorneInf()<p.first.getBorneInf();
		}
		bool operator()(std::pair<Classe,Valeur> const & p, Classe const & c){
			return c.getBorneInf()>p.first.getBorneInf();
		}
};

template <class Compare = std::less<Classe>>
class Histogramme {

    using Container = std::set<Classe,Compare>;
	using HashMap = std::multimap<Classe,Valeur>;
	using PaireH = std::pair<Classe,Valeur>;

    private:
        Container _classes;
        HashMap _valeurs;

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

        template <class T>
        Histogramme(Histogramme<T> & histo) {
            for (auto classe : histo.getClasses())
                _classes.insert(classe);
        }

        Container const getClasses() const { return _classes; }

        HashMap const getValeurs() const { return _valeurs; }

        auto const getValeurs(Classe const & c) const {
			return std::equal_range(_valeurs.begin(), _valeurs.end(), c, CompareHetero{});;
		}

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
                    _valeurs.insert(PaireH(tmp, v));
                    tmp.ajouter();
                    _classes.insert(tmp);
                }
            }
        }
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Histogramme<T> const & histo) {
	auto classes = histo.getClasses();
	auto valeurs = histo.getValeurs();
	std::for_each(classes.begin(), classes.end(),
		[&o, &valeurs](Classe const & c) mutable {
			o << c << " : ";
			const auto p2 = std::equal_range(valeurs.begin(), valeurs.end(), c, CompareHetero{});
			for ( auto it = p2.first; it != p2.second; ++it )
				o << (*it).second << ' ';
			o << "\n";
		}
	);
	return o;
}

#endif