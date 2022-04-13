#ifndef __GSTATE_HPP_
#define __GSTATE_HPP_

/*
inventory:
key: 0b1
paper: 0b10
*/

struct Gstate {
    int scene = 0;
    int state = 0;
    int inv = 0;
};

#endif
