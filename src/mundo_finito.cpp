#include "../include/mundo_finito.hpp"

MundoFinito::MundoFinito(unsigned filas, unsigned columnas) {
    (*this).resize(filas);

    for (unsigned i = 0; i < filas; ++i) {
        (*this)[i].resize(columnas);
        for (unsigned j = 0; j < columnas; ++j) {
            (*this)[i][j] = new celda(false);
        }
    }

    set_hormiga(0, 0);

    /*
    hormigas_ = hormigas;

    for (std::set<Hormiga>::iterator it = hormigas_.begin(); it != hormigas_.end(); ++it) {
        (*it).set_posicion((*it).get_fila(), (*it).get_columna());
    }*/
}

MundoFinito::~MundoFinito() {
    for (unsigned i = 0; i < (*this).size(); ++i) {
        for (unsigned j = 0; j < (*this)[i].size(); ++j) {
            delete (*this)[i][j];
        }
    }
}

void MundoFinito::set_hormiga(int fila, int columna) {
    hormiga_ = Hormiga(fila, columna, (*this)[fila][columna]);
    //hormigas_.insert(Hormiga(fila, columna, (*this)[fila][columna]));
}

void MundoFinito::pasar_turno(void) {
    // Se deberá recorrer la lista de hormigas, y actualizar la posición de cada una de ellas
    hormiga_.mover_finito(*this);
}

std::ostream& MundoFinito::write(std::ostream& os) const {
    write_border(os, (*this));
    os << std::endl;
    
    for (unsigned i = 0; i < size(); ++i) {
        os << "|";
        for (unsigned j = 0; j < (*this)[i].size(); ++j) {
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

std::ostream& write_border(std::ostream& os, const MundoFinito& mundo) {
    for (unsigned i = 0; i <= mundo[0].size() + 1; i++) {
        os << "-";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const MundoFinito& mundo) {
    return mundo.write(os);
}