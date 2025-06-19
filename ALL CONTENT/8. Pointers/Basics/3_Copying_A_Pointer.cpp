#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num = 10;
    int *ptr = &num;

    // crating a 2nd pointer ptr2 which is a copy of ptr
    int *ptr2 = ptr;

    cout << ptr << endl;
    cout << ptr2 << endl;
    
    return 0;
}