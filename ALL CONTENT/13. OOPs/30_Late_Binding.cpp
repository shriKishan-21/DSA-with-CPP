// Late Binding or Dynamic Binding
// Here virtual function is used
#include<bits/stdc++.h>
using namespace std;


class A
{
    public:
    virtual void show()
    {
        cout<<"A\n";
    }
};

class B : public A
{
    public:
    void show()
    {
        cout<<"B\n";
    }
};
int main()
{
    A *a = new B;
    a->show();
    return 0;
}