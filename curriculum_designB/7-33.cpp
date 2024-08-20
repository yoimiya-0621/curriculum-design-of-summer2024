#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    int r=b%a;
    while(r)
    {
        b=a;
        a=r;
        r=b%a;
    }
    return a;
}
int main(){
    int a1,b1,a2,b2;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
    int a=a1*b2+a2*b1;
    int b=b1*b2;
    int c=gcd(a,b);
    if(c==b)
        cout<<a/c;
    else
        cout<<a/c<<'/'<<b/c;
    return 0;
}