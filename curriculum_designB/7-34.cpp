#include <bits/stdc++.h>
using namespace std;
struct S{
    string name;
    char sex;
    string s,tele,b;
}s[15];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].name;
        cin>>s[i].b;
        cin>>s[i].sex>>s[i].s>>s[i].tele;
    }
    int k,x;
    cin>>k;
    while(k--){
        cin>>x;
        if(x>=n||x<0)
            cout<<"Not Found"<<'\n';
        else
        {
            cout<<s[x].name<<' '<<s[x].s<<' '<<s[x].tele<<' '<<s[x].sex<<' '<<s[x].b<<'\n';
        }
    }
    return 0;
}