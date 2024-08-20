#include <bits/stdc++.h>
using namespace std;
void menu();//菜单
class SavingsAccount{
    private:
        int id;//账号
        double balance;//余额
        double rate;//存款的年利率
        int lastDate;//上次变更余额的日期
    public:
        SavingsAccount(int date,int id,double rate);//构造函数，开户时调用
        int getId(){return id;}
        double getBalance(){return balance;}
        double getRate(){return rate;}
        void deposit(int date,double amount);  //存入现金
        void withdraw(int date,double amount); //取出现金
        void settle(int date); //结算利息
        void show();//显示账户信息
        ~SavingsAccount();//析构函数
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
            cout<<"输入不合法，请重新输入：";
            cin>>ty;
        }
        if(ty==1){
            int rate=0;
            SavingsAccount *p =new SavingsAccount(0,cnt+1,rate);
            my_account.push_back(*p);
        }
        else if(ty==2){
            cout<<"你要删除的账户的id：";  
            int x;
            my_account.erase(my_account.begin()+x);
        }
        else if(ty==3);
        else if(ty==4){
            cout<<"请输入你要查询账户的id：";
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
    cout<<"      个人银行账户管理系统        "<<'\n';
    cout<<"        1.开户                   "<<'\n';
    cout<<"        2.销户                   "<<'\n';
    cout<<"        3.汇总                   "<<'\n';
    cout<<"        4.查询                   "<<'\n';
    cout<<"        5.存款                   "<<'\n';
    cout<<"        6.取款                   "<<'\n';
    cout<<"        7.结息                   "<<'\n';
    cout<<"        8.文件导入               "<<'\n';
    cout<<"        9.文件导出               "<<'\n';
    cout<<"        10.退出                  "<<'\n';
    cout<<"请选择：";
}