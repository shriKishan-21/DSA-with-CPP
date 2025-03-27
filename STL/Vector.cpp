#include <iostream>
// to use vector we need to include vector
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    // to check the capacity of vector
    cout << "Capacity: " << v.capacity() << endl;

    // to add element in vector
    v.push_back(1);

    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(2);

    cout<<"Capacity: "<<v.capacity()<<endl;

    // to check the size of vector
    int size=v.size();

    // to print the front element of vector
    cout<<"Front element: "<<v.front()<<endl;

    // to print the back element of vector
    cout<<"Back element: "<<v.back()<<endl; 

    // before pop
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;
    
    // pop is use to remove the element from vector
    v.pop_back();

    // after pop
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    // size before clearing the vector
    cout<<"before clear size : "<<v.size()<<endl;

    // to clear the vector
    v.clear();

    // size after clearing the vector
    cout<<"after clear size : "<<v.size()<<endl;


    // to create a vector with initial size
    vector<int> a(5,1);

    // to create a copy of vector
    vector<int> b(a);

}


