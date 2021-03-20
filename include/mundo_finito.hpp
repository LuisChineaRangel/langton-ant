#pragma once

#include <vector>

#include "mundo.hpp"
#include "hormiga.hpp"

#define SIZE_FILAS 25
#define SIZE_COLUMNAS 25

class MundoFinito : public Mundo, public std::vector<std::vector<Celda>> {
    public:
        MundoFinito(unsigned = SIZE_FILAS, unsigned = SIZE_COLUMNAS, std::list<Hormiga> = std::list<Hormiga>());  // Cambios
        ~MundoFinito();

        void set_hormiga(int, int);

        std::ostream& write(std::ostream&) const;
};

std::ostream& write_border(std::ostream&, const MundoFinito&);   // Cambio chorra