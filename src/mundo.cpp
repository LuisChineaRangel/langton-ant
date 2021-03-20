#include "../include/mundo.hpp"

std::list<Hormiga> Mundo::get_hormiguero(void) const { return hormiguero_; }

void Mundo::pasar_turno(void) {
    // Se deberá recorrer la lista de hormigas, y actualizar la posición de cada una de ellas
    for (std::list<Hormiga>::iterator it = hormiguero_.begin(); it != hormiguero_.end(); ++it)
        (*it).actualizar(this);
}

std::ostream& operator<<(std::ostream& os, const Mundo& mundo) {
    return mundo.write(os);
}