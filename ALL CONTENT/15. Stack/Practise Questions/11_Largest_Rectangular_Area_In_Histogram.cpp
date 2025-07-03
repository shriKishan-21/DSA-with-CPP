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
        while( s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }

        // now after all the larger element popped -- the smaller element remains -- that is the ans
        ans[i] = s.top();
        
        // at last push the index -- as we requied those
        s.push(i);
    }

    return ans;
}

vector<int> previousSmallerElement(vector<int> arr , int n){

    // create a stack
    stack<int> s;
    // push -1 for first comapison
    s.push(-1);
    // create ans array
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int curr = arr[i];
        // pop stack element till a smaller element than curr is found
        while( s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }

        // now after all the larger element popped -- the smaller element remains -- that is the ans
        ans[i] = s.top();
        
        // at last push the index -- as we requied those
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights){
    int n = heights.size();

    // nextptr values 
    vector<int> next(n);
    next = nextSmallerElement(heights,n);

    // previousptr values
    vector<int> prev(n);
    prev = previousSmallerElement(heights,n);

    int area = -100;

    for(int i=0;i<n;i++){
        // find length
        int l = heights[i];
        // this is the case when all heights are same in array -- there will be no next for any rectangle
        // check this condition before calculating breadth
        if(next[i]==-1){
            next[i]=n;
        }
        // find breadth
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;

        area = max(area,newArea);
    }

    return area;

}

int main(){

    vector<int> heights = {2,1,5,6,2,3};

    cout<<"Maximum Rectangular Area is : "<<largestRectangleArea(heights)<<endl;

    return 0;
}