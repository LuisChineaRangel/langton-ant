#pragma once

#include "hormiga.hpp"
#include "vector.hpp"

#define FILAS_MIN -5
#define FILAS_MAX 1

#define COLUMNAS_MIN -5
#define COLUMNAS_MAX 1

class Mundo : public Vector<Vector<celda*>> {
    private:
        Hormiga hormiga_;

    public:
        Mundo(int = FILAS_MIN, int = FILAS_MAX, int = COLUMNAS_MIN, int = COLUMNAS_MAX);
        ~Mundo();

        Hormiga get_hormiga(void) const;

        void set_hormiga(int, int);
        
        void crear_columnas(int);

        void pasar_turno(void);
};

std::ostream& operator<<(std::ostream&, const Mundo&);