#ifndef CARROT_H
#define CARROT_H

#include "food.h"
#include <iostream>

using namespace std;

class Carrot : public Food {
    public:
        Carrot(int start_x, int start_y) : Food(start_x, start_y, "Carrot") {}
};

#endif