#include<bits/stdc++.h>
using namespace std;

int main()
{

// -------------------------------------------------------------------------------
// APPROACH 1 

    string s = "my name is ashu";

    int n = s.length();

    string str = "";
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            str.push_back('@');
            str.push_back('4');
            str.push_back('0');
        }
        else{
            str.push_back(s[i]);
        }
    }


    cout<<str;

// -------------------------------------------------------------------------------

// APPROACH 2

    string a = "my name is ashu";
    int n = a.length();
    cout<<n<<endl;
    int spaceCount = 0;

    for(int i=0;i<n;i++){
        if(a[i]==' '){
            spaceCount++;
        }
    }
    int totalLength = n + 2*spaceCount;
    cout<<totalLength<<endl;
    a.resize(totalLength);

    for(int i=n-1;i>=0;i--){
        if(a[i]==' '){
            a[i+spaceCount*2] = '0';
            a[i+spaceCount*2-1] = '4';
            a[i+spaceCount*2-2] = '@';
            spaceCount--;
        }
        else{
            a[i+spaceCount*2] = a[i];
        }
    }
    
    cout<<a;


// -------------------------------------------------------------------------------

    return 0;
}