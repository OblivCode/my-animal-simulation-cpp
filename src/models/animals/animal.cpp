#include "animal.h"

using namespace std;


// Getters
tuple<int, int> Animal::GetPosition(){
    return position;
}
string Animal::GetName() {
    return name;
}
int Animal::GetAge() {
    return age;
}
// General functions
void Animal::Move(int x, int y) {
    int new_x = get<0>(position) + x;
    int new_y = get<1>(position) + y;

    position = make_tuple(new_x, new_y);
}
// Constructor
Animal::Animal(int start_x, int start_y, string animal_name) {
    position = make_tuple(start_x, start_y);
    name = animal_name;
    age = 0; // Default starting age

    std::cout << "A " << name <<" has been birthed at position (" << start_x << ", " << start_y << ")." << std::endl;
}