#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,u,d;
    cin>>n>>u>>d;
    int t=0;
    int dist=u-d;
    while(n>u){
        n-=dist;
        t+=2;
    }
    t++;
    cout<<t;
    return 0;
    
}