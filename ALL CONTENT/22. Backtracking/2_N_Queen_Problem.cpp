#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


// Function to add board entries in ans array
void addSolution(vector<vector<int>> &ans , vector<vector<int>> &board , int n){
    vector<int> temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);

}

// Function to check 3 condition
bool isSafe(int row , int col , vector<vector<int>> &board , int n){

    int x = row;
    int y = col;

    // 1. check row
    while(y>=0){
        if(board[x][y]==1)
            return false;
        y--;
    }

    // Reset x,y
    x = row;
    y = col;

    // 2. check col -- no need to check cols

    // 3. check diagonal
    // A. Above Diagonal
    while(x>=0 && y>=0){
        if(board[x][y]==1)
            return false;
        y--;
        x--;
    }

    // Reset x,y
    x = row;
    y = col;

    // B. Below Diagonal
    while(x<n && y>=0){
        if(board[x][y]==1)
            return false;
        y--;
        x++;
    }

    return true;
}

void solve(int col , vector<vector<int>> &ans , vector<vector<int>> &board , int n){

    // base case
    if(col==n){
        addSolution(ans,board,n);
        return;
    }

    // Solve 1 case and rest recursion will do
    for(int row=0;row<n;row++){

        // if placing Queen is safe
        if(isSafe(row,col,board,n)){
            board[row][col] = 1;

            // recursive call for next col
            solve(col+1,ans,board,n);

            // backtraking
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));

    solve(0,ans,board,n);

    return ans;
}


int main()
{
    int n = 4;
    vector<vector<int>> ans = nQueen(n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
} 