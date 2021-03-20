#pragma once

#include <list>

#include "hormiga.hpp"

class Mundo {
    protected:
        std::list<Hormiga> hormiguero_;

    public:
        std::list<Hormiga> get_hormiguero(void) const;

        virtual void set_hormiga(int, int) = 0;

        void pasar_turno(void);

        virtual std::ostream& write(std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream&, const Mundo&);