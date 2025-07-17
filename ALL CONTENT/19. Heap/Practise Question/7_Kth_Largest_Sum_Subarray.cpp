#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


int getKthLargest(vector<int> &arr, int k) {
    // 1. create an array to store the sum of each subarray
    vector<int> sumStore;
    int n = arr.size();

    // 2. calculate sum and insert it into array
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }

    // 3. sort the array
    sort(sumStore.begin(),sumStore.end());

    // 4. return kth largest element
    if(k>sumStore.size()){
        return -1;
    }
    else{
        return sumStore[sumStore.size()-k];
    }
}

// Approach 2 -- using min heap
int getKthLargest2(vector<int> &arr, int k) {

    // 1. create a min heap
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int n = arr.size();

    // 2. push first k elements sum into heap
    for(int i=0;i<k;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];

            // 2. push sum into queue till size is less than k
            if(minHeap.size()<k){
                minHeap.push(sum);
            }
            // 3. if size is greater than k, check if sum is less than top of heap, if yes, pop top element and push sum
            else{
                if(sum>minHeap.top()){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }

    return minHeap.top();
}

int main(){

        // Approach 1
        vector<int> arr = {1,2,3,4,5};
        int k = 3;
        int ans = getKthLargest(arr,k);
        cout<<ans<<endl;

        // Approach 2
        vector<int> arr1 = {1,2,3,4,5};
        int k1 = 3;
        int ans1 = getKthLargest2(arr1,k1);
        cout<<ans1<<endl;

        return 0;
    }