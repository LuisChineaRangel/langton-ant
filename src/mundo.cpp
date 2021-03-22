#include "../include/mundo.hpp"
#include "../include/mundo_finito.hpp"
#include "../include/mundo_infinito.hpp"

Mundo::Mundo(void) {}

Mundo::~Mundo() {}

std::list<Hormiga*> Mundo::get_hormiguero(void) const { return hormiguero_; }

void Mundo::set_hormiga(int fila, int columna, bool tipo) {
    if (!tipo) {
        hormiguero_.push_back(new HormigaA(fila, columna, &(*this)[fila][columna]));
    }
    else {
        hormiguero_.push_back(new HormigaB(fila, columna, &(*this)[fila][columna]));
    }
}

void Mundo::pasar_turno(void) {
    // Se deberá recorrer la lista de hormigas, y actualizar la posición de cada una de ellas
    for (std::list<Hormiga*>::iterator it = hormiguero_.begin(); it != hormiguero_.end(); ++it) {
        try {
            (*it) -> actualizar(this);
        }
        catch (WrongIndex& e) {
            if (typeid(*this) == typeid(MundoFinito)) {
                (*it) -> corregir_posicion(this);
            }
            else if (typeid(*this) == typeid(MundoInfinito)) {
                dynamic_cast<MundoInfinito*>(this) -> resize_fila((*it) -> get_fila());
                dynamic_cast<MundoInfinito*>(this) -> resize_columna((*it) -> get_columna());
            }
            
            (*it) -> set_posicion(&(*this)[(*it) -> get_fila()][(*it) -> get_columna()]);
        }
    }
}

std::ostream& Mundo::write(std::ostream& os) const {
    write_border(os, (*this));
    os << std::endl;

    for (int i = begin(); i < end(); ++i) {
        os << "|";
        for (int j = (*this)[begin()].begin(); j < (*this)[begin()].end(); ++j) {
            const Hormiga* hormiga = NULL;

            for (std::list<Hormiga*>::const_iterator it = hormiguero_.begin(); it != hormiguero_.end(); ++it) {
                if (&(*this)[i][j] == (*it) -> get_posicion()) {
                    hormiga = (*it); 
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

std::ostream& write_border(std::ostream& os, const Mundo& mundo) {
    for (int i = 0; i <= mundo[mundo.begin()].size() + 1; i++) {
        os << "-";
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Mundo& mundo) {
    return mundo.write(os);
}