#include "cartesien.hpp"

Cartesien::Cartesien() : _x(0), _y(0) {}

Cartesien::Cartesien(const double x, const double y) : _x(x), _y(y) {}

void Cartesien::afficher(std::ostream& stream) const {
    stream << "(x=" << _x << ";y=" << _y << ")";
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