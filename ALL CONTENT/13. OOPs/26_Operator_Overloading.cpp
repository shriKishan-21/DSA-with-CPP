// operator overloading
// operator overloading is the process of defining operators for user defined data types

#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
    int a;
    int b;

    // using + operator to subtract two objects
    void operator+ (A &obj)
    {
        int value1 = this->a; // current object
        int value2 = obj.a; // passed object
        cout<< "Output :"<<value1-value2<<endl;
    }
};

int main()
{
    A obj1 , obj2;

    obj1.a = 10;
    obj2.b = 20;

    // this will call the + operator
    obj1 + obj2;

    return 0;
}