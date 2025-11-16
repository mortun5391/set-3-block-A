#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>


using namespace std;

void insertion_sort(vector<int> &arr, int left, int right) {
    
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void hybrid_merge_sort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    if (right - left + 1 <= 15) {
        insertion_sort(arr, left, right);
        return;
    }
    int mid = (left + right) / 2;
    hybrid_merge_sort(arr, left, mid);
    hybrid_merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    hybrid_merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}