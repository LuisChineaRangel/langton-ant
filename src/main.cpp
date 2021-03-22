#include "../include/universo.hpp"

void crear_big_bang(Universo&, char&);
void rellenar_hormiguero(std::list<Hormiga*>&);

int main (void) {
    char opcion;
    Universo via_lactea;

    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << via_lactea << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    while (opcion != 'q') {
        crear_big_bang(via_lactea, opcion);
        std::cout << via_lactea << std::endl;

        if (via_lactea.get_mundo())
            via_lactea.controlar_tiempo(10);

        std::cout << "-----------------------------------------------------------------------" << std::endl;
        std::cout << "¡DESTRUYAMOS ESTE UNIVERSO!" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
    }

    return 0;
}

void crear_big_bang(Universo& universo, char& opcion) {
    int filas_min, filas_max, columnas_min, columnas_max;
    std::cout << "Creemos el BIG BANG, ¿que tipo de universo desea? [F]inito / [I]nfinito" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "Introduzca su opción: ";
    std::cin >> opcion;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "Introduzca las dimensiones de la malla" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    
    std::list<Hormiga*> hormiguero;
    switch(opcion) {
        case 'F':
            
            std::cout << "Filas: ";
            std::cin >> filas_max;
            std::cout << "Columnas: ";
            std::cin >> columnas_max;
            std::cout << "-----------------------------------------------------------------------" << std::endl;
            
            rellenar_hormiguero(hormiguero);
            universo.set_mundo(new MundoFinito(filas_max, columnas_max, hormiguero));
            break;
        case 'I':
            std::cout << "Filas Mínimas: ";
            std::cin >> filas_min;
            std::cout << "Filas Máximas: ";
            std::cin >> filas_max;
            std::cout << "-----------------------------------------------------------------------" << std::endl;
            std::cout << "Columnas Mínimas: ";
            std::cin >> columnas_min;
            std::cout << "Columnas Máximas: ";
            std::cin >> columnas_max;
            std::cout << "-----------------------------------------------------------------------" << std::endl;

            rellenar_hormiguero(hormiguero);
            universo.set_mundo(new MundoInfinito(filas_min, filas_max, columnas_min, columnas_max, hormiguero));
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

void rellenar_hormiguero(std::list<Hormiga*>& hormiguero) {
    unsigned size;
    int fila, columna;
    char tipo;

    std::cout << "¿De que tamaño quieres el hormiguero?" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "Introduzca su opción: ";
    std::cin >> size;
    
    for (unsigned i = 0; i < size; ++i) {
        std::cout << "-----------------------------------------------------------------------" << std::endl;
        std::cout << "Hormiga " << i + 1 << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
        std::cout << "Fila: ";
        std::cin >> fila;
        std::cout << "Columna: ";
        std::cin >> columna;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
        std::cout << "Tipo (A/B): ";
        std::cin >> tipo;

        switch (tipo) {
            case 'A':
                hormiguero.push_back(new HormigaA(0, 0));
                break;
            case 'B':
                hormiguero.push_back(new HormigaB(0, 0));
                break;
            default:
                std::cout << "Tipo de Hormiga Desconocido" << std::endl;
        }
    }
}