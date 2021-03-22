#include "../include/mundo_finito.hpp"

MundoFinito::MundoFinito(unsigned filas, unsigned columnas, std::list<Hormiga*> hormiguero) {
    (*this).resize(0, filas);

    for (unsigned i = 0; i < filas; ++i) {
        (*this)[i].resize(0, columnas);
    }

    for (std::list<Hormiga*>::iterator it = hormiguero.begin(); it != hormiguero.end(); ++it) {
        if (typeid(*(*it)) == typeid(HormigaA))
            set_hormiga((*it) -> get_fila(), (*it) -> get_columna(), false);
        else
            set_hormiga((*it) -> get_fila(), (*it) -> get_columna(), true);
    }
}