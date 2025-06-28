// we can access class if made separately using #include"file Name"


#include<iostream>
#include"2_MyClass.cpp"
using namespace std;


int main()
{
     // object creation
    Hero h1;

    cout<<"Size :"<<sizeof(h1)<<endl;

    // accessing the properties
    cout<<"Health :"<<h1.health<<endl;
    cout<<"Level :"<<h1.level<<endl;

    return 0;
}