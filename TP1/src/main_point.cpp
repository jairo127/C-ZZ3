#include <cstdlib>
#include <vector>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

int main() {
    std::vector<Point *> pts_pointer;

    int j = 0;
    for (int i=0; i<10; i++) {
        pts_pointer.push_back(new Cartesien(i, j));
        pts_pointer.push_back(new Polaire(i, j));
        j++;
    }

    for (long unsigned i=0; i<pts_pointer.size(); i++) {
        pts_pointer[i]->afficher(std::cout);
    }

    return EXIT_SUCCESS;
}
