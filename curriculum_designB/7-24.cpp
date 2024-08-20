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
int main()
{
    int a,b;
    scanf("%d/%d",&a,&b);
    cout<<a/gcd(a,b)<<'/'<<b/gcd(a,b);
    return 0;
}