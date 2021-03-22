#include "../include/hormigaB.hpp"
#include "../include/mundo.hpp"

HormigaB::HormigaB(int fila, int columna, Celda* posicion) : Hormiga(fila, columna, posicion) {}

void HormigaB::girar(Celda color, Mundo* mundo) {
    switch (color) {
        case negro:
            movimiento_ = Direccion((movimiento_ + 1) % ENUM_SIZE);
            break;
        case blanco:
            if (Direccion(movimiento_ - 1) <= 0)
                movimiento_ = arriba;
            else
                movimiento_ = Direccion(movimiento_ - 1);
            break;
    }
}

void HormigaB::desplazar(Mundo* mundo) {
    actualizar_coordendas();

    posicion_ = &(*mundo)[fila_][columna_];
}