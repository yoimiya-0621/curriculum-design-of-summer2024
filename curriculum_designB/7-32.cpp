#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string>ans;
    string s;
    while(cin>>s){
        ans.push_back(s);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        if(i)
            cout<<' ';
        cout<<ans[i];
    }
    return 0;
}