#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial ( const int N )
{
    if(N<0){
        printf("Invalid input");
        return;
    }
    int p[100000]={0};
    p[1]=1;
    int w=1;
    for(int i=2;i<=N;i++)
    {
        int yu=0;
        for(int j=1;j<=w;j++)
        {
            p[j]*=i;
            p[j]+=yu;
            yu=p[j]/10;
            p[j]%=10;
        }
        while(yu>0)
        {
            p[++w]=yu%10;
            yu/=10;
        }
    }
    for(int i=w;i>=1;i--)
        printf("%d",p[i]);
}