#include <iostream>
using namespace std;

void printArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int linearSearch(int arr[], size_t size, int key) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[]{ 2, 3, 4, 5, 5, 6, 7, 8 };
    auto size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    int key = 5;
    int index = linearSearch(arr, size, key);
    
    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    }
    else {
        cout << "Element " << key << " not found." << endl;
    }

    return 0;
}
