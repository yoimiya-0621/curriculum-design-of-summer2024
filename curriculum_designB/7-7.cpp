#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2;
    scanf("%d:%d",&n1,&n2);
    if(n1>12)
        cout<<n1-12<<':'<<n2<<' '<<"PM";
    else if(n1==12)
        cout<<n1<<':'<<n2<<' '<<"PM";
    else
        cout<<n1<<':'<<n2<<' '<<"AM";
    return 0;
}