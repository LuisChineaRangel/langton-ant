#include "mundo_finito.hpp"
#include "mundo_infinito.hpp"

class Universo {
    private:
        Mundo* mundo_;
    
    public:
        Universo(Mundo* = NULL);
        ~Universo();

        Mundo* get_mundo(void) const;

        void set_mundo(Mundo*);

        void controlar_tiempo(int);

    private:
        void pasar_turno(void);
};

std::ostream& operator<<(std::ostream&, const Universo&);