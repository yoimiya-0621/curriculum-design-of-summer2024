#include <bits/stdc++.h>
using namespace std;
void menu();//�˵�
class SavingsAccount{
    private:
        int id;//�˺�
        double balance;//���
        double rate;//����������
        int lastDate;//�ϴα����������
    public:
        SavingsAccount(int date,int id,double rate);//���캯��������ʱ����
        int getId(){return id;}
        double getBalance(){return balance;}
        double getRate(){return rate;}
        void deposit(int date,double amount);  //�����ֽ�
        void withdraw(int date,double amount); //ȡ���ֽ�
        void settle(int date); //������Ϣ
        void show();//��ʾ�˻���Ϣ
        ~SavingsAccount();//��������
};
vector<SavingsAccount>my_account;
int cnt=0;
int main()
{
    int ty;
    while(1)
    {
        menu();
        cin>>ty;
        while(ty<1||ty>10){
            cout<<"���벻�Ϸ������������룺";
            cin>>ty;
        }
        if(ty==1){
            int rate=0;
            SavingsAccount *p =new SavingsAccount(0,cnt+1,rate);
            my_account.push_back(*p);
        }
        else if(ty==2){
            cout<<"��Ҫɾ�����˻���id��";  
            int x;
            my_account.erase(my_account.begin()+x);
        }
        else if(ty==3);
        else if(ty==4){
            cout<<"��������Ҫ��ѯ�˻���id��";
        }
        else if(ty==5);
        else if(ty==6);
        else if(ty==7);
        else if(ty==8);
        else if(ty==9);
        else
            break;
    }
    return 0;
}
void menu()
{
    cout<<"      ���������˻�����ϵͳ        "<<'\n';
    cout<<"        1.����                   "<<'\n';
    cout<<"        2.����                   "<<'\n';
    cout<<"        3.����                   "<<'\n';
    cout<<"        4.��ѯ                   "<<'\n';
    cout<<"        5.���                   "<<'\n';
    cout<<"        6.ȡ��                   "<<'\n';
    cout<<"        7.��Ϣ                   "<<'\n';
    cout<<"        8.�ļ�����               "<<'\n';
    cout<<"        9.�ļ�����               "<<'\n';
    cout<<"        10.�˳�                  "<<'\n';
    cout<<"��ѡ��";
}