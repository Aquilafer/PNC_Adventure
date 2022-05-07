#ifndef __GSTATE_HPP_
#define __GSTATE_HPP_

// constants representing inventory items
namespace INV 
{
	const int key1 = 0b001;
	const int sword = 0b010;
	const int key2 = 0b100;
}

struct Gstate {
    int scene = 0;
    int state = 0;
    int inv = 0;
};

#endif
