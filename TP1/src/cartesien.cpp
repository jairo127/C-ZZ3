#include "cartesien.hpp"
#include "polaire.hpp"

Cartesien::Cartesien() : _x(0), _y(0) {}

Cartesien::Cartesien(const double x, const double y) : _x(x), _y(y) {}

void Cartesien::afficher(std::ostream& stream) const {
    stream << "(x=" << _x << ";y=" << _y << ")";
}

void Cartesien::convertir(Polaire& p) const {
    p.setAngle(std::atan2(_y,_x)*180/3.14159);
    p.setDistance(std::sqrt((_x*_x) + (_y*_y)));
}

void Cartesien::convertir(Cartesien& c) const {
    c.setX(_x);
    c.setY(_y);
}

void Cartesien::setX(const double x) {
    _x = x;
}

void Cartesien::setY(const double y) {
    _y = y;
}

double Cartesien::getX() const{
    return _x;
}

double Cartesien::getY() const{
    return _y;
}