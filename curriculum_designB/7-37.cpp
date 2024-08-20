#include <bits/stdc++.h>
using namespace std;
int p[35];//存储分解的数字
int x;
int flag=0;
void f(int n,int k)//函数，分解n，目前已经分解k位
{
    if(n==0){//无法继续分解，输出
        cout<<x<<"=";
        for(int i=1;i<=k;i++)
        {
            if(i>1)
                cout<<'+';
            cout<<p[i];
        }
        flag++;//用flag来判断该输出分号还是换行
        if(flag!=4&&k>1)
        cout<<';';
        else{
            cout<<'\n';
            flag=0;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(i>=p[k]){//保证本次分解出的数字大于前一位
            p[k+1]=i;
            f(n-i,k+1);//递归分解
        }
    }
}
int main()
{
    cin>>x;
    f(x,0);
    return 0;
}