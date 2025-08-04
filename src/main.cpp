#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>

#include "ui/window.h"

#include "models/animals/animal.h"
#include "models/animals/rabbit.h"
#include "models/animals/wolf.h"

#include "models/foods/food.h"
#include "models/foods/carrot.h"


int main() {
    // Create window
    Window window(300,300,"Simulation");

    // Animals
    std::vector<std::unique_ptr<Animal>> animal_population;

    animal_population.push_back(std::make_unique<Rabbit>(100, 150));
    animal_population.push_back(std::make_unique<Wolf>(100, 100));
    animal_population.push_back(std::make_unique<Rabbit>(150, 100));   
    // Foods
    vector<unique_ptr<Food>> food_population;

    food_population.push_back(make_unique<Carrot>(150,150));
    // Loop
    while (window.IsOpen()) {
        window.ProcessEvents();
        window.Render(animal_population, food_population);
    }
    return 0;
}
