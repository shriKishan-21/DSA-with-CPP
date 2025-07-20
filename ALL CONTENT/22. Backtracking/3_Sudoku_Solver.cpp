#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


bool isSafe(int row , int col , vector<vector<int>> &board , int val){

    for(int i=0;i<board.size();i++){

        // row Check
        if(board[row][i]==val){
            return false;
        }

        // col Check
        if(board[i][col]==val){
            return false;
        }

        // 3*3 matrix check
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board){
    int n = board.size();

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            // cell empty
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;

                        // recursive call
                        bool nextPossibleSolution = solve(board);

                        // if next possible solution exist
                        if(nextPossibleSolution==true){
                            return true;
                        }
                        else{
                            // backtracking
                            board[row][col] = 0;
                        }
                    }
                }
                // if no possible solution
                return false;
            }
        }
    }

    return true;

}

void solveSudoku(vector<vector<int>>& board) {

    solve(board);

}



int main()
{
    vector<vector<int>> board = {{3,0,6,5,7,8,0,9,2},{5,2,9,1,3,4,7,6,8},{4,8,0,6,2,9,5,3,1},{2,6,3,4,1,5,9,8,7},{9,7,4,8,6,3,1,2,5},{8,5,1,7,9,2,6,4,3},{1,3,8,9,4,7,2,5,6},{6,9,2,3,5,0,8,7,4},{7,4,5,2,8,6,3,1,9}};
    solveSudoku(board);

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}