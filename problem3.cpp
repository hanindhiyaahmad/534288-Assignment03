#include <iostream>

using namespace std;

int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int* arr, int n, int target) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int* generateSortedArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 2 * i; 
    }
    return arr;
}

void testSearches(int n) {
    int* arr = generateSortedArray(n);
    int targetExists = arr[n / 2]; 
    int targetNotExists = -1;      

    int idxLinear = linearSearch(arr, n, targetExists);
    int idxBinary = binarySearch(arr, n, targetExists);

    cout << "Size n=" << n << " | Target Exists (" << targetExists << "): Linear=" 
              << idxLinear << ", Binary=" << idxBinary << endl;

    idxLinear = linearSearch(arr, n, targetNotExists);
    idxBinary = binarySearch(arr, n, targetNotExists);

    cout << "Size n=" << n << " | Target Missing (" << targetNotExists << "): Linear=" 
              << idxLinear << ", Binary=" << idxBinary << endl;

    delete[] arr;
}

int main() {
    int sizes[] = {10, 100, 1000};
    for (int n : sizes) {
        testSearches(n);
    }
    return 0;
}
