#include <stdio.h>

void PrintN ( int N );

int main ()
{
    int N;

    scanf("%d", &N);
    PrintN( N );

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
//�ҵĴ�
void PrintN(int N)
{
    for(int i=1;i<=N;i++){//��1��N��ѭ��
        printf("%d\n",i);//��ӡ
    }
}