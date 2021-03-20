#include "../include/mundo_finito.hpp"

MundoFinito::MundoFinito(unsigned filas, unsigned columnas, std::list<Hormiga> hormiguero) {
    (*this).resize(filas);

    for (unsigned i = 0; i < filas; ++i) {
        (*this)[i].resize(columnas);
        for (unsigned j = 0; j < columnas; ++j) {
            (*this)[i][j] = blanco;
        }
    }

    for (std::list<Hormiga>::iterator it = hormiguero.begin(); it != hormiguero.end(); ++it) {
        set_hormiga((*it).get_fila(), (*it).get_columna());
    }
}

MundoFinito::~MundoFinito() {}

void MundoFinito::set_hormiga(int fila, int columna) {
    hormiguero_.push_back(Hormiga(fila, columna, &(*this)[fila][columna]));
}

std::ostream& MundoFinito::write(std::ostream& os) const {
    write_border(os, (*this));
    os << std::endl;
    
    for (unsigned i = 0; i < size(); ++i) {
        os << "|";
        for (unsigned j = 0; j < (*this)[i].size(); ++j) {
            
            const Hormiga* hormiga = NULL;

            for (std::list<Hormiga>::const_iterator it = hormiguero_.begin(); it != hormiguero_.end(); ++it) {
                if (&(*this)[i][j] == (*it).get_posicion()) {
                    hormiga = &(*it); 
                    break;
                }
            }

            if (hormiga)
                os << *hormiga;
            else if ((*this)[i][j] == blanco)
                os << " ";
            else
                os << "X";
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