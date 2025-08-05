#include "grid.h"
#include <cmath>
#include <algorithm>

using namespace std;

void Grid::AddAnimal(Animal* p_animal) {
    auto [x,y] = p_animal->GetPosition();
    Bucket* p_bucket = GetBucket(x,y);
    // Add to bucket
    if (p_bucket != nullptr) { 
        p_bucket->animals.push_back(p_animal);
    }
}
void Grid::AddFood(Food* p_food) {
    auto [x,y] = p_food->GetPosition();
    Bucket* p_bucket = GetBucket(x,y);
    // Add to bucket
    if (p_bucket != nullptr)
        p_bucket->foods.push_back(p_food);
}

// TODO: Implement scent range 
vector<Animal*>  Grid::GetNearbyAnimals(Animal* p_animal) {
    vector<Animal*> nearby;
    auto [x,y] = p_animal->GetPosition(); // Position of our animal

    vector<const Bucket*> buckets = GetBucketsByDistance(x,y, p_animal->GetScentRange());
    
    for (const Bucket* p_bucket : buckets) {
        nearby.insert(nearby.end(), p_bucket->animals.begin(), p_bucket->animals.end());
    }
    // Remove our animal
    nearby.erase(remove(nearby.begin(), nearby.end(), p_animal), nearby.end());
    return nearby;
}
// TODO: Implement scent range 
vector<Food*> Grid::GetNearbyFoods(Animal* p_animal) {
    vector<Food*> nearby;
    auto [x,y] = p_animal->GetPosition(); // Position of our animal

    vector<const Bucket*> buckets = GetBucketsByDistance(x,y, p_animal->GetScentRange());
    
    for (const Bucket* p_bucket : buckets) {
        nearby.insert(nearby.end(), p_bucket->foods.begin(), p_bucket->foods.end());
    }

    return nearby;
}

// Constructor
Grid::Grid(int width, int height, int cell_size) {
    m_rows = ceil(height / m_cell_size);
    m_cols = ceil(width / m_cell_size);
    m_buckets.resize(m_cols, vector<Bucket>(m_rows));
}

// Helper functions
Grid::Bucket* Grid::GetBucket(int pos_x, int pos_y) {
    // Translate positions to grid col and row
    int grid_col = pos_x / m_cell_size;
    int grid_row = pos_y / m_cell_size; 
    // Check validity
    if (grid_col < 0 || grid_col >= m_cols) {
        std::cerr << "Invalid bucket col: " << grid_col << std::endl;
        return nullptr;
    }
    if (grid_row < 0 || grid_row >= m_rows) {
        std::cerr << "Invalid bucket row: " << grid_row << std::endl;
        return nullptr;
    }
    // Return mutable pointer
    return &m_buckets[grid_row][grid_col];
}

const Grid::Bucket* Grid::GetBucket(int pos_x, int pos_y) const {
    // Translate positions to grid col and row
    int grid_col = pos_x / m_cell_size;
    int grid_row = pos_y / m_cell_size; 
    // Check validity
    if (grid_col < 0 || grid_col >= m_cols) {
        std::cerr << "Invalid bucket col: " << grid_col << std::endl;
        return nullptr;
    }
    if (grid_row < 0 || grid_row >= m_rows) {
        std::cerr << "Invalid bucket row: " << grid_row << std::endl;
        return nullptr;
    }
    // Return mutable pointer
    return &m_buckets[grid_row][grid_col];
}

vector<const Grid::Bucket*> Grid::GetBucketsByDistance(int pos_x, int pos_y, int range) const {
    // A temporary struct to hold a bucket and its distance to the animal
    struct BucketDistance {
        const Grid::Bucket* bucket;
        float distanceSq;
    };

    vector<BucketDistance> bucket_distances;
    int search_radius = range -1;

    int current_col = pos_x / m_cell_size;
    int current_row = pos_y / m_cell_size;

    // Collect all buckets within the maximum range
    for (int row = current_row - search_radius; row <= current_row + search_radius; ++row) {
        for (int col = current_col - search_radius; col <= current_col + search_radius; ++col) {
            if (row >= 0 && row < m_rows && col >= 0 && col < m_cols) {
                // Calculate the center position of the bucket
                float bucket_center_x = (col * m_cell_size) + (m_cell_size / 2.0f);
                float bucket_center_y = (row * m_cell_size) + (m_cell_size / 2.0f);
                // Calculate distance between the center of the bucket and our position
                // Then add to vector
                BucketDistance bd = {
                    &m_buckets[row][col],
                    GetDistanceSq((float)pos_x, (float)pos_y, bucket_center_x, bucket_center_y)
                };
                bucket_distances.push_back(bd);
            }
        }
    }
    // Sort the vector based on their distance, nearest first
    sort(bucket_distances.begin(), bucket_distances.end(),
        [](const BucketDistance& a, const BucketDistance&b) {
            return a.distanceSq < b.distanceSq;
        });
    // Create the sorted vector of bucket pointers
    vector<const Bucket*> sorted;
    for (const auto& bd: bucket_distances) {
        sorted.push_back(bd.bucket);
    }

    return sorted;
}

float Grid::GetDistanceSq(float x1, float y1, float x2, float y2) const {
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}


