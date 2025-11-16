#pragma once
#include <vector>
#include <chrono>
#include <functional>

class SortTester {
public:
    template<typename Func>
    long long measureTime(Func sortFunc, std::vector<int>& arr, int runs = 3) {
        long long totalTime = 0;
        
        for (int i = 0; i < runs; i++) {
            std::vector<int> temp = arr;
            
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(temp, 0, temp.size() - 1);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            
            totalTime += std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
            
            if (!isSorted(temp)) {
                return -1;
            }
        }
        
        return totalTime / runs;
    }

private:
    bool isSorted(const std::vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) return false;
        }
        return true;
    }
};