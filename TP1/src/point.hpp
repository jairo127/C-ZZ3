#ifndef __ZZ3_CPP1_POINT__
#define __ZZ3_CPP1_POINT__
#include <iostream>

class Point {
    public:
        virtual void afficher(std::ostream&) const = 0;
        // virtual void convertir(Cartesien&) const;
        friend std::ostream& operator<<(std::ostream&, const Point&);
};

#endif