#pragma once

#include "mundo.hpp"
#include "hormiga.hpp"
#include "vector.hpp"

#define FILAS_MIN -10
#define FILAS_MAX 10

#define COLUMNAS_MIN -10
#define COLUMNAS_MAX 10

class MundoInfinito : public Mundo, public Vector<Vector<Celda>> {
    private:
        
    public:
        MundoInfinito(int = FILAS_MIN, int = FILAS_MAX, int = COLUMNAS_MIN, int = COLUMNAS_MAX, std::list<Hormiga> = std::list<Hormiga>());
        ~MundoInfinito();
        
        void set_hormiga(int, int);

        void crear_columnas(int);

        void resize_fila(int);
        void resize_columna(int);

        std::ostream& write(std::ostream&) const;
};

std::ostream& write_border(std::ostream&, const MundoInfinito&);