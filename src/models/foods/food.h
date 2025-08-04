#ifndef FOOD_H
#define FOOD_H

#include <string>
using namespace std;

class Food {
    public:
        virtual ~Food() = default;

        tuple<int, int> GetPosition(); 
        string GetName();

        Food(int start_x, int start_y, string food_name);
    private:
        string name;
        tuple<int, int> position;
};


#endif