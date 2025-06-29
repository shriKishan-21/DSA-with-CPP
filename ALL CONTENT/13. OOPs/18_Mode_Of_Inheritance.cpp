// Mode of inheritance -->
// 1. Public Inheritance
// 2. Private Inheritance
// 3. Protected Inheritance
/*
super class                          sub class 
(Access modifier of property         (Mode of Inheritance)
and data members)

Public                                Public                  --------->       Public
Public                                Private                 --------->       Private
Public                                Protected               --------->       Protected
Protected                             Public                  --------->       Protected
Protected                             Private                 --------->       Private
Protected                             Protected               --------->       Protected
Private                               Public                  --------->       Not Accessible
Private                               Private                 --------->       Not Accessible
Private                               Protected               --------->       Not Accessible
*/

#include<bits/stdc++.h>
using namespace std;


class A
{
    public:
    int a;

    protected:
    int b;

    private:
    int c;

};

// Mode of Inheritance -- Public
class B:public A{
    public:
    int d;

    protected:
    int e;

    private:
    int f;
};
int main()
{
    B obj;
    
    obj.a = 1; // Accessible
    // obj.b = 2; // protected --> Not Accessible
    // obj.c = 3; // private --> Not Accessible
    obj.d = 4; // public --> Accessible
    // obj.e = 5; // protected --> Not Accessible
    // obj.f = 6; // private --> Not Accessible
    return 0;
}