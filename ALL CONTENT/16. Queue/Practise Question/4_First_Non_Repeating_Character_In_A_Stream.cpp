#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;


string firstNonRepeating(string A){
    // map to store the count of occurrence of element
    unordered_map<char,int> count;

    // queue to check repeating and non repeating element
    queue<int> q;

    // ans string to store final ans
    string ans = "";

    for(int i=0;i<A.length();i++){
        char ch = A[i];

        // increase count
        count[ch]++;

        // push into q
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()]>1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }

    }

    return ans;
}
int main()
{
    string A = "aabc";

    cout<<firstNonRepeating(A);

    return 0; 

}