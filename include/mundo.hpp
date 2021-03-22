#pragma once

#include <list>

#include "hormigaA.hpp"
#include "hormigaB.hpp"
#include "vector.hpp"

class Mundo : public Vector<Vector<Celda>>{
    protected:
        std::list<Hormiga*> hormiguero_;

    public:
        Mundo(void);
        ~Mundo();

        std::list<Hormiga*> get_hormiguero(void) const;

        virtual void set_hormiga(int, int, bool);

        void pasar_turno(void);

        std::ostream& write(std::ostream&) const;
};

std::ostream& write_border(std::ostream&, const Mundo&);
std::ostream& operator<<(std::ostream&, const Mundo&);