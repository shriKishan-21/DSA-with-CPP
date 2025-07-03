#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr , int n){

    // create a stack
    stack<int> s;
    // push -1 for first comapison
    s.push(-1);
    // create ans array
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        // pop stack element till a smaller element than curr is found
        while(s.top()>=curr){
            s.pop();
        }

        // now after all the larger element popped -- the smaller element remains -- that is the ans
        ans[i] = s.top();
        
        // at last push the curr element in stack -- for the next element smmallest element to be found
        s.push(curr);
    }

    return ans;
}

int main()
{

    vector<int> arr = {2,1,4,3};

    vector<int> ans = nextSmallerElement(arr,arr.size());

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }       

    return 0;
}
