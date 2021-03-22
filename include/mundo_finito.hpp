#pragma once

#include "mundo.hpp"

#define SIZE_FILAS 25
#define SIZE_COLUMNAS 25

class MundoFinito : public Mundo {
    public:
        MundoFinito(unsigned = SIZE_FILAS, unsigned = SIZE_COLUMNAS, std::list<Hormiga*> = std::list<Hormiga*>());  // Cambios
};