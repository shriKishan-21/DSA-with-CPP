// REVERSE AN ARRAY

#include<iostream>
using namespace std;

int reverseArray(int arr[],int size){
    int i=0;
    int j=size-1;
    while(j>=i){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    return 0;
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr1[]={1,2,3,4,5,6};
    int arr2[]={9,8,7,6,5};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    cout<<"Original Array 1:";
    printArray(arr1,size1);
    reverseArray(arr1,size1);
    cout<<"Reversed Array:";
    printArray(arr1,size1);

    cout<<"Original Array 2:";
    printArray(arr2,size2); 
    reverseArray(arr2,size2);
    cout<<"Reversed Array 2:";
    printArray(arr2,size2);

}

