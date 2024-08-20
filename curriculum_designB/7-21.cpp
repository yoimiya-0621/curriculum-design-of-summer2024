#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        for(int j=i;j<=sqrt(n);j++)
        {
            if(i*i+j*j==n)
            {
                flag=1;
                cout<<i<<' '<<j<<'\n';
                break;
            }
        }
    }
    if(!flag)
        cout<<"No Solution";
    return 0;
}