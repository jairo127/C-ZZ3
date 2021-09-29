#include "polaire.hpp"
#include "cartesien.hpp"

Polaire::Polaire() : _a(0), _d(0) {}

Polaire::Polaire(const double a, const double d) : _a(a), _d(d) {}

void Polaire::afficher(std::ostream& stream) const {
    stream << "(a=" << _a << ";d=" << _d << ")";
}

void Polaire::convertir(Polaire& p) const {
    p.setAngle(_a);
    p.setDistance(_d);
}

void Polaire::convertir(Cartesien& c) const {
    c.setX(_d * cos(_a*3.14159/180));
    c.setY(_d * sin(_a*3.14159/180));
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