#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    //����n������153�����Զ�Ӧ��10���������ᳬ��2λ
    if(n>=16)//ʮλ������n/16
        cout<<n/16;
    cout<<n%16;//��λ��
    return 0;
}