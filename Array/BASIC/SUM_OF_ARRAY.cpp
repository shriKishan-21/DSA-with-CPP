// SUM OF AN ARRAY

#include<iostream>
using namespace std;

int sum(int arr[],int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
   }

   int main(){
    int arr[]={3,6,-2,6,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Sum is: "<<sum(arr,size)<<endl;
   }