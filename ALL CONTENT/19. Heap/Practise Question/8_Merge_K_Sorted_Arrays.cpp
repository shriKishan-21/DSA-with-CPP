#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;
    node(int d , int row , int col){
        this->data = d;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arr,int k){

    // 1. cretae a min heap with a different comparator
    priority_queue<node*,vector<node*>,compare> minHeap;

    // 2. push first element of each array into heap
    for(int i=0;i<k;i++){
        node* temp = new node(arr[i][0],i,0);
        minHeap.push(temp);
    }

    // 3. create a vector to store the merged array
    vector<int> ans;
    while(minHeap.size()>0){
        
        node* temp = minHeap.top();

        // 4. push the top element into vector
        ans.push_back(temp->data);

        // 5. pop the top element
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        // 6. if next element is available, push it into heap
        if(j+1<arr[i].size()){
            node* next = new node(arr[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main(){

    vector<vector<int>> arr = {{1,4,7},{2,5,8},{3,6,9}};
    int k = 3;
    vector<int> ans = mergeKSortedArrays(arr,k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}