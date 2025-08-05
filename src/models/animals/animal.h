#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <vector>
#include <tuple>

class Grid;
using namespace std;

class Animal {
    public:
        virtual ~Animal() = default;
        //Pure virtual (=0) means every child class MUST implement its own version.
        virtual void Update(Grid& grid) = 0;
        
        // Getters
        tuple<int, int> GetPosition();
        string GetName();
        int GetAge();
        int GetScentRange();
        // General functions
        void Move(int x, int y);
        // Constructor
        Animal(int start_x, int start_y, string name);
    protected:
        tuple<int, int> position;
        string name;
        int age;
        int hunger; //percentage
        int scent_range; // By buckets
        vector<string> diet; //stores names of things this will eat. Format: food:carrot, animal:rabbit, etc
};

#endif