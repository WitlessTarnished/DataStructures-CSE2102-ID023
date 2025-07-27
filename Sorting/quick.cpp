#include<iostream>
using namespace std;

int partition(double* arr, int low, int high) {
    double pivot = arr[high]; 
    int i = low - 1; 
    
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quicksort(double *arr, int low,int high){
    if(low<high){
        int pi = partition(arr, low ,high);
    quicksort(arr,low , pi-1);
    quicksort(arr, pi+1 , high);
    }
}
int main(){
    double numbers[]{4,3,7,2,8,3,9,3};
    quicksort(numbers,0,7);
    for(auto i : numbers){
        cout<<i<<" ";
    }
    cout<<endl;
}