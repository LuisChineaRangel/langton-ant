#include "mundo.hpp"

class Universo {
    private:
        Mundo* mundo_;
    
    public:
        Universo(int = FILAS_MIN, int = FILAS_MAX, int = COLUMNAS_MIN, int = COLUMNAS_MAX);
        ~Universo();

        Mundo* get_mundo(void) const;

        void controlar_tiempo(int);

    private:
        void pasar_turno(void);
};

std::ostream& operator<<(std::ostream&, const Universo&);