#include<bits/stdc++.h>
using namespace std;


bool linearSearch(int arr[], int size, int key){
    // base case
    if(size==0) return false;

    // processing
    if(arr[0]==key){
        return true;
    }

    // recursive case
    return linearSearch(arr+1, size-1,key);
}
int main()
{
    int arr[5] = {1,2,3,9,5};
    int size = 5;
    int key = 6;
    cout<<linearSearch(arr,size,key);
}