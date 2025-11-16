#pragma once
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

class SortingAlgorithms {
private:
    std::mt19937 gen;
    
    void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(std::vector<int>& arr, int left, int right) {
        int n = right - left + 1;
        
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, left + i);

        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[left], arr[left + i]);
            heapify(arr, i, left);
        }
    }

    void insertionSort(std::vector<int>& arr, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int key = arr[i];
            int j = i - 1;
            
            while (j >= left && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    int partition(std::vector<int>& arr, int left, int right) {
        int pivotIndex = left + gen() % (right - left + 1);
        std::swap(arr[pivotIndex], arr[right]);
        
        int pivot = arr[right];
        int i = left - 1;
        
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[right]);
        return i + 1;
    }

public:
    SortingAlgorithms() : gen(std::random_device{}()) {}

    void standardQuickSort(std::vector<int>& arr, int left, int right) {
        if (left >= right) return;
        
        int pivot = partition(arr, left, right);
        standardQuickSort(arr, left, pivot - 1);
        standardQuickSort(arr, pivot + 1, right);
    }

    void introSort(std::vector<int>& arr, int left, int right, int depthLimit) {
        int size = right - left + 1;
        
        if (size < 16) {
            insertionSort(arr, left, right);
            return;
        }
        
        if (depthLimit == 0) {
            heapSort(arr, left, right);
            return;
        }
        
        int pivot = partition(arr, left, right);
        introSort(arr, left, pivot - 1, depthLimit - 1);
        introSort(arr, pivot + 1, right, depthLimit - 1);
    }

    void hybridQuickSort(std::vector<int>& arr, int left, int right) {
        int depthLimit = 2 * log2(right - left + 1);
        introSort(arr, left, right, depthLimit);
    }
};