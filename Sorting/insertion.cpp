#include<iostream>
using namespace std;


void insertionsort(double* arr, int n){
    double x;
    int j;
    for(int i = 1 ; i<n; i ++){
       j = i-1;
       x = arr[i];
       while(j> -1 && arr[j]> x){
         arr[j+1] = arr[j];
         j--;
       }
       arr[j+1] = x;
       
    }
}
int main(){
    double numbers[]{4,3,7,2,8,3,9,3};
   insertionsort(numbers,8);
    for(auto i : numbers){
        cout<<i<<" ";
    }
    cout<<endl;
}