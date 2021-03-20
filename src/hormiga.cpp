#include "../include/hormiga.hpp"
#include "../include/mundo_finito.hpp"
#include "../include/mundo_infinito.hpp"

Hormiga::Hormiga(int fila, int columna, Celda* posicion) : movimiento_(arriba), posicion_(posicion), fila_(fila), columna_(columna) {}

Hormiga::~Hormiga() {}

Direccion Hormiga::get_direccion(void) const { return movimiento_; }

Celda* Hormiga::get_posicion(void) const { return posicion_; }

int Hormiga::get_fila(void) const { return fila_; }

int Hormiga::get_columna(void) const { return columna_; }

void Hormiga::actualizar(Mundo* mundo) {
    if (*posicion_ == blanco) {
        *posicion_ = negro;

        girar(blanco, mundo);
    }
    else {
        *posicion_ = blanco;
        girar(negro, mundo);
    }

    desplazar(mundo);
}

std::ostream& Hormiga::write(std::ostream& os) const {
    switch (get_direccion()) {
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

Hormiga& Hormiga::operator=(const Hormiga& hormiga) {
    movimiento_ = hormiga.get_direccion();
    posicion_ = hormiga.get_posicion();
    fila_ = hormiga.get_fila();
    columna_ = hormiga.get_columna();

    return (*this);
}

void Hormiga::girar(Celda color, Mundo* mundo) {
    int desplazamiento = 0;
    
    if (typeid(*mundo) == typeid(MundoFinito))
        desplazamiento = 2;
    else if (typeid(*mundo) == typeid(MundoInfinito))
        desplazamiento = 1;

    switch (color) {
        case blanco:
            movimiento_ = Direccion((movimiento_ + desplazamiento) % ENUM_SIZE);
            break;
        case negro:
            if (Direccion(movimiento_ - desplazamiento) <= 0)
                movimiento_ = arriba;
            else
                movimiento_ = Direccion(movimiento_ - desplazamiento);
            break;
    }
}

void Hormiga::desplazar(Mundo* mundo) {
    if ((movimiento_ == arriba_izquierda) || (movimiento_ == arriba_derecha) || (movimiento_ == arriba))  
        --fila_;
    
    if ((movimiento_ == abajo_izquierda) || (movimiento_ == abajo_derecha) || (movimiento_ == abajo))
        ++fila_;

    if ((movimiento_ == abajo_izquierda) || (movimiento_ == arriba_izquierda) || (movimiento_ == izquierda))
        --columna_;

    if ((movimiento_ == abajo_derecha) || (movimiento_ == arriba_derecha) || (movimiento_ == derecha))
        ++columna_;

    if (typeid(*mundo) == typeid(MundoFinito)) {
        corregir_posicion(*dynamic_cast<MundoFinito*>(mundo));

        posicion_ = &(*dynamic_cast<MundoFinito*>(mundo))[fila_][columna_];
    }
    else if (typeid(*mundo) == typeid(MundoInfinito)) {

        dynamic_cast<MundoInfinito*>(mundo) -> resize_fila(fila_);
        dynamic_cast<MundoInfinito*>(mundo) -> resize_columna(columna_);

        posicion_ = &(*dynamic_cast<MundoInfinito*>(mundo))[fila_][columna_];
    }
}

void Hormiga::corregir_posicion(const MundoFinito mundo) {
    if (fila_ < 0)
        fila_ = mundo.size() - 1;

    if (columna_ < 0)
        columna_ = mundo[0].size() - 1;

    if (fila_ >= mundo.size())
        fila_ = 0;

    if (columna_ >= mundo[0].size())
        columna_ = 0;
}

std::ostream& operator<<(std::ostream& os, const Hormiga& hormiga) {
    return hormiga.write(os);
}