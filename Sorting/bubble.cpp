#include<iostream>
using namespace std;

void bubblesort(double *arr , int n){
    for (int i = 0; i < n-1; i++)
    {
        
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
               double temp = arr[j+1];
               arr[j+1] = arr[j];
               arr[j]=temp;
            }
            
        }
        
    }
    
}

int main(){
    double numbers[]{4,3,7,2,8,3,9,3};
    bubblesort(numbers,8);
    for(auto i : numbers){
        cout<<i<<" ";
    }
    cout<<endl;
}