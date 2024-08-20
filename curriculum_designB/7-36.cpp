#include <bits/stdc++.h>
using namespace std;
void print(double a,double b){//输出式子
    if(b>=0)
    printf("%.1lf+%.1lfi",a,b);
    else
    printf("%.1lf%.1lfi",a,b);
}
void print2(double a,double b){//输出结果
    if(abs(a)<0.05&&abs(b)<0.05)
    {
        cout<<"0.0";
    }
    else if(abs(a)<0.05&&b!=0)
        printf("%.1lfi",b);
    else if(abs(b)<0.05&&a!=0)
        printf("%.1lf",a);
    else if(b>0)
    printf("%.1lf+%.1lfi",a,b);
    else
    printf("%.1lf%.1lfi",a,b);
}
int main()
{
    double a1,a2,b1,b2;
    cin>>a1>>b1>>a2>>b2;
    cout<<'(';print(a1,b1);cout<<')';
    cout<<" + "; 
    cout<<'(';print(a2,b2);cout<<')';
    cout<<" = ";
    print2(a1+a2,b1+b2);
    cout<<'\n';
    
     cout<<'(';print(a1,b1);cout<<')';
    cout<<" - ";
    cout<<'(';print(a2,b2);cout<<')';
    cout<<" = ";
    print2(a1-a2,b1-b2);
    cout<<'\n';
    
     cout<<'(';print(a1,b1);cout<<')';
    cout<<" * "; 
    cout<<'(';print(a2,b2);cout<<')';
    cout<<" = ";
    print2(a1*a2-b1*b2,b1*a2+a1*b2);
    cout<<'\n';
    
     cout<<'(';print(a1,b1);cout<<')';
    cout<<" / "; 
    cout<<'(';print(a2,b2);cout<<')';
    cout<<" = ";
    print2((a1*a2+b1*b2)/(a2*a2+b2*b2),(b1*a2-a1*b2)/(a2*a2+b2*b2));
    return 0;
}