#include<iostream>
using namespace std;

void printArray(int arr[], size_t size) {
    for (size_t i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void InsertInArray(int arr[],size_t& size,int index,int value){
    if (index < 1 || index > size)
        return;

    for (int i = size - 1; i >= index; i--)
    {
        arr[i+1]=arr[i];
       }

       arr[index]=value;
       ++size; 
}

int main(){
    int arr[]={2,3,4,5,5,6,7,8};
    
    auto size=sizeof(arr)/sizeof(arr[0]);

    printArray(arr,size);

    InsertInArray(arr,size,2,10);

    printArray(arr,size);
}