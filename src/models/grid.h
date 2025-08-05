#ifndef GRID_H
#define GRID_H

#include <vector>
#include <memory>
#include "animals/animal.h"
#include "foods/food.h"

using namespace std;

class Grid {
    public:
        void AddAnimal(Animal* p_animal);
        void AddFood(Food* p_food);

        vector<Animal*> GetNearbyAnimals(Animal* p_animal);
        vector<Food*> GetNearbyFoods(Animal* p_animal);

        void Clear();

        Grid(int width, int height, int cell_size);

    private:
        int m_cell_size;
        int m_rows; // Dependent on Y max coord
        int m_cols; // Dependent on X max coord

        // A 2D grid of "buckets". Each bucket holds lists of pointers.
        struct Bucket {
            std::vector<Animal*> animals;
            std::vector<Food*> foods;
        };
        std::vector<std::vector<Bucket>> m_buckets;
        Bucket* GetBucket(int pos_x, int pos_y);
        const Bucket* GetBucket(int pos_x, int pos_y) const;
        vector<const Bucket*> GetBucketsByDistance(int pos_x, int pos_y, int range) const;

        float GetDistanceSq(float x1, float y1, float x2, float y2) const;
};

#endif