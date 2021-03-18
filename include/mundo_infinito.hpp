#pragma once

#include "mundo.hpp"
#include "hormiga.hpp"
#include "vector.hpp"

#define FILAS_MIN -5
#define FILAS_MAX 1

#define COLUMNAS_MIN -5
#define COLUMNAS_MAX 1

class MundoInfinito : public Mundo, public Vector<Vector<celda*>> {
    private:
        
    public:
        MundoInfinito(int = FILAS_MIN, int = FILAS_MAX, int = COLUMNAS_MIN, int = COLUMNAS_MAX);
        ~MundoInfinito();
        
        void set_hormiga(int, int);

        void crear_columnas(int);

        void resize_fila(int);
        void resize_columna(int);

        void pasar_turno(void);

        std::ostream& write(std::ostream&) const;
};

std::ostream& write_border(std::ostream&, const MundoInfinito&);
std::ostream& operator<<(std::ostream&, const MundoInfinito&);