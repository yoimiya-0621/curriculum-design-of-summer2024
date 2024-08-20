#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,str;
    getline(cin,s);//字符串s
    getline(cin,str);//子字符串str
    while(s.find(str)!=-1){//只要s中含子字符串str就进入循环删除
        s.erase(s.find(str),str.size());
    }
    cout<<s;
    return 0;
}