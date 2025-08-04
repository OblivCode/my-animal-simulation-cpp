#ifndef COLORS_H
#define COLORS_H

#include <SFML/Graphics.hpp>

namespace Colors {
    // Basic colors
    const sf::Color BLACK(0, 0, 0);
    const sf::Color WHITE(255, 255, 255);
    const sf::Color RED(255, 0, 0);
    const sf::Color GREEN(0, 255, 0);
    const sf::Color BLUE(0, 0, 255);
    const sf::Color YELLOW(255, 255, 0);
    const sf::Color MAGENTA(255, 0, 255);
    const sf::Color CYAN(0, 255, 255);
    
    // Nature colors
    const sf::Color GRASS_GREEN(34, 139, 34);
    const sf::Color FOREST_GREEN(34, 100, 34);
    const sf::Color SAND(238, 203, 173);
    const sf::Color SKY_BLUE(135, 206, 235);
    
    
    // Food colors
    const sf::Color CARROT_ORANGE(255, 165, 0);
    const sf::Color BERRY_PURPLE(128, 0, 128);
    const sf::Color APPLE_RED(220, 20, 60);
    
    // UI colors
    const sf::Color DARK_GRAY(64, 64, 64);
    const sf::Color LIGHT_GRAY(192, 192, 192);
    const sf::Color BACKGROUND(25, 25, 25);
}

#endif