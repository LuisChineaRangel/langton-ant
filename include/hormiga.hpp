#pragma once

#include <iostream>
#include <cmath>

typedef bool celda;

#define ENUM_SIZE 8
enum Direccion {arriba_izquierda, izquierda, abajo_izquierda, abajo, abajo_derecha, derecha, arriba_derecha, arriba};

class MundoFinito;
class MundoInfinito;

class Hormiga {
    private:
        Direccion movimiento_;
        celda* posicion_;
        int fila_, columna_;
        
    public:
        Hormiga(int = -1, int = -1, celda* = NULL);  // Añadido la opción de inicializar la posición
        ~Hormiga();

        Direccion get_direccion(void) const;
        celda* get_posicion(void) const;
        int get_fila(void) const;
        int get_columna(void) const;

        void set_direccion(Direccion);
        void set_posicion(celda*);

        void mover_finito(MundoFinito&);
        void mover_infinito(MundoInfinito&);

        bool operator<(const Hormiga&) const;

        Hormiga& operator=(const Hormiga&);

    private:
        void actualizar_pos(void);
};

std::ostream& operator<<(std::ostream&, const Hormiga&);