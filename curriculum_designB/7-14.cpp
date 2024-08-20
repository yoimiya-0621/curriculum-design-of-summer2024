#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int sum=0;
    for(int i=a,j=0;i<=b;i++)
    {
        sum+=i;
        printf("%5d",i);
        if(i==b)
            break;
        j++;
        if(j==5)
        {
            j%=5;
            cout<<'\n';
        }
    }
    cout<<'\n'<<"Sum = "<<sum;
    return 0;
}