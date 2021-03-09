#include "../include/universo.hpp"

Universo::Universo(int filas_min, int filas_max, int columnas_min, int columnas_max) {
    mundo_ = new Mundo(filas_min, filas_max);
}

Universo::~Universo() {
    delete mundo_;
}

Mundo* Universo::get_mundo(void) const { return mundo_; }

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
    return os << *universo.get_mundo();
}