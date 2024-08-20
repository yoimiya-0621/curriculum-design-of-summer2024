#include <bits/stdc++.h>
using namespace std;
int main()
{
    double open,high,low,close;
    cin>>open>>high>>low>>close;
    if(open>close)
        cout<<"BW-Solid";
    else if(open==close)
        cout<<"R-Cross";
    else
        cout<<"R-Hollow";

    if(low<min(open,close)&&high>max(open,close)){
        cout<<" with Lower Shadow and Upper Shadow";
    }
    else if(low<min(open,close)){
        cout<<" with Lower Shadow";
    }
    else if(high>max(open,close))
        cout<<" with Upper Shadow";
    return 0;
}