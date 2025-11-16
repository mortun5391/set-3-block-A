#pragma once
#include <vector>
#include <random>
#include <algorithm>

class ArrayGenerator {
private:
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;
    
public:
    ArrayGenerator() : gen(std::random_device{}()), dist(0, 6000) {}
    
    std::vector<int> generateRandom(int size) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = dist(gen);
        }
        return arr;
    }
    
    std::vector<int> generateReverseSorted(int size) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = size - i;
        }
        return arr;
    }
    
    std::vector<int> generateAlmostSorted(int size, int swaps = 100) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
        
        for (int i = 0; i < swaps; i++) {
            int idx1 = rand() % size;
            int idx2 = rand() % size;
            std::swap(arr[idx1], arr[idx2]);
        }
        return arr;
    }
};