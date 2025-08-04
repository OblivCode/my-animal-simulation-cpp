#ifndef WINDOW_H
#define WINDOW_H

#include "../models/animals/animal.h"
#include "../models/foods/food.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

using namespace std;

class Window {
    public: 
        bool IsOpen();
        void ProcessEvents();
        void Render(const vector<unique_ptr<Animal>>& animals, const vector<unique_ptr<Food>>& foods);
        Window(unsigned int width,unsigned int height, string title);

    private:
        sf::RenderWindow m_window;
        // Textures
        sf::Texture m_rabbit_texture;
        sf::Texture m_wolf_texture;

        sf::Texture m_carrot_texture;
};

#endif