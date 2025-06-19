#include<bits/stdc++.h>
using namespace std;


/*
Algorithm:
1. Create an array of size n+1
2. Mark all elements as prime
3. Iterate over all primes and mark their multiples as not prime
4. Count the number of primes
5. Print the count
*/

int main()
{
    int n;
    cin>>n;

    int count=0;
    vector<bool> primes(n+1,true);

    primes[0]=primes[1]=false;

    for(int i=2;i<n;i++){
        if(primes[i]){
            count++;
            for(int j=2*i;j<n;j=j+i){
                primes[j]=false;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}