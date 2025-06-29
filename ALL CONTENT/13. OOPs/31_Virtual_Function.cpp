// Virtual Function or method
// Virtual function is a function that is defined in base class and overridden in derived class

#include<bits/stdc++.h>
using namespace std;

class A
{
    public:
    virtual void show()
    {
        cout<<"A\n";
    }

    // Pure virtual function -- It is a function that is does not have any implementation and is assigned to 0
    virtual void show1()=0;
    // A class that contains a pure virtual function is called abstract class
};

class B:public A
{
    public:
    void show()
    {
        cout<<"B\n";
    }

    void show1()
    {
        cout<<"B1\n";
    }
};

int main()
{
    A *a = new B;
    a->show();
    return 0;
}