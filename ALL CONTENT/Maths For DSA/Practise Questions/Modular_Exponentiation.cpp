#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 4, n = 3 , m =10;

    int res = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            // odd case
            res = (1LL * (res) * (x)%m)%m;
        }
        x = (1LL * (x)%m * (x)%m)%m;
        n = n >> 1;
    }
    cout<< res;
}