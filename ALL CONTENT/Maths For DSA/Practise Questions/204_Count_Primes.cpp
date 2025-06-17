#include <bits/stdc++.h>
using namespace std;

/*
bool isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main()
{
    int n = 10;
    int count=0;

    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
    */

// This came out to be a O(n^2) solution
// This will give TLE error for big values
// We need to optimize this
// We'll use sieve of eratosthenes

int main()
{
    int n;
    cin >> n;

    int count = 0;
    vector<bool> primes(n + 1, true);

    primes[0] = primes[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            count++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                primes[j] = false;
            }
        }
    }

    cout << count << endl;

    return 0;
}
