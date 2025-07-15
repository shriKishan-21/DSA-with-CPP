#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int kthSmallest(int arr[],int l , int r , int k){
    priority_queue<int> pq;

    // step 1 : push first k elements into pq 
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    
    // step 2 : compare rest elements
    for(int i=k;i<r;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step 3
    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[] = {12,3,5,7,19,25,27,29,31,50};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = kthSmallest(arr,0,n,k);
    cout<<ans<<endl;
    
    return 0;

}