#include <bits/stdc++.h>
using namespace std;
int p[35];//�洢�ֽ������
int x;
int flag=0;
void f(int n,int k)//�������ֽ�n��Ŀǰ�Ѿ��ֽ�kλ
{
    if(n==0){//�޷������ֽ⣬���
        cout<<x<<"=";
        for(int i=1;i<=k;i++)
        {
            if(i>1)
                cout<<'+';
            cout<<p[i];
        }
        flag++;//��flag���жϸ�����ֺŻ��ǻ���
        if(flag!=4&&k>1)
        cout<<';';
        else{
            cout<<'\n';
            flag=0;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(i>=p[k]){//��֤���ηֽ�������ִ���ǰһλ
            p[k+1]=i;
            f(n-i,k+1);//�ݹ�ֽ�
        }
    }
}
int main()
{
    cin>>x;
    f(x,0);
    return 0;
}