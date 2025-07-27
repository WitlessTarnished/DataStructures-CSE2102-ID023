#include<iostream>
using namespace std;

void merge(double* arr, int low, int mid, int high){
    int i  = low;
    int j = mid+1;
    int k = low;
    double* temp = new double[high+1];

    while(i<= mid && j <= high){
      if(arr[i] < arr[j]){
     temp[k++] = arr[i++];
      }else{
        temp[k++] = arr[j++];
      }
    }
    for(;i<=mid;i++){temp[k++]=arr[i++];}
     for(;j<=high;j++){temp[k++]=arr[j++];}

     for(int l = low; l<=high ; l++){arr[l]=temp[l];}
   delete []temp;
}

void mergesort(double* arr, int low, int high){
    double mid;
    if(low < high){
        mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr,mid+1, high);
        merge(arr, low,mid, high);
    }
}   

int main(){
    double numbers[]{4,3,7,2,8,3,9,3};
 mergesort(numbers,0,7);
    for(auto i : numbers){
        cout<<i<<" ";
    }
    cout<<endl;
}

