#pragma once

#include "mundo.hpp"

#define FILAS_MIN -10
#define FILAS_MAX 10

#define COLUMNAS_MIN -10
#define COLUMNAS_MAX 10

class MundoInfinito : public Mundo {
    private:
        
    public:
        MundoInfinito(int = FILAS_MIN, int = FILAS_MAX, int = COLUMNAS_MIN, int = COLUMNAS_MAX, std::list<Hormiga*> = std::list<Hormiga*>());
        
        void crear_columnas(int);

        void resize_fila(int);
        void resize_columna(int);
};