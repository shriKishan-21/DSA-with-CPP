#include <iostream>
using namespace std;

// implementation of stack -- using arrays
class stack
{
public:
    // properties
    int *arr; // pointer to array
    int top;  // pointer to top of the stack
    int size; // size of the stack

    // behaviour
    // constructor
    stack(int size)
    {
        this->size = size;   // assigning the size of the stack
        arr = new int[size]; // creating an array of size 'size'
        top = -1;            // initially top will be -1
    }

    // push operation
    void push(int element)
    {   // if size of the stack is greater than 1
        if (size - top > 1)      
        {                      
            top++;              // increment the top by 1
            arr[top] = element; // assign the element to the top of the stack
        }
        else
        {   // if size of the stack is less than 1
            cout << "Stack overflow" << endl;
        }
    }

    // pop operation
    void pop()
    {   // if top is greater than or equal to 0 -- element present
        if (top >= 0)
        {          
            top--; // decrement the top by 1
        }
        else
        {   // if top is less than 0 -- stack is empty
            cout << "Stack underflow" << endl; 
        }
    }

    // top operation
    int peek()
    {   // if top is greater than or equal to 0 -- element present
        if (top >= 0)
        {                    
            return arr[top]; // return the top of the stack
        }
        else
        {   // if top is less than 0 -- stack is empty
            cout << "Stack is empty" << endl;
            return -1;                     
        }
    }

    // empty operation
    bool isEmpty()
    {   // if top is -1 -- empty stack
        if (top == -1)
        {            
            return true; 
        }
        else
        {   // if top is greater than or equal to 0 -- element present
            return false; 
        }
    }
};

int main(){

    // creating a stack of size 5
    stack s(5); 

    // push elements in the stack
    s.push(10); // push 10 in the stack
    s.push(20); // push 20 in the stack

    // pop elements from the stack
    s.pop(); // pop the top element from the stack
    
    // peek the top element
    cout<<s.peek()<<endl; 
    
    // check if stack is empty
    if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    
    // lets check stack overflow - by pushing more element that actal size
    s.push(20); // size filled = 2
    s.push(30); // size filled = 3
    s.push(40); // size filled = 4
    s.push(50); // size filled = 5 -- stack is full here
    s.push(60); // inserting this element will cause stack overflow

    // lets check satck underflow - by popping element from empty stack
    s.pop(); // size filled = 4
    s.pop(); // size filled = 3
    s.pop(); // size filled = 2
    s.pop(); // size filled = 1
    s.pop(); // size filled = 0 -- stack is empty here
    s.pop(); // inserting this element will cause stack underflow
    
    return 0;
}