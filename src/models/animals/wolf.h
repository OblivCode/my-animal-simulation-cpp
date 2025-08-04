#ifndef WOLF_H
#define WOLF_H

#include "animal.h"

using namespace std;

class Wolf : public Animal {
    public:
        Wolf(int start_x, int start_y) : Animal(start_x, start_y, "Wolf")
        {
            
        }
};

#endif