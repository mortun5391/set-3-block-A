#include <iostream>
#include <vector>
#include <fstream>
#include "ArrayGenerator.h"
#include "SortTester.h"
#include "Algorithms.h"

int main() {
    ArrayGenerator generator;
    SortTester tester;
    SortingAlgorithms algorithms;
    
    std::vector<int> sizes;
    for (int size = 500; size <= 100000; size += 1000) {
        sizes.push_back(size);
    }
    
    std::ofstream randomFile("quick_random_results.csv");
    std::ofstream reverseFile("quick_reverse_results.csv");
    std::ofstream almostFile("quick_almost_results.csv");
    
    randomFile << "Size,StandardQuickSort,HybridQuickSort\n";
    reverseFile << "Size,StandardQuickSort,HybridQuickSort\n";
    almostFile << "Size,StandardQuickSort,HybridQuickSort\n";
    
    std::cout << "Starting Quick Sort experiments..." << std::endl;
    
    for (int size : sizes) {
        std::cout << "Testing size: " << size << std::endl;
        
        auto randomArr = generator.generateRandom(size);
        
        auto standardQuick = [&](std::vector<int>& arr, int l, int r) {
            algorithms.standardQuickSort(arr, l, r);
        };
        
        auto hybridQuick = [&](std::vector<int>& arr, int l, int r) {
            algorithms.hybridQuickSort(arr, l, r);
        };
        
        long long standardTime = tester.measureTime(standardQuick, randomArr);
        long long hybridTime = tester.measureTime(hybridQuick, randomArr);
        
        randomFile << size << "," << standardTime << "," << hybridTime << "\n";
        
        auto reverseArr = generator.generateReverseSorted(size);
        standardTime = tester.measureTime(standardQuick, reverseArr);
        hybridTime = tester.measureTime(hybridQuick, reverseArr);
        
        reverseFile << size << "," << standardTime << "," << hybridTime << "\n";
        
        auto almostArr = generator.generateAlmostSorted(size);
        standardTime = tester.measureTime(standardQuick, almostArr);
        hybridTime = tester.measureTime(hybridQuick, almostArr);
        
        almostFile << size << "," << standardTime << "," << hybridTime << "\n";
    }
    
    randomFile.close();
    reverseFile.close();
    almostFile.close();
    
    std::cout << "Experiments completed! Results saved to CSV files." << std::endl;
    
    return 0;
}