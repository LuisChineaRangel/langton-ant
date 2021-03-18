#pragma once

#include <set>

#include "hormiga.hpp"

class Mundo {
    protected:
        Hormiga hormiga_;

    public:

        Hormiga get_hormiga(void) const;

        virtual void set_hormiga(int, int) = 0;

        virtual void pasar_turno(void) = 0;

        virtual std::ostream& write(std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream&, const Mundo&);