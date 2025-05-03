#include<iostream>
using namespace std;

int main(){
    int arr[]{2,3,4,5,6,7,8};

    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}