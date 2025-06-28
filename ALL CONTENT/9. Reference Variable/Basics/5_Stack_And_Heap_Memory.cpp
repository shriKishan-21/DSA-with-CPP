#include<bits/stdc++.h>
using namespace std;

int getSum(int *arr,int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter arr size :"<<endl;
    cin>>n;

    // Variable size array
    int* arr = new int[n];
    // int* arr --> static memory
    // new int[n] --> heap memory

    // taking input in array
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // ans[i] = *(arr+i);
    }

    int ans = getSum(arr,n);

    cout<<"Answer is :"<<ans<<endl;
}
