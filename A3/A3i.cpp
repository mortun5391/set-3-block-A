#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

void insertionSort(vector<int>& arr, int left, int right) {
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

void heapSort(vector<int>& arr, int left, int right) {
    make_heap(arr.begin() + left, arr.begin() + right + 1);
    sort_heap(arr.begin() + left, arr.begin() + right + 1);
}

int partition(vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    
    if (arr[mid] < arr[left]) swap(arr[left], arr[mid]);
    if (arr[right] < arr[left]) swap(arr[left], arr[right]);
    if (arr[right] < arr[mid]) swap(arr[mid], arr[right]);
    
    int pivot = arr[mid];
    swap(arr[mid], arr[right - 1]);
    
    int i = left;
    int j = right - 1;
    
    while (true) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);
        if (i < j) swap(arr[i], arr[j]);
        else break;
    }
    swap(arr[i], arr[right - 1]);
    return i;
}

void introsort(vector<int>& arr, int left, int right, int depthLimit) {
    if (left >= right) return;
    
    if (right - left < 16) {
        insertionSort(arr, left, right);
        return;
    }
    
    if (depthLimit == 0) {
        heapSort(arr, left, right);
        return;
    }
    
    int p = partition(arr, left, right);
    introsort(arr, left, p - 1, depthLimit - 1);
    introsort(arr, p + 1, right, depthLimit - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if (n > 0) {
        int depthLimit = 2 * log2(n);
        introsort(arr, 0, n - 1, depthLimit);
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}