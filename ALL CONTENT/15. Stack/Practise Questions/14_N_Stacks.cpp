#include<iostream>
using namespace std;

class Nstack{
    public:
    int *arr;
    int *top;
    int *next;
    // n-size of stack , s - size of array
    int n,s;
    int freespot;

    // constructor
    Nstack(int N,int S){
        n=N;
        s=S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        // top initializer
        for(int i=0;i<n;i++){
            top[i] = -1;
        }

        // next initializer
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }

        // update last value of next with -1
        next[s-1] = -1;

        // initialize freespot
        freespot = 0;
    }

    bool push(int x,int m){
        //check for overflow
        if(freespot==-1){
            return false;
        }

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // push value
        arr[index] = x;

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    int pop(int m){
        // check for underflow
        if(top[m-1]==-1){
            return -1;
        }

        // find index
        int index = top[m-1];

        // update top
        top[m-1] = next[index];

        // update next
        next[index] = freespot;

        // update freespot
        freespot = index;

        // return value
        return arr[index];
    }

};

int main(){
    Nstack s(3,6);  

    // 1st operation
    s.push(10,1);

    // 2nd operation
    s.push(20,1);

    // 3rd operation
    s.push(30,2);

    // 4th operation
    cout<<s.pop(1)<<endl;

    // 5th operation
    cout<<s.pop(2)<<endl;
}