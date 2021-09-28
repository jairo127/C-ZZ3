#include "point.hpp"

std::ostream& operator<<(std::ostream& os, const Point& p) {
    p.afficher(os);
    return os;
}