#ifndef __DOOR_1_HPP_
#define __DOOR_1_HPP_

#include <string>
#include <assert.h>
#include "gstate.hpp"

/*
scene = 1
state |= 0b1
case 0: door is locked
case 1: door is unlocked

uses key (INV::key1)
*/
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
    switch(state->state | INV::key1) {
    case 0: 
        if(state->inv | INV::key1){
            return "The door is locked, but you have a key that looks like it might fit.";
        } else {
            return "The door is locked.";
        }
    case 1:
        return "The door is unlocked. It goes to another room. You hear something growling.";
    }
}

std::string Door_1::use(Gstate* state){
    assert(state->scene == 1);
    switch(state->state | INV::key1) {
    case 0:       
        if(state->state | INV::key1){
            state->state |= 01;
            return "You use the key on the door. The door unlocks.";
        }
        break;
    case 1:
        return "You have nothing to use on the door.";
    }
}

std::string Door_1::go_to(Gstate* state){
    assert(state->scene == 1);
    switch(state->state | INV::key1) {
    case 0:
        return "You try to open the door, but it is locked.";
    case 1:
        state->scene = 2;
        return "You go through the door.";
    }
}

#endif
