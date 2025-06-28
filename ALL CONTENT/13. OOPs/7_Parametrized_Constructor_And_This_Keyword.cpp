#include<bits/stdc++.h>
using namespace std;


class Hero{
    public:
    int health;
    int level;

    Hero(int health){//
        // this is wrong way of initialization
        // we are just passing same value to health 

        // health = health;

        // use this keyword here
        this->health = health;
        // here this->health indicate original health and health indicate new health
    }

    // This Keyword-->
    // It is a pointer which points to the current object
    // This stores the address of the current object created
};
int main()
{
    Hero h1(70);

    cout<<h1.health<<endl;

    return 0;

}