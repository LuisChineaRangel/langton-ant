#include "../include/universo.hpp"

int main (void) {
    Universo via_lactea;

    via_lactea.get_mundo() -> set_hormiga(0, 0);

    std::cout << via_lactea << std::endl;

    via_lactea.controlar_tiempo(1000);

    return 0;
}