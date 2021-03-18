#include "../include/mundo.hpp"

Hormiga Mundo::get_hormiga(void) const { return hormiga_; }

std::ostream& operator<<(std::ostream& os, const Mundo& mundo) {
    return mundo.write(os);
}