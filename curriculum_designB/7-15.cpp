#include <bits/stdc++.h>
using namespace std;
double jie(int i)//计算阶乘-分子
{
    double sum=1;
    for(int j=2;j<=i;j++)
        sum*=j;
    return sum;
}
double jie2(int i)//计算分母
{
    double sum=1;
    for(int j=3;j<=i;j+=2)
        sum*=j;
    return sum;
}
double f(int i){
    double x=jie(i)/jie2(2*i+1);
    return x;
}
int main()
{
    double sum=1;
    double x;
    cin>>x;
    for(int i=1;;i++)
    {
        sum+=f(i);
        if(f(i)<x)
            break;
    }
   printf("%.6lf",sum*2);
    return 0;
}