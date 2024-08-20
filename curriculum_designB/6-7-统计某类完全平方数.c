#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
    
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */
int IsTheNumber ( const int N )
{
    if((int)sqrt(N)*(int)sqrt(N)!=N)//如果不是完全平方数，返回0
        return 0;
    
    int a[10]={0};
    int x=N;
    while(x){
        a[x%10]++;//用数组储存每位数字,x%10表示个位
        x/=10;
    }
    for(int i=0;i<10;i++)
        if(a[i]>=2){//满足至少两位数字相同
            return 1;
        }
    return 0;
}