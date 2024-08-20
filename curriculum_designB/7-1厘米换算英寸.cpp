#include <bits/stdc++.h>
using namespace std;
int main()
{
    double mili;
    cin>>mili;
    cout<<(int)(mili/30.48)<<' '<<(int)(12*(mili/30.48-(int)(mili/30.48)));
    return 0;
}