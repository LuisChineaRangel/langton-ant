#pragma once

#include <iostream>
#include <cmath>

#define ENUM_SIZE 8

enum Celda {blanco, negro};
enum Direccion {arriba_izquierda, izquierda, abajo_izquierda, abajo, abajo_derecha, derecha, arriba_derecha, arriba};

class Mundo;
class MundoFinito;
class MundoInfinito;

class Hormiga {
    private:
        Direccion movimiento_;
        Celda* posicion_;
        int fila_, columna_;
        
    public:
        Hormiga(int = -1, int = -1, Celda* = NULL);  // Añadido la opción de inicializar la posición
        ~Hormiga();

        Direccion get_direccion(void) const;
        Celda* get_posicion(void) const;
        int get_fila(void) const;
        int get_columna(void) const;

        void actualizar(Mundo*);

        std::ostream& write(std::ostream&) const;

        Hormiga& operator=(const Hormiga&);

    private:
        void girar(Celda, Mundo*);
        void desplazar(Mundo*);

        void corregir_posicion(const MundoFinito);
};

std::ostream& operator<<(std::ostream&, const Hormiga&);