#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    string a[105];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j+1<n-i;j++)
        {
            if(a[j]>a[j+1])
                swap(a[j+1],a[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<'\n';
        cout<<a[i];
    }
    return 0;
}