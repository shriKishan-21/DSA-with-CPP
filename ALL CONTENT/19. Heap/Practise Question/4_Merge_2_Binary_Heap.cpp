#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // step 1 : merge both the arrays
    vector<int> ans;
    //  we are using 0 based indexing 
    for(auto i : a){
        ans.push_back(i);
    }
    for(auto i : b){
        ans.push_back(i);
    }

    // step 2 : heapify the merged array
    int size = ans.size();
    for(int i=size/2 - 1;i>=0;i--){ // heapify from last to first
        heapify(ans,size,i);
    }

    return ans;
}


int main()
{
    vector<int> a = {10,5,6,2};
    vector<int> b = {12,7,9};
    int n = 4 , m = 3;

    vector<int> ans = mergeHeaps(a,b,n,m);

    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;

}
