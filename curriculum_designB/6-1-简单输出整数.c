#include <stdio.h>

void PrintN ( int N );

int main ()
{
    int N;

    scanf("%d", &N);
    PrintN( N );

    return 0;
}
/* 你的代码将被嵌在这里 */
//我的答案
void PrintN(int N)
{
    for(int i=1;i<=N;i++){//从1到N的循环
        printf("%d\n",i);//打印
    }
}