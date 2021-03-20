#include "../include/universo.hpp"

void crear_big_bang(Universo&, std::list<Hormiga>, char&);

int main (void) {
    char opcion;
    Universo via_lactea;

    std::list<Hormiga> hormiguero;
    hormiguero.push_back(Hormiga(0, 0));
    hormiguero.push_back(Hormiga(0, 1));
    hormiguero.push_back(Hormiga(1, 0));
    hormiguero.push_back(Hormiga(2, 2));
    hormiguero.push_back(Hormiga(4, 6));
    hormiguero.push_back(Hormiga(9, 9));

    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << via_lactea << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    while (opcion != 'q') {
        crear_big_bang(via_lactea, hormiguero, opcion);
        std::cout << via_lactea << std::endl;

        if (via_lactea.get_mundo())
            via_lactea.controlar_tiempo(1000);

        std::cout << "-----------------------------------------------------------------------" << std::endl;
        std::cout << "¡DESTRUYAMOS ESTE UNIVERSO!" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
    }

    return 0;
}

void crear_big_bang(Universo& universo, std::list<Hormiga> hormiguero, char& opcion) {
    std::cout << "Creemos el BIG BANG, ¿que tipo de universo desea? [F]inito / [I]nfinito" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "Introduzca su opción: ";
    std::cin >> opcion;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    switch(opcion) {
        case 'F':
            universo.set_mundo(new MundoFinito(20, 20, hormiguero));
            break;
        case 'I':
            universo.set_mundo(new MundoInfinito(FILAS_MIN, FILAS_MAX, COLUMNAS_MIN, COLUMNAS_MAX, hormiguero));
            break;
        case 'q':
            universo.set_mundo(NULL);
            break;
        default:
            universo.set_mundo(NULL);
            std::cout << "No existe ese tipo de mundo... todavía" << std::endl;
            std::cout << "-----------------------------------------------------------------------" << std::endl;
            break;
    }
}