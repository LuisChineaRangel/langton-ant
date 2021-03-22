#pragma once

#include "hormiga.hpp"

class HormigaB : public Hormiga {
    public:
        HormigaB(int = -1, int = -1, Celda* = NULL);

    private:
        void girar(Celda color, Mundo* mundo);
        void desplazar(Mundo* mundo);
};