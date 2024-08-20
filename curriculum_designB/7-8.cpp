#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<"Speed: "<<n<<" - ";
    if(n>60)
        cout<<"Speeding";
    else
        cout<<"OK";
    return 0;
}