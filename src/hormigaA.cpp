#include "../include/hormigaA.hpp"
#include "../include/mundo.hpp"

HormigaA::HormigaA(int fila, int columna, Celda* posicion) : Hormiga(fila, columna, posicion) {}

void HormigaA::girar(Celda color, Mundo* mundo) {
    switch (color) {
        case blanco:
            movimiento_ = Direccion((movimiento_ + 2) % ENUM_SIZE);
            break;
        case negro:
            if (Direccion(movimiento_ - 2) <= 0)
                movimiento_ = arriba;
            else
                movimiento_ = Direccion(movimiento_ - 2);
            break;
    }
}

void HormigaA::desplazar(Mundo* mundo) {
    actualizar_coordendas();

    posicion_ = &(*mundo)[fila_][columna_];
}