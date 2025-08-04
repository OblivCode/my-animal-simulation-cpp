#include "window.h"
#include <optional>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../models/animals/animal.h"
#include "../models/foods/food.h"
#include "colours.h"

using namespace std;

bool Window::IsOpen() {
    return m_window.isOpen();
}

void Window::ProcessEvents() {
    while (optional<sf::Event> event = m_window.pollEvent()) {
        if(event->is<sf::Event::Closed>()) {
            m_window.close();
        }
    }
}

void Window::Render(const vector<unique_ptr<Animal>>& animals, const vector<unique_ptr<Food>>& foods) {
    m_window.clear(Colors::GRASS_GREEN);
    sf::Sprite sprite(m_rabbit_texture);
    const float target_size = 20.f;

    // Animals
    for (const auto& p_animal : animals){
        Animal* animal = p_animal.get();
        // Set texture based on animal species
        string animal_name = animal->GetName();
        if(animal_name == "Wolf") {
            sprite.setTexture(m_wolf_texture);
        } else if (animal_name == "Rabbit") {
            sprite.setTexture(m_rabbit_texture);
        }   
        else {
            std::cerr << "Invalid animal name: " << animal->GetName() << std::endl;
            return;
        }
        // Sprite scaling
        sf::Vector2u original_size = sprite.getTexture().getSize();
        float scale_factor_x = target_size / original_size.x;
        float scale_factor_y = target_size / original_size.y;
        sprite.setScale({scale_factor_x, scale_factor_y});
        // Positioning
        auto [x, y] = animal->GetPosition(); 
        sf::Vector2 pos = sf::Vector2(static_cast<float>(x), static_cast<float>(y));
        sprite.setPosition(pos);
        // Draw
        m_window.draw(sprite);
        
    }
    // Foods
    for (const auto& p_food :foods) {
        Food* food = p_food.get();
        // Set texture based on plant species
        if (food->GetName() == "Carrot") {
            sprite.setTexture(m_carrot_texture);
        } else {
            std::cerr << "Invalid food name: " << food->GetName() << std::endl;
            return;
        }
        // Sprite scaling
        sf::Vector2u original_size = sprite.getTexture().getSize();
        float scale_factor_x = target_size / original_size.x;
        float scale_factor_y = target_size / original_size.y;
        sprite.setScale({scale_factor_x, scale_factor_y});
        // Positioning
        auto [x, y] = food->GetPosition(); 
        sf::Vector2 pos = sf::Vector2(static_cast<float>(x), static_cast<float>(y));
        sprite.setPosition(pos);
        // Draw
        m_window.draw(sprite);
    }
    m_window.display();                                                                                                                                                                                                                                            
}

Window::Window(unsigned int width, unsigned  int height, string title) : m_window(sf::VideoMode({width, height}), title) {
    // Load textures
    const string images_folder = "src/images/";
    if (!m_rabbit_texture.loadFromFile(images_folder + "rabbit.png")) 
        std::cerr << "Error loading rabbit.png" << std::endl;
    if (!m_wolf_texture.loadFromFile(images_folder + "wolf.png")) 
        std::cerr << "Error loading wolf.png" << std::endl;
    if (!m_carrot_texture.loadFromFile(images_folder + "carrot.png")) 
        std::cerr << "Error loading carrot.png" << std::endl;
}