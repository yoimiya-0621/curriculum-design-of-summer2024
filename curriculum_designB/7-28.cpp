#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=0;
    map<int,int>mp;//��map��Ǻ����Ƿ�ɸ��
    int num=n,nx=1,m=1;//����numֻ���ӣ�ֻʣһֻʱ��ѡ����
    while(num>1){
        for(int i=1;i<=3;i++){
            while(mp[nx]==1){nx++;if(nx==n+1)nx=1;}
            if(i==3){//ÿ�εĵ���ֻ��ɸ��
                mp[nx]=1;
                num--;
            }
            else
                nx++;
            if(nx==n+1)//�߽紦��
                nx=1;
        }
    }
    for(int i=1;i<=n;i++)
        if(mp[i]==0){//�ҵ�δ��ɸ�µĺ���������
            cout<<i;
            break;
        }
    return 0;
}