#pragma once

#include "hormiga.hpp"

class HormigaA : public Hormiga {
    public:
        HormigaA(int = -1, int = -1, Celda* = NULL);

    private:
        void girar(Celda color, Mundo* mundo);
        void desplazar(Mundo* mundo);
};