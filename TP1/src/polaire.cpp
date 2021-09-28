#include "polaire.hpp"

Polaire::Polaire() : _a(0), _d(0) {}

Polaire::Polaire(const double a, const double d) : _a(a), _d(d) {}

void Polaire::afficher(std::ostream& stream) const {
    stream << "(a=" << _a << ";d=" << _d << ")";
}

void Polaire::convertir(Cartesien& c) const {
    c.setX(_a * cos(_d));
    c.setY(_a * sin(_d));
}

void Polaire::setAngle(const double a) {
    _a = a;
}

void Polaire::setDistance(const double d) {
    _d = d;
}

double Polaire::getAngle() const{
    return _a;
}

double Polaire::getDistance() const{
    return _d;
}