#ifndef __ZZ3_CPP1_VECTEUR__
#define __ZZ3_CPP1_VECTEUR__
#include <iostream>
#include <cstring>
#include <exception>

class Vecteur {
    private:
        int * _tab;
        int _size;
        int _capacity;

    public:
        Vecteur();
        Vecteur(int const i);
        ~Vecteur();
        Vecteur(Vecteur const & v);

        Vecteur& operator=(Vecteur const & v);
        int& operator[](int const i);
        int operator[](int const i) const;
        friend std::ostream& operator<<(std::ostream & os, Vecteur const & v);
        Vecteur operator+(const Vecteur&);
        int operator*(const Vecteur&);

        int capacity() const;
        int size() const;
        void push_back(int const val);
};

#endif