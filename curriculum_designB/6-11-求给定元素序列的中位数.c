#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
ElementType Median( ElementType A[], int N )
{
    for(int gap=N/2;gap>0;gap/=2){//ϣ������
    for(int i=gap;i<N;i++)
    {
        for(int j=i-gap;j>=0&&A[j]>A[j+gap];j-=gap)
        {
                ElementType t=A[j+gap];
                A[j+gap]=A[j];
                A[j]=t;
        }
    }
    }
    return A[N/2];
}