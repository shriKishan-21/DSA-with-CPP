// There are three access modifiers in c++ which are public , private and protected
// public : It is accessible from anywhere in the program
// private : It is accessible only in the class
// protected : It is accessible only in the class and its derived classes

#include<bits/stdc++.h>
using namespace std;


class Hero{
    // private access modifier
    private:
    int health;

    // public access modifier
    public:
    int level;

};

int main()
{
    // creating object
    Hero h1;

    // accessing public variable
    cout<<h1.level<<endl;

    // accessing private variable --> will throw error
    // cout<<h1.health<<endl;

    return 0;
}