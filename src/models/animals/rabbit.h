#ifndef RABBIT_H
#define RABBIT_H

#include "animal.h"

using namespace std;

class Rabbit : public Animal {
    public:
        Rabbit(int start_x, int start_y) : Animal(start_x, start_y, "Rabbit")
        {
            
        }
};

#endif