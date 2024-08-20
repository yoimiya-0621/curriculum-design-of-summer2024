#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int flag=0;
    while(1){
        cin>>s;
        if(s[s.size()-1]=='.')//最后一个单词
        {
            if(s.size()>1)
            {
                if(flag)
                    cout<<' ';
             cout<<s.size()-1;
            }
             break;
        }
        else
        {
            if(flag)
                cout<<' ';
            cout<<s.size();
            flag=1;
        }
    }
    return 0;
}