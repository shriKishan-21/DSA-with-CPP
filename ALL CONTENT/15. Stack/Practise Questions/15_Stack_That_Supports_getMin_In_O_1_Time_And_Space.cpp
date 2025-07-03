#include<iostream>
#include<stack>
using namespace std;


// Approach 1 -- TC : O(1)  SC : O(n)
class specialStack1{
    public:
    stack<int> s1;
    stack<int> s2;

    // constructor
    specialStack1(){
        stack<int> s1;
        stack<int> s2;
    }

    // push function
    void push(int x){
        s1.push(x);

        if(s2.empty() || x <= s2.top()){
            s2.push(x);
        }
    }

    void pop(){
        if(s1.top() == s2.top()){
            s1.pop();
            s2.pop();
        }
        else{
            s1.pop();
        }
    }

    int getMin(){
        return s2.top();
    }

     
};


// Approach 2  -- TC : O(1)  SC : O(1)
class specialStack2{
    public:
    stack<int> s;
    int mini;

    // push function
    void push(int element){
        if(s.empty()){
            s.push(element);
            mini = element;
        }
        else{
            if(element < mini){
                s.push(2*element - mini);
                mini = element;
            }
            else{
                s.push(element);
            }
        }
    }

    // pop function
    int pop(){
        if(s.empty()){
            return -1;
        }

        int curr = s.top();
        s.pop();
        if(curr<mini){
            return curr;
        }
        else{
            int prevMini = mini;
            int val = 2* mini - curr;
            mini = val;
            return prevMini;
        }
    }

    // top function
    int top(){
        if(s.empty()){
            return -1;
        }

        int curr = s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    // isEmpty function
    bool isEmpty(){
        return s.empty();
    }

    // getMin function
    int getMin(){
        if(s.empty()){
            return -1;
        }
        return mini;
    }
};


int main()
{
    specialStack2 s1;
    s1.push(5);
    s1.push(3);
    s1.push(8);
    s1.push(2);
    s1.push(4);

    cout<<"The minimum element is : "<<s1.getMin()<<endl;

    cout<<"popped element is : "<<s1.pop()<<endl;

    cout<<"The minimum element is : "<<s1.getMin()<<endl;


    return 0;
}