#include<iostream>
using namespace std;

void selectionsort(double *arr , int n){
    for (int i = 0; i < n; i++)
    {
        
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
               double temp = arr[j];
               arr[j] = arr[i];
               arr[i]=temp;
            }
            
        }
        
    }
    
}

int main(){
    double numbers[]{4,3,7,2,8,3,9,3};
    selectionsort(numbers,8);
    for(auto i : numbers){
        cout<<i<<" ";
    }
    cout<<endl;
}