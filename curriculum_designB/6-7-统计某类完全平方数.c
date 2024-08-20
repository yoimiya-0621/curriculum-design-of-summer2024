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

/* ��Ĵ��뽫��Ƕ������ */
int IsTheNumber ( const int N )
{
    if((int)sqrt(N)*(int)sqrt(N)!=N)//���������ȫƽ����������0
        return 0;
    
    int a[10]={0};
    int x=N;
    while(x){
        a[x%10]++;//�����鴢��ÿλ����,x%10��ʾ��λ
        x/=10;
    }
    for(int i=0;i<10;i++)
        if(a[i]>=2){//����������λ������ͬ
            return 1;
        }
    return 0;
}