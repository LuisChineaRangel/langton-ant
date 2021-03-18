#include "../include/universo.hpp"

Universo::Universo(Mundo* mundo) : mundo_(mundo) {}

Universo::~Universo() {
    if (mundo_)
        delete mundo_;

    mundo_ = NULL;
}

Mundo* Universo::get_mundo(void) const { return mundo_; }

void Universo::set_mundo(Mundo* mundo) {
    if (mundo_)
        delete mundo_;

    mundo_ = NULL;

    mundo_ = mundo; 
}

void Universo::controlar_tiempo(int segundos) {
    for (int i = 0; i < segundos; ++i) {
        pasar_turno();
        std::cout << (*this) << std::endl;
    }
}

void Universo::pasar_turno(void) {
    mundo_ -> pasar_turno();
}

std::ostream& operator<<(std::ostream& os, const Universo& universo) {
    if (universo.get_mundo())
        return os << *universo.get_mundo();
    else
        return os << "¡Todavía no ha sucedido el BIG BANG!";
}