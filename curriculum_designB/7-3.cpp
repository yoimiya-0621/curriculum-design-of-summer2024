#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;//���������ַ���������
    int flag=0;
    reverse(s.begin(),s.end());//���ַ�������
    for(int i=0;i<s.size();i++)
    {
        if(flag==0&&s[i]=='0')//ǰ��0�����
            continue;
        cout<<s[i];
        flag=1;
    }
    return 0;
}