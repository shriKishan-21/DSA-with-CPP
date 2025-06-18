#include<bits/stdc++.h>
using namespace std;

int main()
{

// ----------------------------------------------------------------------------------------------------------
    int arr[10];

    // printing the address of first memory block of array
    // 1. The address of the first memory block of array is the same as the address of the array itself
    cout<<arr<<endl;

    // 2. The address of the first memory block of array use the address operator (&)
    cout<<&arr[0]<<endl;

// ----------------------------------------------------------------------------------------------------------
    int num[10]={2,6,4,0};

    // Well print the value of *nums
    cout<<*num<<endl;

    // some insights
    cout<<*num+1<<endl; // it will print the *num value + 1
    cout<<*(num+1)<<endl; // it will print the next memory block after 1st memory block
    cout<<*(num)+1<<endl; // it will print the *num value + 1

// ----------------------------------------------------------------------------------------------------------
    int a[4]={1,2,3,4};
    
    // how arr[i] works
    cout<<a[1]<<endl;
    // it is actually of the form : *(arr+i)
    // +i means move to next memory block of the array(not adding the value of i to the address)

    // Also arr[i] = *(arr+i) or i[arr] = *(i+arr)
    int i =2;
    cout<<i[a]<<endl;
    // both are correct and will give the same result

// ---------------------------------------------------------------------------------------------------------



    return 0;
}