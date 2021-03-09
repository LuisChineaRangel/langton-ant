#include "../include/hormiga.hpp"
#include "../include/mundo.hpp"

Hormiga::Hormiga(int fila, int columna) : movimiento_(arriba), posicion_(NULL), fila_(fila), columna_(columna) {}

Hormiga::~Hormiga() {}

Direccion Hormiga::get_direccion(void) const { return movimiento_; }

celda* Hormiga::get_posicion(void) const { return posicion_; }

int Hormiga::get_fila(void) const { return fila_; }

int Hormiga::get_columna(void) const { return columna_; }

void Hormiga::set_direccion(Direccion movimiento) { movimiento_ = movimiento; }

void Hormiga::set_posicion(celda* posicion) { posicion_ = posicion; }

void Hormiga::mover(Mundo& mundo) {
    if (!(*posicion_)) {
        *posicion_ = true;
        movimiento_ = Direccion((movimiento_ + 1) % ENUM_SIZE);
    }
    else {
        *posicion_ = false;

        if (Direccion(movimiento_ - 1) == 0)
            movimiento_ = arriba;
        else
            movimiento_ = Direccion(movimiento_ - 1);
    }

    actualizar_pos(mundo);

    // Redimensionar Filas
    if (fila_ >= mundo.get_end()) {
        mundo.resize(mundo.get_begin(), fila_ + 1);

        mundo.crear_columnas(fila_);
    }
    else if (fila_ < mundo.get_begin()) {
        mundo.resize(fila_, mundo.get_end());

        mundo.crear_columnas(mundo.get_end() - 1);

        for (int i = mundo.get_end() - 1; i > mundo.get_begin(); --i) {
            for (int j = mundo[i].get_begin(); j < mundo[i].get_end(); ++j) {
                *mundo[i][j] = *mundo[i - 1][j];
            }
        }

        //for (int i = mundo[mundo.get_begin()].get_begin(); i < mundo[mundo.get_begin()].get_end(); ++i) {
        //    *mundo[mundo.get_begin()][i] = false;
        //}
    }
    
    // Redimensionar columnas
    if (columna_ >= mundo[mundo.get_begin()].get_end()) {
        for (int i = mundo.get_begin(); i < mundo.get_end(); ++i) {
            mundo[i].resize(mundo[i].get_begin(), columna_ + 1);
            mundo[i][columna_] = new celda(false);
        }
    }
    else if (columna_ < mundo[mundo.get_begin()].get_begin()) {
        for (int i = mundo.get_begin(); i < mundo.get_end(); ++i) {
            mundo[i].resize(columna_, mundo[i].get_end());

            mundo[i][mundo[mundo.get_begin()].get_end() - 1] = new celda(false);

            for (int j = mundo[mundo.get_begin()].get_end() - 1; j > mundo[mundo.get_begin()].get_begin(); --j) {
                *mundo[i][j] = *mundo[i][j - 1];
            }
            *mundo[i][mundo[mundo.get_begin()].get_begin()] = false;
        }
    }

    posicion_ = mundo[fila_][columna_];
}

Hormiga& Hormiga::operator=(const Hormiga& hormiga) {
    movimiento_ = hormiga.get_direccion();
    posicion_ = hormiga.get_posicion();
    fila_ = hormiga.get_fila();
    columna_ = hormiga.get_columna();

    return (*this);
}

void Hormiga::actualizar_pos(Mundo& mundo) {
    if ((movimiento_ == arriba_izquierda) || (movimiento_ == arriba_derecha) || (movimiento_ == arriba))  
        --fila_;
    
    if ((movimiento_ == abajo_izquierda) || (movimiento_ == abajo_derecha) || (movimiento_ == abajo))
        ++fila_;

    if ((movimiento_ == abajo_izquierda) || (movimiento_ == arriba_izquierda) || (movimiento_ == izquierda))
        --columna_;

    if ((movimiento_ == abajo_derecha) || (movimiento_ == arriba_derecha) || (movimiento_ == derecha))
        ++columna_;
}

std::ostream& operator<<(std::ostream& os, const Hormiga& hormiga) {
    switch (hormiga.get_direccion()) {
        case izquierda:
            return os << "←";
        case derecha:
            return os << "→";
        case arriba:
            return os << "↑";
        case abajo:
            return os << "↓";
        case abajo_derecha:
            return os << "↘";
        case abajo_izquierda:
            return os << "↙";
        case arriba_derecha:
            return os << "↗";
        case arriba_izquierda:
            return os << "↖";
    }
    return os;
}