/* 
There are 4 types of macros in c++ :
1. object-like macro
2. chain macro
3. multi-line macro
4. function-like macro
*/

#include<iostream>
using namespace std;

// 1. object-like macro
#define PI 3.14

// 2. chain macro
#define INSTRAGRAM FOLLOWERS
#define FOLLOWERS 100

// 3. multi-line macro
#define ELE 1 , \
            2 , \
            3

// 4. function-like macro
#define MAX(a,b) ((a)>(b)?(a):(b))

int main(){
    // 1. object-like macro
    cout<<"Value of PI is :"<<PI<<endl;

    // 2. chain macro
    cout<<"I have "<<INSTRAGRAM<<"K"<<" followers"<<endl;

    // 3. multi-line macro
    int arr[] = {ELE};
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";// 1 2 3
    }
    cout<<endl;

    // 4. function-like macro
    int a=10,b=20;
    cout<<"Maximum of "<<a<<" and "<<b<<" is "<<MAX(a,b)<<endl;

    return 0;
}