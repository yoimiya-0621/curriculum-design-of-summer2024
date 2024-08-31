#include <bits/stdc++.h>
using namespace std;
void menu();//打印菜单
class SavingsAccount{
    public:
        int id;//账户id
        double balance=0;//账户余额
        double balance2=0;//中途存款的余额，此部分不论定期活期，只按照活期利息算
        double rate=0;//利率
        int lastDate;//上一次余额变更的日期
        int type;//账户类型
        int date;//
        SavingsAccount(int d,int i,double r,int tp,int m)//构造函数，用于创建账户
        {
            date=d;
            id=i;
            rate=r;
            type=tp;
            balance2=0;
            balance=m;
            lastDate=0;
        }
        void deposit(int d,double a) //存款函数
        {
            if(type==1&&d>365){//一年期定期账户的存款
                cout<<"已超过存款期限！，无法存入"<<'\n';
                return;
            }
            if(type==2&&d>365*3){//三年期定期账户的存款
                cout<<"已超过存款期限！，无法存入"<<'\n';
                return;
            }
            if(type==3&&d>365*5){//五年期定期账户的存款
                cout<<"已超过存款期限！，无法存入"<<'\n';
                return;
            }
            balance2+=balance2*0.35*0.01*(d-lastDate);
            balance+=balance*rate/12/30*(d-lastDate);
            balance2+=a;
            lastDate=d;
            cout<<"存款成功，当前余额为"<<balance+balance2<<'\n';
        }
        void withdraw(int d,double a)//取款
        {
            if(type==1&&d>365){
                d=365;
            }
            if(type==2&&d>365*3){
                d=365*3;
            }
            if(type==3&&d>365*5){
                d=365*5;
            }//若取款日期超过定期账户的存款日期时，则按存款日期算
            balance2+=balance2*0.35*0.01*(d-lastDate);
            balance+=balance*0.35*0.01/12/30*(d-lastDate);
            lastDate=d;
            if(balance+balance2<a)//存款小于取款，不能取出
            {
                cout<<"余额不足"<<'\n';
                return ;
            }
            cout<<balance2<<'\n'<<a<<' ';
            if(balance2>=a)
            {
                balance2-=a;
                //cout<<"nn";
            }
            else{
                balance2=0;
                balance-=(a-balance2);
                //cout<<"hh";
            }
            cout<<"取款成功，当前余额为"<<balance+balance2<<'\n';
        }
        void settle(int d)//结息，到达存款日期时，才可以结算利息
        {
            if(type==1&&d<365){
                cout<<"未到结息日期，不能结息"<<'\n';
                return;
            }
            if(type==2&&d<365*3){
                cout<<"未到结息日期，不能结息"<<'\n';
                return;
            }
            if(type==3&&d<365*5){
                cout<<"未到结息日期，不能结息"<<'\n';
                return;
            }
            balance2+=balance2*0.35*0.01*(d-lastDate);
            balance+=balance*rate/12/30*(d-lastDate);
            lastDate=d;
            cout<<"结息成功，你将取出"<<balance+balance2<<"元"<<'\n';
            balance=0;
            balance2=0;
        }
        void show()//显示账户信息
        {
            cout<<id<<' '<<balance+balance2<<' ';
                if(type==1)
            cout<<"定期账户--一年期";
                if(type==2)
            cout<<"定期账户--三年期";
                if(type==3)
            cout<<"定期账户--五年期";
                if(type==4)
            cout<<"活期账户";
            cout<<' '<<rate<<'\n';
        }
        void file_out()//文件导出函数
        {
            ifstream inFile("bank_account.txt",ios::in);
            if(!inFile)
                cerr<<"Error"<<'\n';
            else{
                int i,b,t,r;
                    inFile>>i>>b;
                    cout<<i<<' '<<b;
                    inFile>>t;
                    if(t==1)
                        cout<<"定期账户--一年期";
                    if(t==2)
                        cout<<"定期账户--三年期";
                    if(t==3)
                        cout<<"定期账户--五年期";
                    if(t==4)
                        cout<<"活期账户";
                    inFile>>r;
                    cout<<' '<<r<<'\n';
            }
        }
};
vector<SavingsAccount>my_account;//用vector来存储多个账户
int cnt=100000;
double sum=0;
void file_in()
{
    ofstream outFile("bank_account.txt",ios::out);
    if(!outFile)
        cerr<<"Error"<<'\n';
    else{  
        for(int i=0;i<my_account.size();i++)
        {
            outFile<<my_account[i].id<<' '<<my_account[i].balance+my_account[i].balance2;
            int type=my_account[i].type;
                    if(type==1)
                        outFile<<" 定期账户--一年期 ";
                    if(type==2)
                        outFile<<" 定期账户--三年期 ";
                    if(type==3)
                        outFile<<" 定期账户--五年期 ";
                    if(type==4)
                        outFile<<" 活期账户 ";
            outFile<<' '<<my_account[i].rate<<'\n';
        }
    }
}
void file_out()//文件导出函数
{
    ifstream inFile("bank_account.txt",ios::in);
    if(!inFile)
        cerr<<"Error"<<'\n';
    else{
                
        for(int j=0;j<my_account.size();j++)
        {
            int i;
            double b,t,r;
            string s;
                    inFile>>i>>b>>s;
                    cout<<i<<' '<<b<<' '<<s;
                    // inFile>>t;
                    // if(t==1)
                    //     cout<<"定期账户--一年期";
                    // if(t==2)
                    //     cout<<"定期账户--三年期";
                    // if(t==3)
                    //     cout<<"定期账户--五年期";
                    // if(t==4)
                    //     cout<<"活期账户";
                    inFile>>r;
                    cout<<' '<<r<<'\n';
        }
    }
}
int main()
{
    int ty;
    menu();
    cin>>ty;
    while(1)
    {
        while(ty<1||ty>10){
            cout<<"输入不合法请重新输入："<<'\n';
            cin>>ty;
        }
        if(ty==1){
            double r=0;
            int tp=0;
            cout<<"请选择账户类型"<<'\n';
            cout<<"1.  定期账户"<<'\n';
            cout<<"2.  活期账户"<<'\n';
            int t=0;
            cin>>t;
            while(t<1||t>2){
                cout<<"输入不合法，请重新输入"<<'\n';
                cin>>t;
            }
            if(t==1){
                cout<<"请选择存款期限:"<<'\n';
                cout<<"1.   一年期"<<'\n';
                cout<<"2.   三年期"<<'\n';
                cout<<"3.   五年期"<<'\n';
                int flag=0;
                cin>>flag;
                while(flag<1|flag>3){
                    cout<<"输入不合法请重新输入"<<'\n';
                }
                if(flag==1)
                    {r=1.35;tp=1;}//一年期，设置利率为1.35
                else if(flag==2)
                    {r=1.75;tp=2;}//三年期，设置利率为1.75
                else
                    {r=1.8;tp=3;}//五年期，设置利率为1.8
            }
            else
                {r=0.35;tp=4;}//活期，利率为0.35
            cout<<"请输入初始存款金额"<<'\n';
            double m;
            cin>>m;
            r*=0.01;
            SavingsAccount *p =new SavingsAccount(0,cnt+1,r,tp,m);
            my_account.push_back(*p);
            cnt++;
        }
        else if(ty==2){
            cout<<"请输入要删除的账户id"<<'\n';  
            int x;
            cin>>x;
            my_account.erase(my_account.begin()+x-100001);
            cnt--;
        }
        else if(ty==3){
            for(int i=0;i<my_account.size();i++)
            {
                my_account[i].show();
            }
        }
        else if(ty==4){
            cout<<"请输入账户id";
            int x;
            cin>>x;
            for(int i=0;i<my_account.size();i++)
            {
                if(my_account[i].id==x)
                my_account[i].show();
            }
        }
        else if(ty==5){
            int flag=0;
            cout<<"请输入账户id:"<<"\n";
            int x;
            cin>>x;
            cout<<"请输入已存款日期和存款金额"<<'\n';
            int d,m;
            cin>>d>>m;
            for(int i=0;i<my_account.size();i++)
            {
                if(my_account[i].id==x)
                    {
                        my_account[i].deposit(d,m);
                        flag=1;
                        cout<<"现在余额为"<<my_account[i].balance+my_account[i].balance2<<"元"<<'\n';
                        break;
                    }
            }
            if(!flag)
            cout<<"账户不存在"<<'\n';
        }
        else if(ty==6)
        {
            int flag=0;
            cout<<"请输入账户id:"<<'\n';
            int x;
            cin>>x;
            cout<<"请输入已存款日期和取款金额"<<'\n';
            int d,m;
            cin>>d>>m;
            for(int i=0;i<my_account.size();i++)
            {
                if(my_account[i].id==x)
                {
                    my_account[i].withdraw(d,m);
                    flag=1;
                    cout<<"现在余额为"<<my_account[i].balance+my_account[i].balance2<<"元"<<'\n';
                    break;
                }
            }
            if(!flag)
            cout<<"账户不存在"<<'\n';
        }
        else if(ty==7)
        {
            cout<<"请输入账户id:"<<'\n';
            int x;
            cin>>x;
            if(x<=100000||x>cnt)
            {
                cout<<"账户不存在"<<'\n';
                continue;
            }
            cout<<"请输入结息日期"<<'\n';
            int d;
            cin>>d;
            my_account[x-100001].settle(d);
        }
        else if(ty==8){
            file_in();
        }
        else if(ty==9){
            file_out();
        }
        else if(ty==10)
            break;
        cout<<"继续请按1，退出按0：";
		int flag;
		cin>>flag;
		if(flag){
			system("cls");
		}
		else
			return 0;
        menu();
        cin>>ty;
    }
    return 0;
}
void menu()
{
    cout<<"个人银行账户管理系统：        "<<'\n';
    cout<<"        1.开户                  "<<'\n';
    cout<<"        2.销户                   "<<'\n';
    cout<<"        3.汇总                   "<<'\n';
    cout<<"        4.查询                "<<'\n';
    cout<<"        5.存款                  "<<'\n';
    cout<<"        6.取款                "<<'\n';
    cout<<"        7.结息                  "<<'\n';
    cout<<"        8.文件导入               "<<'\n';
    cout<<"        9.文件导出               "<<'\n';
    cout<<"        10.退出                  "<<'\n';
    cout<<"请选择:";
}