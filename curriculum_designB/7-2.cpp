#include <bits/stdc++.h>
using namespace std;
int main()
{
    int time,pass;//当前时间与经过时间
    cin>>time>>pass;
    int min=time/100*60+time%100+pass;//先全部转化为分钟
    int hour=min/60;//小时
    min-=hour*60;
    printf("%d%02d",hour,min);
    return 0;
}