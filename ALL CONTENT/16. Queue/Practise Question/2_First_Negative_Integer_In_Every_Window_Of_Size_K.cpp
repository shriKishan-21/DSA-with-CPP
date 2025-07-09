#include<iostream>
#include<queue>
using namespace std;


vector<long long> printFirstNegativeElement(long long A[],long long int n,long long int k){
    deque<long long int> dq;
    vector<long long> ans;

    // step 1 : process the first window of k size
    for(int i=0;i<k;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }

    // step 2 : store answer of first k size window
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    // step 3 : process for remaining window
    for(int i = k ; i<n ; i++){

        // Removal - previous element
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }

        // Addition
        if(A[i]<0){
            dq.push_back(i);
        }

        // store ans
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    return ans;
}
int main()
{
    long long A[] = {-8,2,3,-6,10};
    long long int n = 5;
    long long int k = 2;

    vector<long long> ans = printFirstNegativeElement(A,n,k);

    for(int i=0; i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
