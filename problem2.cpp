#include <iostream>
#include <iomanip>

struct DynArray {
    int* data;
    int size;
    int capacity;
};

// O(1)
void initArray(DynArray& a) {
    a.capacity = 2;
    a.size = 0;
    a.data = new int[a.capacity];
}

// O(1)
void freeArray(DynArray& a) {
    delete[] a.data;
    a.data = nullptr;
    a.size = 0;
    a.capacity = 0;
}

// O(1) amortized
void pushBack(DynArray& a, int value) {
    if (a.size == a.capacity) {
        int newCapacity = a.capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        delete[] a.data;
        a.data = newData;
        a.capacity = newCapacity;
    }
    a.data[a.size] = value;
    a.size++;
}

// O(n)
void insertAt(DynArray& a, int index, int value) {
    if (a.size == a.capacity) {
        int newCapacity = a.capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        delete[] a.data;
        a.data = newData;
        a.capacity = newCapacity;
    }
    
    for (int i = a.size; i > index; i--) {
        a.data[i] = a.data[i - 1];
    }
    a.data[index] = value;
    a.size++;
}

// O(n)
void removeAt(DynArray& a, int index) {
    for (int i = index; i < a.size - 1; i++) {
        a.data[i] = a.data[i + 1];
    }
    a.size--;
}

// O(1)
int getAt(const DynArray& a, int index) {
    return a.data[index];
}

// O(1)
void setAt(DynArray& a, int index, int value) {
    a.data[index] = value;
}

// O(n)
void printDynArr(const DynArray& a) {
    std::cout << "[";
    for (int i = 0; i < a.size; i++) {
        std::cout << a.data[i];
        if (i < a.size - 1) std::cout << ", ";
    }
    std::cout << "] (size=" << a.size << ", cap=" << a.capacity << ")" << std::endl;
}

int main() {
    DynArray arr;
    initArray(arr);

    // 1. pushBack until a resize is triggered
    for (int i = 1; i <= 5; i++) {
        pushBack(arr, i * 10);
    }
    printDynArr(arr); // Expected: [10, 20, 30, 40, 50] (size=5, cap=8)

    // 2. insertAt
    insertAt(arr, 2, 25);
    printDynArr(arr); // Expected: [10, 20, 25, 30, 40, 50] (size=6, cap=8)

    // 3. removeAt
    removeAt(arr, 0);
    printDynArr(arr); // Expected: [20, 25, 30, 40, 50] (size=5, cap=8)

    // 4. getAt / setAt
    std::cout << "Element at index 2: " << getAt(arr, 2) << "\n"; // Expected: 30
    setAt(arr, 2, 99);
    printDynArr(arr); // Expected: [20, 25, 99, 40, 50] (size=5, cap=8)

    freeArray(arr);

    return 0;
}
