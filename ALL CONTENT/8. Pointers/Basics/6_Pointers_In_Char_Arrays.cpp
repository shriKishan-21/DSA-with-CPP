#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch[6] = "abcde";

    cout<<ch<<endl;
    // this will print the string itself till the termination "\0"
    // Whyy ??
    // Because cout work differently on char array

    char *cp = &ch[0];
    cout<<cp<<endl;
    // this will print all the character one by one till the termination "\0"
    // because cout work differently on char array

    // What if there is no null character in the array
    char temp = 'z';
    char *p = &temp;
    cout<<p<<endl;
    // this will print the char z and other garbage value till it didnt find the null character


    // Memory Allocation in character array -->
    char ch[6] = "abcdf";
    // temp memory <---  "abcdf"
    // memory ch ---> copy temp
    // it is good to use this

    char *c = "abcde";
    // temp memory <---  "abcde"
    // pointer c  ---> stores the address of first character
    // This is super risky to use , so do not use this

    return 0;
}