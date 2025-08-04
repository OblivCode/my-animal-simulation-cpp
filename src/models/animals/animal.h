#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal {
    public:
        virtual ~Animal() = default;
        
        // Getters
        tuple<int, int> GetPosition();
        string GetName();
        int GetAge();
        // General functions
        void Move(int x, int y);
        // Constructor
        Animal(int start_x, int start_y, string name);
    private:
        tuple<int, int> position;
        string name;
        int age;
};

#endif