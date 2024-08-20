#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    cout<<a<<a+1<<a+2<<' ';
    cout<<a<<a+1<<a+3<<' ';
    cout<<a<<a+2<<a+1<<' ';
    cout<<a<<a+2<<a+3<<' ';
    cout<<a<<a+3<<a+1<<' ';
    cout<<a<<a+3<<a+2;
    cout<<'\n';

    cout<<a+1<<a<<a+2<<' ';
    cout<<a+1<<a<<a+3<<' ';
    cout<<a+1<<a+2<<a<<' ';
    cout<<a+1<<a+2<<a+3<<' ';
    cout<<a+1<<a+3<<a<<' ';
    cout<<a+1<<a+3<<a+2;
    cout<<'\n';

    cout<<a+2<<a<<a+1<<' ';
    cout<<a+2<<a<<a+3<<' ';
    cout<<a+2<<a+1<<a<<' ';
    cout<<a+2<<a+1<<a+3<<' ';
    cout<<a+2<<a+3<<a<<' ';
    cout<<a+2<<a+3<<a+1;
    cout<<'\n';

    cout<<a+3<<a<<a+1<<' ';
    cout<<a+3<<a<<a+2<<' ';
    cout<<a+3<<a+1<<a<<' ';
    cout<<a+3<<a+1<<a+2<<' ';
    cout<<a+3<<a+2<<a<<' ';
    cout<<a+3<<a+2<<a+1;
    cout<<'\n';
    return 0;
}