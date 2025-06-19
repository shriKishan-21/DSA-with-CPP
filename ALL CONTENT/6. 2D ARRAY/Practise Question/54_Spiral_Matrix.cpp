#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> ans;

    int count = 0; // to count elements after every print
    int total = row*col; // total elements in the matrix

    int startRow = 0;// to keep check of starting row
    int endRow = row-1; // to keep check of ending row
    int startCol = 0; // to keep check of starting col
    int endCol = col-1; // to keep check of ending col

    while(count<total){
        // printing left to right
        for(int i=startCol;count<total && i<=endCol;i++){ 
            ans.push_back(matrix[startRow][i]);
            count++;
        }
        startRow++;
        // printing top to bottom 
        for(int i=startRow;count<total && i<=endRow;i++){
            ans.push_back(matrix[i][endCol]);
            count++;
        }
        endCol--;

        // printing right to left
        for(int i=endCol;count<total && i>=startCol;i--){
            ans.push_back(matrix[endRow][i]);
            count++;
        }
        endRow--;

        // printing bottom to top
        for(int i=endRow;count<total && i>=startRow;i--){
            ans.push_back(matrix[i][startCol]);
            count++;
        }
        startCol++;
    }


    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}