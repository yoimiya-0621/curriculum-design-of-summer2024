#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;//将数字用字符串存起来
    int flag=0;
    reverse(s.begin(),s.end());//将字符串倒叙
    for(int i=0;i<s.size();i++)
    {
        if(flag==0&&s[i]=='0')//前导0不输出
            continue;
        cout<<s[i];
        flag=1;
    }
    return 0;
}