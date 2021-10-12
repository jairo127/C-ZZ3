#ifndef __ZZ3_CPP2_NUAGE__
#define __ZZ3_CPP2_NUAGE__

#include <vector>
#include "cartesien.hpp"
#include "polaire.hpp"

template <typename T>
class Nuage {
    private:
        std::vector<T> v;
    
    public:
        using const_iterator = typename std::vector<T>::const_iterator;

        Nuage();
        void ajouter(T);
        int size();
        const_iterator begin();
        const_iterator end();
};

template <typename T>
Nuage<T>::Nuage() {}

template <typename T>
void Nuage<T>::ajouter(T obj) {
    v.push_back(obj);
}

template <typename T>
int Nuage<T>::size() {
    return v.size();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() {
    return v.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() {
    return v.end();
}

template <typename T>
T barycentre_v1(Nuage<T> n) {
    int n_size = n.size();
    double sum_x = 0;
    double sum_y = 0;
    Cartesien c;
    
    typename Nuage<T>::const_iterator it = n.begin();
    while (it != n.end()) {
        (*it).convertir(c);
        sum_x += c.getX();
        sum_y += c.getY();
        it++;
    }

    if (n_size == 0) n_size = 1;

    return T(Cartesien(sum_x/n_size, sum_y/n_size));
}

/* SPECIALIZATION OF BARYCENTER FOR POLAR COORDINATES
template <>
Polaire barycentre_v1<Polaire>(Nuage<Polaire> n) {
    int n_size = n.size();
    double sum_x = 0;
    double sum_y = 0;
    Cartesien c;
    
    typename Nuage<Polaire>::const_iterator it = n.begin();
    while (it != n.end()) {
        (*it).convertir(c);
        sum_x += c.getX();
        sum_y += c.getY();
        it++;
    }

    if (n_size == 0) n_size = 1;

    return Polaire(Cartesien(sum_x/n_size, sum_y/n_size));
}*/

#endif