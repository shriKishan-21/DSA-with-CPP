// Abstraction
// Abstraction is the process of hiding the internal details and showing only the necessary information to the user
#include<bits/stdc++.h>
using namespace std;

class A
{
    private:
    int a;

    public:
    void set(int x)
    {
        a=x;
    }
    int get()
    {
        return a;
    }
};

int main()
{
    A obj;
    obj.set(10);
    cout<<obj.get();
}