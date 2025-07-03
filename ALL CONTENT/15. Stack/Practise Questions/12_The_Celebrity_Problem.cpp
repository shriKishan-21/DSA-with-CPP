  #include<iostream>
#include<vector>
#include<stack>
using namespace std;


bool knows(vector<vector<int>> M  ,int a, int b){

    if(M[a][b]==1){
        return true;
    }
    return false;
}

int findCelebrity(vector<vector<int>>& M ,int n){

    stack<int> s;

    // step 1 : push all the people in the stack
    for(int i=0;i<n;i++){
        s.push(i);
    }

    // step 2 : operate until only one person is left in the stack
    while(s.size()>1){

        // find a --> s.top()
        int a = s.top();
        s.pop();

        // find b --> s.top()
        int b = s.top();
        s.pop();

        // if a knows b then a is not celebrity
        if(knows(M,a,b)){
            s.push(b);
        }
        // if b knows a then b is not celebrity
        else{
            s.push(a);
        }
    }

    // store potential celebrity
    int candidate = s.top();

    // check if candidate is a celebrity or not

    // Row Check
    int zeroCount=0;
    for(int i=0;i<n;i++){
        if(M[candidate][i]==0){
            zeroCount++;
        }
    }
    if(zeroCount!=n){
        return -1;
    }

    // column check
    int oneCount=0;
    for(int i=0;i<n;i++){
        if(M[i][candidate]==1){
            oneCount++;
        }
    }
    if(oneCount!=n-1){
        return -1;
    }

    return candidate;
}

int main(){

    vector<vector<int>> H = {{0,1,0},{0,0,0},{0,1,0}};
    int n = H.size();

    int h = findCelebrity(H,n);

    if(h==-1){
        cout<<"No celebrity exists";
    }
    else{
        cout<<"Celebrity is "<<h;
    }
    
    return 0;
}