#include <iostream>
#include <vector>
#include <fstream>
#include "ArrayGenerator.h"
#include "SortTester.h"
#include "Algorithms.h"

int main() {
    ArrayGenerator generator;
    SortTester tester;
    
    std::vector<int> sizes;
    for (int size = 500; size <= 10000; size += 100) {
        sizes.push_back(size);
    }
    
    std::vector<int> thresholds = {5, 10, 15, 20, 30, 50};
    
    std::ofstream randomFile("random_results.csv");
    std::ofstream reverseFile("reverse_results.csv");
    std::ofstream almostFile("almost_results.csv");
    
    randomFile << "Size,Standard";
    reverseFile << "Size,Standard";
    almostFile << "Size,Standard";
    
    for (int threshold : thresholds) {
        randomFile << ",Hybrid_" << threshold;
        reverseFile << ",Hybrid_" << threshold;
        almostFile << ",Hybrid_" << threshold;
    }
    randomFile << "\n";
    reverseFile << "\n";
    almostFile << "\n";
    
    for (int size : sizes) {
        std::cout << "Testing size: " << size << std::endl;
        
        auto randomArr = generator.generateRandom(size);
        long long standardTime = tester.measureTime(standard_merge_sort, randomArr);
        
        randomFile << size << "," << standardTime;
        
        for (int threshold : thresholds) {
            auto hybridFunc = [threshold](std::vector<int>& arr, int l, int r) {
                hybrid_merge_sort(arr, l, r, threshold);
            };
            long long hybridTime = tester.measureTime(hybridFunc, randomArr);
            randomFile << "," << hybridTime;
        }
        randomFile << "\n";
        
        auto reverseArr = generator.generateReverseSorted(size);
        standardTime = tester.measureTime(standard_merge_sort, reverseArr);
        
        reverseFile << size << "," << standardTime;
        
        for (int threshold : thresholds) {
            auto hybridFunc = [threshold](std::vector<int>& arr, int l, int r) {
                hybrid_merge_sort(arr, l, r, threshold);
            };
            long long hybridTime = tester.measureTime(hybridFunc, reverseArr);
            reverseFile << "," << hybridTime;
        }
        reverseFile << "\n";
        
        auto almostArr = generator.generateAlmostSorted(size);
        standardTime = tester.measureTime(standard_merge_sort, almostArr);
        
        almostFile << size << "," << standardTime;
        
        for (int threshold : thresholds) {
            auto hybridFunc = [threshold](std::vector<int>& arr, int l, int r) {
                hybrid_merge_sort(arr, l, r, threshold);
            };
            long long hybridTime = tester.measureTime(hybridFunc, almostArr);
            almostFile << "," << hybridTime;
        }
        almostFile << "\n";
    }
    
    randomFile.close();
    reverseFile.close();
    almostFile.close();
    
    std::cout << "Experiment completed! Results saved to CSV files." << std::endl;
    
    return 0;
}