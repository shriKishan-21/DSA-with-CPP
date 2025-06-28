#include<bits/stdc++.h>
using namespace std;


class Hero{
    public:
    int health;
    int level;

    Hero(){
        cout<<" Default constructor is called"<<endl;
    }

    Hero(int health, int level){
        this->health = health;
        this->level = level;
    }

    // if no copy constructor is created then the compiler will create a default copy constructor
    // copy constructor 
    Hero(Hero &temp){
        // Here &temp is important as it is call by reference and without & operator it will become call by value which 
        // will create an infinite loop and will not work
        cout<<" Copy constructor is called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

};
int main()
{
    Hero h1(70, 10);

    cout<<h1.health<<" "<<h1.level<<endl;

    // creating a copy of h1
    Hero h2(h1);
    // This is same as :
    // h2.health = h1.health;
    // h2.level = h1.level;

    cout<<h2.health<<" "<<h2.level<<endl;
}