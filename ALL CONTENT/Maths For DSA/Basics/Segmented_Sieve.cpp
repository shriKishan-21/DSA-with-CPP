/*
The Segmented Sieve is an optimization over the regular Sieve of Eratosthenes used to find all prime numbers 
in a given range [L, R], especially when R is large (like up to 10^12 ) and R - L is relatively small
(like 10^9 ).
*/

/*
Algorithm:
1. Use normal Sieve of Eratosthenes to find all primes up to √R.
2. Create a boolean array isPrime[R - L + 1] and initialize all values as true.
3. For each prime p found in step 1:
    - Find the first multiple ≥ L (say start = max(p*p, (L + p - 1) / p * p)).
    - Mark all multiples of p in [L, R] as not prime in isPrime[].
*/

#include <bits/stdc++.h>
using namespace std;

