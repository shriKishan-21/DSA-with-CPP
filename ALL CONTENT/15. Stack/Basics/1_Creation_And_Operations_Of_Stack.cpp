#include<iostream>
// include the stack library 
#include<stack>
using namespace std;

int main()
{
    // creating stack
    stack<int> s;
    // s stack of integer type is created

    // push operations
    s.push(1);
    s.push(2);
    s.push(3);
    // stack include these digit in order (from bottom to top) : 1 -> 2 -> 3

    // pop operation
    s.pop();
    // the top element will pop out --> 3
    // stack is : 1 -> 2 

    // top operation
    cout<<"Printing top element : "<<s.top()<<endl;
    // give top element -> 2

    // empty operation
    // this operation return true or false 
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    // size operation
    cout<<"Size of stack is : "<<s.size()<<endl;

    // swap operation
    // s1.swap(s2);
    // swap operation work by swapping the stack s1 and s2
    // swap the entire contents (all elements, including their order) in constant time (just pointer or internal container swap)
    // Works only if both stacks have the same underlying container type.

    // emplace operation
    s.emplace(4);

    // Use emplace when you want to avoid extra copies or moves
    // Without emplace -- This creates a temporary object, then copies or moves it onto the stack.
    // With emplace (more efficient) -- Constructs the object directly in-place at the top.
    // For int, emplace is almost the same as push
 



    return 0;

}