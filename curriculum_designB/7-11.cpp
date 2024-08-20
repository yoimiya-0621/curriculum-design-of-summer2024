#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x;
    cin>>x;
    if(x<=15)
        printf("%.2lf",4*x/3);
    else
        printf("%.2lf",2.5*x-17.5);
    return 0;
}