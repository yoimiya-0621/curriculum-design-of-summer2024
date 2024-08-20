#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    //由于n不大于153，所以对应的10进制数不会超过2位
    if(n>=16)//十位数，即n/16
        cout<<n/16;
    cout<<n%16;//个位数
    return 0;
}