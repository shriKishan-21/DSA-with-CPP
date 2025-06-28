#include<bits/stdc++.h>
using namespace std;


class Hero{

    private:
    int health;

    public:
    char level;

    // getter -- use to access the private data members
    int getHealth()
    {
        return health;
    }

    // setter -- use to modify the private data members
    void setHealth(int h)
    {
        health = h;
    }

    // we can also add conditions in setter
    // void setLevel(int h , char name)
    // {
    //     if(name =='A')
    //     {
    //         health = h;
    //     }
    // } 

};
int main()
{
    Hero h1;

    // accessing the private data members
    cout<<h1.getHealth()<<endl;

    // modifying the private data members
    h1.setHealth(70);

    // modified value
    cout<<h1.getHealth()<<endl;
}