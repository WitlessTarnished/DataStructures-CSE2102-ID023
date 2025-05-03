#include<iostream>
using namespace std;

void printArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int BinarySearch ( int* arr , int size, int value){
    int low = 0;
    int high = size -1;
    int mid;

    while (high >= low)
    {
        mid = (high+low)/2;
        if (value == arr[mid])
        {
            return mid;
        }else if (value < arr[mid]){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
        
    }
    return -1;   
}

int main(){
    int arr[]{2,3,4,5,5,6,7,8};
    auto size = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,size);
    int key = 5;
    int index = BinarySearch(arr, size, key);
    
    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found." << endl;
    }
}