#include<bits/stdc++.h>
using namespace std;


class Hero{

    private:
    int health;

    public:
    char level;

    // getter 
    int getHealth()
    {
        return health;
    }

    // setter
    void setHealth(int h)
    {
        health = h;
    }

};
int main()
{

    // Static Memory Allocation
    Hero a;
    a.setHealth(80);
    a.level = 'B';
    cout<<"Health is :"<<a.getHealth()<<endl;
    cout<<"Level is :"<<a.level<<endl;

    // Dynamic Memory Allocation
    Hero *b = new Hero;
    // for accesing in dynamic memory we can either use (*b) or (b->)
    (*b).setHealth(70);
    (*b).level = 'C';
    // or we can use
    // b->setHealth(70);
    // b->level = 'C';
    cout<<"Health is :"<<(*b).getHealth()<<endl;
    cout<<"Level is :"<<(*b).level<<endl;

    return 0;
}