#include "../include/hormiga.hpp"
#include "../include/mundo_finito.hpp"
#include "../include/mundo_infinito.hpp"

Hormiga::Hormiga(int fila, int columna, celda* posicion) : movimiento_(arriba), posicion_(posicion), fila_(fila), columna_(columna) {}

Hormiga::~Hormiga() {}

Direccion Hormiga::get_direccion(void) const { return movimiento_; }

celda* Hormiga::get_posicion(void) const { return posicion_; }

int Hormiga::get_fila(void) const { return fila_; }

int Hormiga::get_columna(void) const { return columna_; }

void Hormiga::set_direccion(Direccion movimiento) { movimiento_ = movimiento; }

void Hormiga::set_posicion(celda* posicion) { posicion_ = posicion; }

void Hormiga::mover_finito(MundoFinito& mundo) {
    if (!(*posicion_)) {
        *posicion_ = true;

        movimiento_ = Direccion((movimiento_ + 2) % ENUM_SIZE);
    }
    else {
        *posicion_ = false;

        if (Direccion(movimiento_ - 2) <= 0)
            movimiento_ = arriba;
        else
            movimiento_ = Direccion(movimiento_ - 2);
        
    }

    actualizar_pos();

    if (fila_ < 0)
        fila_ = mundo.size() - 1;

    if (columna_ < 0)
        columna_ = mundo[0].size() - 1;

    if (fila_ >= mundo.size())
        fila_ = 0;

    if (columna_ >= mundo[0].size())
        columna_ = 0; 

    posicion_ = mundo[fila_][columna_];
}

void Hormiga::mover_infinito(MundoInfinito& mundo) {
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

    actualizar_pos();

    // Redimensionar Filas
    mundo.resize_fila(fila_);
    
    // Redimensionar Columnas
    mundo.resize_columna(columna_);

    posicion_ = mundo[fila_][columna_];
}

bool Hormiga::operator<(const Hormiga& hormiga) const {
    if ((fila_ < hormiga.get_fila()) || ((fila_ == hormiga.get_fila()) && (columna_ < hormiga.get_columna())))
        return true;

    return false;
}

Hormiga& Hormiga::operator=(const Hormiga& hormiga) {
    movimiento_ = hormiga.get_direccion();
    posicion_ = hormiga.get_posicion();
    fila_ = hormiga.get_fila();
    columna_ = hormiga.get_columna();

    return (*this);
}

void Hormiga::actualizar_pos(void) {
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