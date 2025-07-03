#include<iostream>
#include<vector>
#include<stack>
const int MAX = 1000;
using namespace std;

vector<int> nextSmallerElement(int *arr , int n){

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

vector<int> previousSmallerElement(int *arr , int n){

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

int largestRectangleArea(int *heights,int n){
    // nextptr values 
    vector<int> next(n);
    next = nextSmallerElement(heights,n);

    // previousptr values
    vector<int> prev(n);
    prev = previousSmallerElement(heights,n);

    int area = 0;

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

int maxArea(int M[MAX][MAX] , int n , int m){

    // compute area for first area
    int area = largestRectangleArea(M[0],m);

    for(int i = 1;i<n;i++){
        for(int j=0;j<m;j++){
            // row update
            if(M[i][j]!=0){
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else{
                M[i][j] = 0;
            }
        }
        // entire row is updated
        int newArea = largestRectangleArea(M[i],m);
        area = max(area,newArea);
    }

    return area;
}

int main() {
    // Define matrix dimensions
    int n = 4, m = 4;

    // Define the binary matrix
    int M[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    // Print the input matrix
    cout << "Input binary matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    // Compute maximum rectangle area
    int ans = maxArea(M, n, m);

    // Output the result
    cout << "Maximum rectangle area is: " << ans << endl;

    return 0;
}
