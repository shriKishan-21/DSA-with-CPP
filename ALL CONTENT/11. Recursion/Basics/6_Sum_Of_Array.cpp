#include<bits/stdc++.h>
using namespace std;


int getSum(int arr[], int n){
    // base case
    if(n==0) return 0;
    if(n==1) return arr[0];

    // processing
    int sum = 0;
    sum += arr[0];
    
    // recursive case
    return sum + getSum(arr+1, n-1);

    // can also be written as
    // return arr[0] + getSum(arr+1, n-1);
}
int main()
{
    int arr[5] = {1,2,3,9,5};
    int size = 5;
    cout<<getSum(arr,size);
}