#include <bits/stdc++.h>
using namespace std;
int main()
{
    double year,hour;
    cin>>year>>hour;
    double wage;
    if(year<5)
        wage=30;
    else 
        wage=50;
    
    if(hour>=40)
        printf("%.2lf",1.5*wage*(hour-40)+40*wage);
    else
        printf("%.2lf",wage*hour);
    return 0;
}