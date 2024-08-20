#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int s1=0,s2=0;
    s2=3*T;//最终乌龟跑的距离
    int i;
    for(i=0;i<T/10*10;){//计算兔子跑的距离，按照整10分钟计算
        if(s1<=i*3)//小于乌龟的距离就跑10分钟
        {
            s1+=90;
            i+=10;
        }
        else{//否则休息30分钟
            i+=30;
        }
    }
    if(i<T&&s1<=T/10*10*3){//最后的不到10分钟的时间，如果小于乌龟就跑
        s1+=T%10*9;
    }
    if(s1>s2){
        cout<<"^_^ "<<s1;
    }
    else if(s1<s2){
        cout<<"@_@ "<<s2;
    }
    else
        cout<<"-_- "<<s1;
    return 0;
}