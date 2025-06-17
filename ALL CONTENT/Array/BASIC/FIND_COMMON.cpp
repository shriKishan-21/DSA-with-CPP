// FINDING COMMON ELEMENTS IN TWO ARRAY AND STORING IT IN ANOTHER ARRAY

#include<iostream>
using namespace std;

int main(){

    int arr1[]={1,2,3,4,5};
    int arr2[]={2,4,6,7,8};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    int count=0;
    int size=max(size1,size2);
    int num[size-1];

    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if(arr1[i]==arr2[j]){
                count++;
                num[i]=arr1[i];
            }
        }
    }
    for(int i=0;i<count;i++){
        if(num[i]!=0){
            cout<<num[i]<<" ";
        }
        
    }
}