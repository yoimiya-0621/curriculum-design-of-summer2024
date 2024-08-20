#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int n;
    cin>>n;
    n%=s.size();
    for(int i=n,j=0;j<s.size();i++,j++)
    {
        if(i>s.size()-1)
            i=0;
        cout<<s[i];
    }
    return 0;
}