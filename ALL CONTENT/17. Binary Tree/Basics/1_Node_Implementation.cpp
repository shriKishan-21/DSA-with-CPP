#include<iostream>
using namespace std;


class node{

    public:

    int data;
    node* left;
    node* right;

    // constructor
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    

};

int main()
{
    node n1(5);

    cout<<n1.data<<endl;
    cout<<n1.right<<endl;
    cout<<n1.left<<endl;

    return 0;
}