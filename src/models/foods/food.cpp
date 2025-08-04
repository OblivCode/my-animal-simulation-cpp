#include "food.h"

#include "iostream"

using namespace std;

tuple<int, int> Food::GetPosition() {
    return position;
}
string Food::GetName() {
    return name;
}

Food::Food(int start_x, int start_y, string food_name) {
    position = make_tuple(start_x, start_y);
    name = food_name;
    std::cout << "A "<< name <<" has sprouted at position (" << start_x << ", " << start_y << ")." << std::endl;
}