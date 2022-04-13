#ifndef __DOOR_1_HPP_
#define __DOOR_1_HPP_

#include <string>
#include <assert>
#include "gstate.hpp"
#include "gobj.hpp"

/*
scene = 1
state |= 0b1
case 0: door is locked
case 1: door is unlocked

uses key (inv: 0b1)
*/
class Door_1 : Gobj; 

std::string Door_1::look_at(Gstate* state){
    assert(Gstate->scene == 1);
    switch(Gstate->state | 0b1) {
    case 0: 
        if(Gstate->inv | 0b1){
            return "The door is locked, but you have a key that looks like it might fit.";
        } else {
            return "The door is locked.";
        }
    case 1:
        return "The door is unlocked. It goes to **TODO**.";
    }
}

std::string Door_1::use(Gstate* state){
    assert(Gstate->scene == 1);
    switch(Gstate->state | 0b1) {
    case 0:       
        if(Gstate->state | 0b1){
            Gstate->state |= 07771;
            return "You use the key on the door. The door unlocks.";
        }
        break;
    case 1:
        return "You have nothing to use on the door."
    }
}

std::string Door_1::go_to(Gstate* state){
    assert(Gstate->scene == 1);
    switch(Gstate->state | 0b1) {
    case 0:
        return "You try to open the door, but it is locked.";
    case 1:
        Gstate->scene = 2;
        return "You go through the door.";
    }
}

#endif
