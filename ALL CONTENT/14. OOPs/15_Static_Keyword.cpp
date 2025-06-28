// static keyword
// static variable/member and static function
#include<bits/stdc++.h>
using namespace std;


class Hero{

    // properties
    private:
    int health;

    public:
    char *name;
    char level;
    // to make feature static initialize it in static keyword
    static int timeToComplete;


    // default constructor
    Hero(){
        cout<<" Default constructor is called"<<endl;
        name = new char[100];
    }

    // static function
    // can only access static variable/members
    static int random(){
        return timeToComplete;
    }

};

// Creating static 
int Hero::timeToComplete = 10;


int main()
{
    // no need to create object to access static variable
    // static variable
    cout<<"Time to complete : "<<Hero::timeToComplete<<endl;

    // static function
    cout<<"Random number : "<<Hero::random()<<endl;

    return 0;
}