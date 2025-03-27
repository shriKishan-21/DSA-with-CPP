// LINEAR SEARCH

#include<iostream>
using namespace std;

int linearSerach(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return 0;
}

int main(){
    int arr[]={1,77,43,7,63,24,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=9;
    if(linearSerach(arr,size,key)!=0){
        cout<<"Key found at index:"<<linearSerach(arr,size,key)<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    
}