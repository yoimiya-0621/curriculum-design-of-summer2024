#include <bits/stdc++.h>
using namespace std;
int main()
{
    int time,pass;//��ǰʱ���뾭��ʱ��
    cin>>time>>pass;
    int min=time/100*60+time%100+pass;//��ȫ��ת��Ϊ����
    int hour=min/60;//Сʱ
    min-=hour*60;
    printf("%d%02d",hour,min);
    return 0;
}