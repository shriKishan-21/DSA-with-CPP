#include <bits/stdc++.h>
using namespace std;

int main()
{

    // ----------------------------------------------------------------------------------------------------------
    int arr[10];

    // printing the address of first memory block of array
    // 1. The address of the first memory block of array is the same as the address of the array itself
    cout << arr << endl;

    // 2. The address of the first memory block of array use the address operator (&)
    cout << &arr[0] << endl;

    // ----------------------------------------------------------------------------------------------------------
    int num[10] = {2, 6, 4, 0};

    // Well print the value of *nums
    cout << *num << endl;

    // some insights
    cout << *num + 1 << endl;   // it will print the *num value + 1
    cout << *(num + 1) << endl; // it will print the next memory block after 1st memory block
    cout << *(num) + 1 << endl; // it will print the *num value + 1

    // ----------------------------------------------------------------------------------------------------------
    int a[4] = {1, 2, 3, 4};

    // how arr[i] works
    cout << a[1] << endl;
    // it is actually of the form : *(arr+i)
    // +i means move to next memory block of the array(not adding the value of i to the address)

    // Also arr[i] = *(arr+i) or i[arr] = *(i+arr)
    int i = 2;
    cout << i[a] << endl;
    // both are correct and will give the same result

    // ---------------------------------------------------------------------------------------------------------

    int temp[10];
    cout << sizeof(temp) << endl;

    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl;

    // some insights
    cout << sizeof(*temp) << endl; // will give the size of the value at the address of temp array
    cout << sizeof(&temp) << endl; // will give the size of the address of temp array

    cout << sizeof(*ptr) << endl; // will give the size of the value at the address of ptr
    cout << sizeof(&ptr) << endl; // will give the size of the address of ptr

    // ---------------------------------------------------------------------------------------------------------

    int b[10] = {1, 2, 3, 5};

    cout << &b[0] << endl;
    cout << &b << endl;
    cout << b << endl;
    // The above three will give same result -> the address of first memory block

    int *p = &b[0];

    cout << p << endl;  // gives the address of a[0]
    cout << *p << endl; // gives the value at address stored in arr[0]
    cout << &p << endl; // gives the address of the pointer p

    // ---------------------------------------------------------------------------------------------------------

    int c[10];
    // if we try to change the arr
    // arr=arr+1;
    // it will give us error as symbol table content cannot be change

    int *pp = &arr[0];
    cout<<pp<<endl; // value stored in pp
    pp=pp+1; // increase the address inside the pp by 1(i.e 4 bytes as its int type)
    cout<<pp<<endl; // increased pp value will be given


    return 0;
}