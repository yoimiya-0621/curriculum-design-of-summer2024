#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int s1=0,s2=0;
    s2=3*T;//�����ڹ��ܵľ���
    int i;
    for(i=0;i<T/10*10;){//���������ܵľ��룬������10���Ӽ���
        if(s1<=i*3)//С���ڹ�ľ������10����
        {
            s1+=90;
            i+=10;
        }
        else{//������Ϣ30����
            i+=30;
        }
    }
    if(i<T&&s1<=T/10*10*3){//���Ĳ���10���ӵ�ʱ�䣬���С���ڹ����
        s1+=T%10*9;
    }
    if(s1>s2){
        cout<<"^_^ "<<s1;
    }
    else if(s1<s2){
        cout<<"@_@ "<<s2;
    }
    else
        cout<<"-_- "<<s1;
    return 0;
}