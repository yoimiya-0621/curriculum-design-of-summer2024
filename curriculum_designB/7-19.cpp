#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
     for(int i=0;i<=99;i++)
         for(int j=99;j>=i;j--)
         {
             if(98*j-n==199*i){
                 if(j)
                 cout<<i<<'.'<<j;
                 else
                     cout<<i;
                 return 0;
             }
         }
    cout<<"No Solution";
    return 0;
}