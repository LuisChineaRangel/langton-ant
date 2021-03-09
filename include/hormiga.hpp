#pragma once

#include <iostream>
#include <cmath>

typedef bool celda;

#define ENUM_SIZE 8
enum Direccion {arriba_izquierda, izquierda, abajo_izquierda, abajo, abajo_derecha, derecha, arriba_derecha, arriba};

class Mundo;

class Hormiga {
    private:
        Direccion movimiento_;
        celda* posicion_;
        int fila_, columna_;
        
    public:
        Hormiga(int = -1, int = -1);
        ~Hormiga();

        Direccion get_direccion(void) const;
        celda* get_posicion(void) const;
        int get_fila(void) const;
        int get_columna(void) const;

        void set_direccion(Direccion);
        void set_posicion(celda*);

        void mover(Mundo&);

        Hormiga& operator=(const Hormiga&);

    private:
        void actualizar_pos(Mundo&);
};

std::ostream& operator<<(std::ostream&, const Hormiga&);