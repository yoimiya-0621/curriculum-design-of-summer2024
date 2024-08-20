#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=0;
    map<int,int>mp;//用map标记猴子是否被筛下
    int num=n,nx=1,m=1;//共有num只猴子，只剩一只时当选大王
    while(num>1){
        for(int i=1;i<=3;i++){
            while(mp[nx]==1){nx++;if(nx==n+1)nx=1;}
            if(i==3){//每次的第三只被筛下
                mp[nx]=1;
                num--;
            }
            else
                nx++;
            if(nx==n+1)//边界处理
                nx=1;
        }
    }
    for(int i=1;i<=n;i++)
        if(mp[i]==0){//找到未被筛下的猴子作大王
            cout<<i;
            break;
        }
    return 0;
}