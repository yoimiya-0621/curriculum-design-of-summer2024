#include <bits/stdc++.h>
using namespace std;
int p[100010];
int main()
{
    int a,n,x,w=0;
    cin>>a>>n;
    if(n==0){//特判
        cout<<0;
        return 0;
    }
    int k=0;
    for(int i=n,j=1;j<=n,i>=1;j++,i--)//j表示当前位
    {
        x=i*a;//处理每一位
        k=0;
        while(x){
            p[j+k]+=x%10;
            w=max(w,j+k);
            if(p[j+k]>=10){//需要进位，用k来控制进位
                p[j+k+1]+=1;
                p[j+k]%=10;
            w=max(w,j+k+1);//位数
            }
            k++;
            x/=10;
        }
    }
    for(int i=w;i>=1;i--)
        cout<<p[i];//输出结果
    return 0;
}