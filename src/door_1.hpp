#ifndef __DOOR_1_HPP_
#define __DOOR_1_HPP_

#include <string>
#include <assert.h>
#include "gstate.hpp"

/*
scene = 1
state |= 0b1
uses key (INV::key1)
*/

namespace DOOR
{
	const int locked = 0b0;
	const int unlocked = 0b1;
}

class Door_1
{
public:
Door_1();
~Door_1();

std::string look_at(Gstate* state);
std::string use(Gstate* state);
std::string go_to(Gstate* state);
};

std::string Door_1::look_at(Gstate* state){
    assert(state->scene == 1);
    switch(state->state & DOOR::unlocked) {
    case 0: 
        if(state->inv & INV::key1){
            return "The door is locked, but you have a key that looks like it might fit.";
        } else {
            return "The door is locked.";
        }
    case 1:
        if(state->inv & INV::key1){
            return "The door is unlocked. It goes to another room. You hear something growling.";
        } else {
            return "The door is locked. You think you can hear something on the other side.";
        }
    }
}

std::string Door_1::use(Gstate* state){
    assert(state->scene == 1);
    switch(state->state & DOOR::unlocked) {
    case 0:       
        if(state->state & INV::key1){
            state->state |= DOOR::unlocked;
            return "You use the key on the door. The door unlocks.";
        } else {
	    return "You try the knop, but it is locked."
        }
    case 1:
        return this->go_to(Gstate* state);
    }
}

std::string Door_1::go_to(Gstate* state){
    assert(state->scene == 1);
    switch(state->state & DOOR::unlocked) {
    case 0:
        return "You try to open the door, but it is locked.";
    case 1:
        state->scene = 2;
        return "You go through the door.";
    }
}

#endif
