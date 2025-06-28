// constructor
// constructor is a special member function which is called automatically when an object is created.
// if no constructor is created in the class then the compiler will create a default constructor and call it.


// Default constructor
#include<bits/stdc++.h>
using namespace std;

class Hero{
    public:
    int health;
    int level;

    // default constructor
    Hero(){
        cout<<" Default constructor is called"<<endl;
    }

};


int main()
{
    // static object allocation
    Hero h1;

    // dynamic object allocation
    Hero *h2 = new Hero;
    
    // statically or dynamically , kese bhe memory allocate ho , firstly the constructor is called
    return 0;
}