#include<iostream>
using namespace std;

int main()
{
    const int a=10;
    // int a becomes constant
    // its value can not be changed after initialization
    cout<<a;

    return 0;
}

// Keep in mind that constant variable needs to be assigned during initialization only
// otherwise it will store garbage value that cannot be changed further