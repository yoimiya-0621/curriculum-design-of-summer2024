#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Count_Digit ( const int N, const int D )
{
    if(N==0)
    {
        if(D==0)
            return 1;
        else
            return 0;
    }
    int ans=0;
    int x=N;
    if(x<0)
        x=-x;
    while(x)
    {
        if(x%10==D)//如果个位数是D
            ans++;
        x/=10;//除10去除个位
    }
    return ans;
}