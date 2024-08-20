#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
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
        if(x%10==D)//�����λ����D
            ans++;
        x/=10;//��10ȥ����λ
    }
    return ans;
}