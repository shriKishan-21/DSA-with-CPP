#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


class node{
    public:
    int data;
    int row;
    int col;

    node(int d , int row , int col){
        this->data = d;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a , int k , int n){
    int mini = INT_MAX , maxi = INT_MIN;

    priority_queue<node* , vector<node*> , compare> minHeap;

    // step 1 : create a min heap for sorting element of each list and tracking mini/maxi vaule
    for(int i=0;i<k;i++){
        int element = a[i][0];

        mini = min(mini , element);
        maxi = max(maxi , element);

        minHeap.push(new node(element,i,0));
    }

    int start = mini , end = maxi;

    while(!minHeap.empty()){
        // fetch mini
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // range of answer updation
        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        // next element exists or not
        if(temp->col + 1 < n){
            maxi = max(maxi , a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1] , temp->row , temp->col+1));
        }
        else{
            break;
        }
    }

    return end - start + 1;
    
}
int main()
{
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 3 , n = 3;

    cout<<kSorted(a , k , n)<<endl;

    return 0;
}