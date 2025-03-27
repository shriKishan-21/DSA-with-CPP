// MAX AND MIN IN AN ARRAY

#include<iostream>
using namespace std;

int max(int arr[],int size){
    int max_element=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]>max_element){
            max_element=arr[i];
        }
    }
    return max_element;
}

int min(int arr[],int size){
    int min_element=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]<min_element){
            min_element=arr[i];
        }
    }
    return min_element;
}
int main() {
    //int arr[]={2,4,7,3,5,8};
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"MAximum element is: "<<max(arr,size)<<endl;
    cout<<"Minimum element is: "<<min(arr,size)<<endl;
    }
    

   
