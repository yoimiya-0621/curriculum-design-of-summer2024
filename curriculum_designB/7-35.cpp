#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1){
        int a,b;
        scanf("%d/%d",&a,&b);
        cout<<a<<'/'<<b;
        return 0;
    }
    long long a1,b1,a2,b2;
    char ch;
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    long long a=a1*b2+a2*b1;
    long long b=b1*b2;
    long long c=gcd(abs(a),b);
    a/=c;
    b/=c;//随时约分化简
    for(int i=0;i<n-2;i++)
    {
        cin>>a2>>ch>>b2;
        long long c2=gcd(abs(a2),b2);
        a2/=c2;
        b2/=c2;
        a=a*b2+a2*b;
        b=b*b2;
        c=gcd(a,b);
        a/=c;//随时约分化简
        b/=c;
    }
    b*=n;//除以n，相当于分母乘n
    c=gcd(a,b);
    a/=c;
    b/=c;
    if(a==0)
        cout<<0;
    else if(b==1)
        cout<<a;
    else
        cout<<a<<'/'<<b;
    return 0;
}