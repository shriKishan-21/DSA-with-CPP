// ARRAY WITH FUNCTION

#include<iostream>
using namespace std;

int printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={2,4,7,3,5,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
}