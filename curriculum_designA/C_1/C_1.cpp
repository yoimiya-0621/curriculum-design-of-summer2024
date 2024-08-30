#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll start=0,now=0;
void game()
{
    cout<<"请自行设定用时：";
    ll time_limit;
    cin>>time_limit;
    cout<<"是否需要提示,如果需要请按1,否则按0"<<'\n';
    int tips=0;
    cin>>tips;
    cout<<"在游戏过程中如果想要提示就猜0,如果已经准备好开始游戏请按1，如想退出请按0："<<'\n';
    int flag=0;
    cin>>flag;
    if(flag==1)
    {
        start=time(NULL);
        int ans=rand()%10000+1;
        if(tips==1)
        {
            cout<<"个位数字为"<<ans%10<<'\n';
        }
        int x=0;
        while(1)
        {
            cout<<"请猜数字：";
            cin>>x;
            system("cls");
            if(ans<x){
                cout<<x<<"太大了"<<'\n';
            }
            else if(ans>x)
            {
                cout<<x<<"太小了"<<'\n';
            }
            else{
                now=time(NULL);
                if(now-start<=time_limit){
                    cout<<"恭喜！正确猜出数字"<<x<<'\n';
                }
                else{
                    cout<<"很遗憾，猜出数字，但未在规定时间内，游戏失败";
                }
                break;
            }
            now=time(NULL);
            if(now-start>time_limit){
                cout<<"很遗憾，用时结束，未能在规定时间内猜出数字，数字为"<<ans;
                break;
            }
            
        }
    }
    else if(flag==0)
    return;
    else
    cout<<"输入不合法！";
}
int main()
{
    game();
    while(1)
    {
        int again=0;
        cout<<"要再来一局吗？继续请按1，退出请按0"<<'\n';
        cin>>again;
        if(again==1)
        {
            system("cls");
            game();
        }
        else
            break;
    }
    return 0;
}