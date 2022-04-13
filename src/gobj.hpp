#ifndef __GOBJ_HPP_
#define __GOBJ_HPP_

#include <string>
#include "gstate.hpp"

class Gobj {
public:
    G_obj();
    ~G_obj();
    
    std::string use(Gstate* state);
    std::string look_at(Gstate* state);
    std::string go_to(Gstate* state);
}

#endif
