#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,str;
    getline(cin,s);//�ַ���s
    getline(cin,str);//���ַ���str
    while(s.find(str)!=-1){//ֻҪs�к����ַ���str�ͽ���ѭ��ɾ��
        s.erase(s.find(str),str.size());
    }
    cout<<s;
    return 0;
}