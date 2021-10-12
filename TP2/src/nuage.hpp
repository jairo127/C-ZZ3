#ifndef __ZZ3_CPP2_NUAGE__
#define __ZZ3_CPP2_NUAGE__

#include <iostream>
#include <vector>

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

#endif