#include "vecteur.hpp"

Vecteur::Vecteur() :
_tab(new int[10]), _size(0), _capacity(10) {}

Vecteur::Vecteur(int const i) :
_tab(new int[i]), _size(0), _capacity(i) {}

Vecteur::~Vecteur() {
    delete [] _tab;
}

Vecteur::Vecteur(Vecteur const & v) : 
_tab(new int[v.capacity()]), _size(v.size()), _capacity(v.capacity()) {
    memcpy(_tab, v._tab, sizeof(int)*size());
}

Vecteur& Vecteur::operator=(Vecteur const & v) {
    if (&v != this)
    {
        _capacity = v.capacity();
        _size = v.size();
        _tab = new int[_capacity];
        delete [] _tab;
        memcpy(_tab, v._tab, sizeof(int)*size());
    }
    return *this;
}

int& Vecteur::operator[](int const i) {
    if(i > capacity() || i < 0)
        throw std::out_of_range("Index out of range");
    return _tab[i];
}

int Vecteur::operator[](int const i) const {
    if(i > capacity() || i < 0)
        throw std::out_of_range("Index out of range");
    return _tab[i];
}

std::ostream& operator<<(std::ostream & os, Vecteur const & v) {
    for(int i = 0; i < v.size(); i++)
    {
        os << v[i] << " ";
    }
    os << std::endl;
    return os;
}

int Vecteur::capacity() const {
    return _capacity;
}

int Vecteur::size() const {
    return _size;
}

void Vecteur::push_back(int const val) {
    if(size() == capacity()) // realloc
    {
        int * tab = new int[capacity()+5];
        memcpy(tab, _tab, sizeof(int)*capacity());
        delete [] _tab;
        _capacity += 5;
        _tab = tab;
    }
    _tab[size()] = val;
    _size++;
}

Vecteur Vecteur::operator+(const Vecteur& right) {
    Vecteur v(this->capacity()+right.capacity());
    std::copy(this->_tab, this->_tab+this->size(), v._tab);
    v._size += this->size();
    std::copy(right._tab, right._tab+right.size(), v._tab+v.size());
    v._size += right.size();
    return v;
}

int Vecteur::operator*(const Vecteur& right) {
    if (this->size() != right.size())
        throw std::exception();
    
    int sum = 0;
    for (int i = 0; i<right.size(); i++) {
        sum += (*this)[i] * right[i];
    }
    return sum;
}

Vecteur::Iterateur::Iterateur(int * valeur) : _valeur(valeur) {}

Vecteur::Iterateur& Vecteur::Iterateur::operator++() {
    _valeur++;
    return *this;
}

Vecteur::Iterateur Vecteur::Iterateur::operator++(int i) {
    _valeur += i;
    return *this;
}

int Vecteur::Iterateur::operator*() {
    return *_valeur;
}

bool Vecteur::Iterateur::operator==(const Iterateur& right) {
    if (this->_valeur == right._valeur)
        return true;
    return false;
}

Vecteur::Iterateur Vecteur::begin() {
    return Iterateur(this->_tab);
}

Vecteur::Iterateur Vecteur::end() {
    return Iterateur(this->_tab+_size-1);
}