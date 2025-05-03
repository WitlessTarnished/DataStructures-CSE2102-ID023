#include<iostream>
using namespace std;

using DeleteFunction = void (*)(int arr[], size_t &size, int param);

void DeleteByIndex(int arr[], size_t &size, int index)
{
    for(size_t i=index-1;i<size;i++)
    {
       arr[i]=arr[i+1];
    }
    size--;
}

void DeleteByValue(int arr[], size_t &size, int value)
{
    for(size_t i=0;i<size;)
    {
        if (arr[i] == value)
        {
            for (size_t j = i; j < size; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
        }
        else
        {
            i++;
        }
    }
}

void deleteElement(int arr[], size_t &size, int param, DeleteFunction func)
{
    func(arr,size,param);
}

void printArray(int arr[],size_t size){

    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={2,3,4,5,5,6,7,8};
    auto size=sizeof(arr)/sizeof(arr[0]);

    printArray(arr,size);

    deleteElement(arr,size,2,DeleteByIndex);

    printArray(arr,size);

    deleteElement(arr,size,5,DeleteByValue);

    printArray(arr,size);
}