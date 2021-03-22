#include "../include/mundo_infinito.hpp"

MundoInfinito::MundoInfinito(int filas_min, int filas_max, int columnas_min, int columnas_max, std::list<Hormiga*> hormiguero) {
    (*this).resize(filas_min, filas_max);

    for (int i = filas_min; i < filas_max; ++i) {
        (*this)[i].resize(columnas_min, columnas_max);
    }

    for (std::list<Hormiga*>::iterator it = hormiguero.begin(); it != hormiguero.end(); ++it) {
        if (typeid(*it) == typeid(HormigaA))
            set_hormiga((*it) -> get_fila(), (*it) -> get_columna(), false);
        else
            set_hormiga((*it) -> get_fila(), (*it) -> get_columna(), true);
    }
}

void MundoInfinito::crear_columnas(int fila) {
    (*this)[fila].resize((*this)[begin()].begin(), (*this)[begin()].end());
}

void MundoInfinito::resize_fila(int fila) {
    if (fila >= end()) {
        resize(begin(), fila + 1);

        crear_columnas(fila);
    }
    else if (fila < begin()) {
        resize(fila, end());

        crear_columnas(end() - 1);

        for (int i = end() - 1; i > begin(); --i)
            for (int j = (*this)[i].begin(); j < (*this)[i].end(); ++j)
                (*this)[i][j] = (*this)[i - 1][j];

        for (int i = (*this)[begin()].end() - 1; i > (*this)[begin()].begin(); --i)
            (*this)[begin()][i] = blanco;
    }
}

void MundoInfinito::resize_columna(int columna) {
    if (columna >= (*this)[begin()].end()) {
        for (int i = begin(); i < end(); ++i) {
            (*this)[i].resize((*this)[i].begin(), columna + 1);
        }
    }
    else if (columna < (*this)[begin()].begin()) {
        for (int i = begin(); i < end(); ++i) {
            (*this)[i].resize(columna, (*this)[i].end());

            for (int j = (*this)[begin()].end() - 1; j > (*this)[begin()].begin(); --j) {
                (*this)[i][j] = (*this)[i][j - 1];
            }
            (*this)[i][(*this)[begin()].begin()] = blanco;
        }
    }
}