#include "../include/mundo.hpp"

Mundo::Mundo(int filas_min, int filas_max, int columnas_min, int columnas_max) {
    (*this).resize(filas_min, filas_max);

    for (int i = filas_min; i < filas_max; ++i) {
        (*this)[i].resize(columnas_min, columnas_max);
        for (int j = columnas_min; j < columnas_max; ++j) {
            (*this)[i][j] = new celda(false);
        }
    }
}

Mundo::~Mundo() {
    for (int i = (*this).get_begin(); i < (*this).get_end(); ++i) {
        for (int j = (*this)[i].get_begin(); j < (*this)[i].get_end(); ++j) {
            delete (*this)[i][j];
        }
    }
}

Hormiga Mundo::get_hormiga(void) const { return hormiga_; }

void Mundo::set_hormiga(int fila, int columna) {
    hormiga_ = Hormiga(fila, columna);
    hormiga_.set_posicion((*this)[fila][columna]);
}

void Mundo::crear_columnas(int fila) {

    (*this)[fila].resize((*this)[get_begin()].get_begin(), (*this)[get_begin()].get_end());
    for (int i = (*this)[get_begin()].get_begin(); i < (*this)[get_begin()].get_end(); ++i) {
        (*this)[fila][i] = new celda(false);
    }
}

void Mundo::pasar_turno(void) {
    hormiga_.mover(*this);
}

std::ostream& operator<<(std::ostream& os, const Mundo& mundo) {
    for (int i = 0; i <= mundo[mundo.get_begin()].size() + 1; i++) {
        os << "-";
    }
    os << std::endl;
    for (int i = mundo.get_begin(); i < mundo.get_end(); ++i) {
        os << "|";
        for (int j = mundo[mundo.get_begin()].get_begin(); j < mundo[mundo.get_begin()].get_end(); ++j) {
            if (mundo[i][j] == mundo.get_hormiga().get_posicion()) {
                os << mundo.get_hormiga();
            }
            else if (!(*mundo[i][j])) {
                os << " ";
            }
            else {
                os << "X";
            }
        }
        os << "|" << std::endl;
    }
    for (int i = 0; i <= mundo[mundo.get_begin()].size() + 1; i++) {
        os << "-";
    }
    return os;
}