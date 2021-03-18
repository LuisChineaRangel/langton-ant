#include "../include/mundo_infinito.hpp"

MundoInfinito::MundoInfinito(int filas_min, int filas_max, int columnas_min, int columnas_max) {
    (*this).resize(filas_min, filas_max);

    for (int i = filas_min; i < filas_max; ++i) {
        (*this)[i].resize(columnas_min, columnas_max);
        for (int j = columnas_min; j < columnas_max; ++j) {
            (*this)[i][j] = new celda(false);
        }
    }

    set_hormiga(filas_min, columnas_min);
}

MundoInfinito::~MundoInfinito() {
    for (int i = (*this).get_begin(); i < (*this).get_end(); ++i) {
        for (int j = (*this)[i].get_begin(); j < (*this)[i].get_end(); ++j) {
            delete (*this)[i][j];
        }
    }
}

void MundoInfinito::set_hormiga(int fila, int columna) {
    hormiga_ = Hormiga(fila, columna, (*this)[fila][columna]);
    //hormigas_.insert(Hormiga(fila, columna, (*this)[fila][columna]));
}

void MundoInfinito::crear_columnas(int fila) {

    (*this)[fila].resize((*this)[get_begin()].get_begin(), (*this)[get_begin()].get_end());
    for (int i = (*this)[get_begin()].get_begin(); i < (*this)[get_begin()].get_end(); ++i) {
        (*this)[fila][i] = new celda(false);
    }
}

void MundoInfinito::resize_fila(int fila) {
    if (fila >= get_end()) {
        resize(get_begin(), fila + 1);

        crear_columnas(fila);
    }
    else if (fila < get_begin()) {
        resize(fila, get_end());

        crear_columnas(get_end() - 1);

        for (int i = get_end() - 1; i > get_begin(); --i)
            for (int j = (*this)[i].get_begin(); j < (*this)[i].get_end(); ++j)
                *(*this)[i][j] = *(*this)[i - 1][j];

        for (int i = (*this)[get_begin()].get_end() - 1; i > (*this)[get_begin()].get_begin(); --i)
            *(*this)[get_begin()][i] = false;
    }
}

void MundoInfinito::resize_columna(int columna) {
    if (columna >= (*this)[get_begin()].get_end()) {
        for (int i = get_begin(); i < get_end(); ++i) {
            (*this)[i].resize((*this)[i].get_begin(), columna + 1);
            (*this)[i][columna] = new celda(false);
        }
    }
    else if (columna < (*this)[get_begin()].get_begin()) {
        for (int i = get_begin(); i < get_end(); ++i) {
            (*this)[i].resize(columna, (*this)[i].get_end());

            (*this)[i][(*this)[get_begin()].get_end() - 1] = new celda(false);

            for (int j = (*this)[get_begin()].get_end() - 1; j > (*this)[get_begin()].get_begin(); --j) {
                *(*this)[i][j] = *(*this)[i][j - 1];
            }
            *(*this)[i][(*this)[get_begin()].get_begin()] = false;
        }
    }
}

void MundoInfinito::pasar_turno(void) {
    hormiga_.mover_infinito(*this);
}

std::ostream& MundoInfinito::write(std::ostream& os) const {
    write_border(os, (*this));
    os << std::endl;

    for (int i = get_begin(); i < get_end(); ++i) {
        os << "|";
        for (int j = (*this)[get_begin()].get_begin(); j < (*this)[get_begin()].get_end(); ++j) {
            if ((*this)[i][j] == get_hormiga().get_posicion()) {
                os << get_hormiga();
            }
            else if (!(*(*this)[i][j])) {
                os << " ";
            }
            else {
                os << "X";
            }
        }
        os << "|" << std::endl;
    }

    write_border(os, (*this));

    return os;
}

std::ostream& write_border(std::ostream& os, const MundoInfinito& mundo) {
    for (int i = 0; i <= mundo[mundo.get_begin()].size() + 1; i++) {
        os << "-";
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const MundoInfinito& mundo) {
    return mundo.write(os);
}