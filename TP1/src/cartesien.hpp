#ifndef __ZZ3_CPP1_CARTESIEN__
#define __ZZ3_CPP1_CARTESIEN__
#include <iostream>
#include <cmath>
#include "point.hpp"
#include "polaire.hpp"

class Cartesien : public Point {
    private:
        double _x;
        double _y;
    
    public:
        Cartesien();
        Cartesien(const double, const double);
        void afficher(std::ostream&) const;
        void convertir(Polaire&) const;

        void setX(const double);
        void setY(const double);
        double getX() const;
        double getY() const;
};

#endif