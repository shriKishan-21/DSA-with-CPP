#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    if(n<=1)
    {
        cout<<"Not Prime";
    }
    else
    {
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                cout<<"Not Prime";
                return 0;
            }
        }
        cout<<"Prime";
    }


}