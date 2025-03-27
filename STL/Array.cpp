#include <iostream>
#include<array>
using namespace std;
int main()
{
    // basic array and its size
    int basic[3]={1,2,3};
    int size1=sizeof(basic)/sizeof(int);

    // array using stl array (library is <array>)
    array<int,4> a={1,2,3,4};
    int size2=a.size();

    // to get element at a particular index
    cout<<"Element at index 2 is: "<<a.at(2)<<endl;

    // to check if array is empty or not
    cout<<"Array is empty or not: "<<a.empty()<<endl;

    // to get first element of array
    cout<<"First element of array is: "<<a.front()<<endl;

    // to get last element of array
    cout<<"Last element of array is: "<<a.back()<<endl;

    


    return 0;
}