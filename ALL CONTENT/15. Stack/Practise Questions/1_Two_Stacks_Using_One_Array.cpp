#include<iostream>
using namespace std;

class TwoStack{
    public:

    // properties
    int *arr;
    int size;
    int top1;
    int top2;

    // constructor
    TwoStack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // push operation for stack 1
    void push1(int element){
        // if top2 is less than top 1 -- atlease a empty space is present
        if(top2 - top1 > 1){
            top1++; 
            arr[top1] = element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    // push operation for stack 2
    void push2(int element){
        // id topq is less than top 2 -- element can be pushed in stack 2
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    // pop operation for stack 1
    int pop1(){
        // chek if element is present in stack
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // pop operation for stack 2
    int pop2(){
        // check if element is present
        // as stack 2 is in reverse -- and top2 is at size of stack not size-1(->on the stack) initially
        // like top1 is at -1 (outside arr first ) , top2 is at size(outide arr last)
        // if size is larger than top2 -- top2 is pointing inside the array
        if(top2<size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }

};
 

int main(){

    TwoStack ts(5);
    ts.push1(10);
    ts.push2(15);
    ts.push1(20);
    ts.push2(25);
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;

    return 0;
}
