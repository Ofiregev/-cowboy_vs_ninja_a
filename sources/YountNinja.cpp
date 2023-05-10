#include "YountNinja.hpp"

namespace ariel {

    YountNinja::YountNinja(string name, Point location) : Ninja(location, 100, name) {
        setSpeed(14);
    }

}
