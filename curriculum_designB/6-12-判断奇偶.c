#include <stdio.h>

int even( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);
    
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int even( int n ){
    if(n&1)
        return 0;
    else
        return 1;
}