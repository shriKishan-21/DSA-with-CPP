// creating class
#include<bits/stdc++.h>
using namespace std;


class Hero{

    // properties
    int health;
    char level;


};
int main()
{
    // object creation
    Hero h1;

    // checking the size of object
    // size of object is equal to size of class
    // if class is empty then size will be 1
    cout<<"Size :"<<sizeof(h1)<<endl;


    // We can access the properties of class using Dot (.) operator

    
    // accessing the properties
    // cout<<"Health :"<<h1.health<<endl;
    // cout<<"Level :"<<h1.level<<endl;
    // we cant acces the properties because they are private
    // as if nothing is specified then by default it will be private

    return 0;
}