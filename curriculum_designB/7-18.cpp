#include <bits/stdc++.h>
using namespace std;
double a3,a2,a1,a0;
double f(double x){
    return a3*x*x*x+a2*x*x+a1*x+a0;
}
int main()
{
    double a,b,mid;
    cin>>a3>>a2>>a1>>a0>>a>>b;
    mid=(a+b)/2;
    while(abs(f(mid))>1e-6){
        if(f(a)*f(mid)>0){
            a=mid;
        }
        else{
            b=mid;
        }
        mid=(a+b)/2;
    }
    printf("%.2lf",mid);
    return 0;
}