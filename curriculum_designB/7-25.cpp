#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string ch[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    for(int i=0;i<s.size();i++)
    {
        if(i)
            cout<<' ';
        if(s[i]=='-')
            cout<<"fu";
        else{
            cout<<ch[s[i]-'0'];
        }
    }
    return 0;
}