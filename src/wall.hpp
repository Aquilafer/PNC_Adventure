#ifndef __WALL_HPP_
#define __WALL_HPP_

#include <string>
#include <assert.h>
#include "gstate.hpp"

/*
scene = 1
uses sword (INV::sword)
*/

class Wall
{
public:
Wall();
~Wall();

std::string look_at(Gstate* state);
std::string use(Gstate* state);
std::string go_to(Gstate* state);
};

std::string Wall::look_at(Gstate* state){
    assert(state->scene == 1);
    switch(state->inv & INV::sword) {
    case 0: 
	state->inv |= INV::sword;
        return "The wall is cool to touch. Hanging along the wall are swords of various shapes, though most are quite rusted. You pick up one of the less degraded ones. You now have a SWORD!";
    case 1:
        return "There is an empty spot on the wall where the sword you took used to be.";
    }
}

std::string Wall::use(Gstate* state){
    assert(state->scene == 1);
    return "You knock the wall with your hand. It is quite sturdy despite how worn it is. There is no use in trying to break through it without an excavation team.";
}

std::string Wall::go_to(Gstate* state){
    assert(state->scene == 1);
    return this->look_at(state);
}

#endif
