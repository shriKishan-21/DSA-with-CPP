#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;



int signum(int a , int b){
    if(a==b) return 0;
    else if (a>b) return 1;
    else return -1;
}


void solveMedian(int val , priority_queue<int> &maxi , priority_queue<int , vector<int> , greater<int>> &mini , int &median){
    
    switch(signum(maxi.size(),mini.size())){

        case 0 : // both side same size
            if(val>median){
                mini.push(val);
                median = mini.top();
            }
            else{
                maxi.push(val);
                median = maxi.top();
            }
            break;


        case 1: // mini size greater
            if(val>median){
                mini.push(val);
                median = (mini.top()+maxi.top())/2;
            }
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(val);
                median = (mini.top()+maxi.top())/2;
            }
            break;

        case -1 : // maxi size greater
            if(val>median){
                maxi.push(mini.top());
                mini.pop();
                mini.push(val);
                median = (mini.top()+maxi.top())/2;
            }
            else{
                maxi.push(val);
                median = (mini.top()+maxi.top())/2;
            }
            break;
    }
}


vector<int> findMedian(vector<int> &arr , int n){

    vector<int> ans;

    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> , greater<int>> minHeap;

    int median = 0;

    for(int i=0;i<n;i++){
        
        solveMedian(arr[i],maxHeap,minHeap,median);

        ans.push_back(median);
    }

    return ans;
}


int main()
{

    vector<int> arr = {1,2,3};
    int n = arr.size();

    vector<int> ans = findMedian(arr,n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}