#include "../include/universo.hpp"

void crear_big_bang(Universo&, char&);

int main (void) {
    char opcion;
    Universo via_lactea;

    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << via_lactea << std::endl;

    while (opcion != 'q') {
        crear_big_bang(via_lactea, opcion);

        if (via_lactea.get_mundo())
            via_lactea.controlar_tiempo(100);

        std::cout << "-----------------------------------------------------------------------" << std::endl;
        std::cout << "¡DESTRUYAMOS ESTE UNIVERSO!" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
    }

    return 0;
}

void crear_big_bang(Universo& universo, char& opcion) {
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "Creemos el BIG BANG, ¿que tipo de universo desea? [F]inito / [I]nfinito" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "Introduzca su opción: ";
    std::cin >> opcion;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    switch(opcion) {
        case 'F':
            universo.set_mundo(new MundoFinito(20, 20));
            break;
        case 'I':
            universo.set_mundo(new MundoInfinito(FILAS_MIN, FILAS_MAX, COLUMNAS_MIN, COLUMNAS_MAX));
            break;
        case 'q':
            break;
        default:
            std::cout << "No existe ese tipo de mundo... todavía" << std::endl;
            break;
    }
}