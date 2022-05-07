#ifndef __TABLE_HPP_
#define __TABLE_HPP_

#include <string>
#include <assert.h>
#include "gstate.hpp"

/*
scene = 1
uses key (INV::key1)
*/

class Table
{
public:
Table();
~Table();

std::string look_at(Gstate* state);
std::string use(Gstate* state);
std::string go_to(Gstate* state);
};

std::string Table::look_at(Gstate* state){
    assert(state->scene == 1);
    switch(state->inv & INV::key1) {
    case 0: 
	state->inv |= INV::key1;
        return "You think you see something useful on the table. Upon closer inspection, you spy an old-looking brass key. You wonder whether it will fit the keyhole in the door as you pocket it. You now have a KEY!";
    case 1:
        return "After picking up the key, there is nothing left on or under the table.";
    }
}

std::string Table::use(Gstate* state){
    assert(state->scene == 1);
    return "The table is akward to pick up. You don't see any particular use for it.";
}

std::string Table::go_to(Gstate* state){
    assert(state->scene == 1);
    return this->look_at(state);
}

#endif
