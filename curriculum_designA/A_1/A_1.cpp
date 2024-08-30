#include <bits/stdc++.h>
using namespace std;
const int N=1010;
void menu();//菜单
class Manage;//管理系统类
class Train_Ticket{//车次车票类
    public:
    friend class Manage;
        int id;
        string start_station;
        string end_station;
        int depature_time_hour;
        int depature_time_min;
        double pass_time;
        int capacity;
        int sailed_ticket;
};
class Manage{
    public:
        void add();//录入车次
        void show();//浏览
        void search();//查询
        void buy_ticket();//购票
        void refund_ticket();//退票
        void save();//保存到文件
};
int n,cnt=0;
Train_Ticket t[N];//车票车次，不超过n，现有cnt个车次
Manage p;//管理系统的对象，需要对象来调用成员函数
int now=time(NULL);//获取当前时间
int now_hour=now%(3600*24)/3600+8;//换算为现在的时间
int now_min=now%(3600*24)%3600/60;
int main()
{
    cout<<"输入最大的车次数目"<<'\n';
    cin>>n;
    int ty=0;
    while(1){
        menu();
        cin>>ty;
        while(ty<1||ty>6){
            cout<<"输入不合法，请重新输入：";
            cin>>ty;
        }
        if(ty==1) {
            p.add();
            p.save();
        }
        else if(ty==2)
            p.show();
        else if(ty==3)
            p.search();
        else if(ty==4){
            p.buy_ticket();
            p.save();
        }
        else if(ty==5){
            p.refund_ticket();
            p.save();
        }
        else 
            break;
        int ty2;
        cout<<"是否继续，继续按1，退出按0"<<'\n';
        cin>>ty2;
        if(ty2==0)
            break;
        system("cls");
    }
    return 0;
}
void menu()
{
    cout<<"~~~~~~欢迎使用车票管理系统!~~~~~~"<<'\n';
    cout<<"     =====================     "<<'\n';
    cout<<"        1.录入车票信息          "<<'\n';
    cout<<"        2.浏览车票信息          "<<'\n';
    cout<<"        3.查询车票信息          "<<'\n';
    cout<<"        4.售票                 "<<'\n';
    cout<<"        5.退票                 "<<'\n';
    cout<<"        6.退出系统             "<<'\n';
    cout<<"请选择：";
}
void Manage::save()
{
    ofstream outFile("Train_Ticket.txt",ios::out);
    if(!outFile)
        cerr<<"Error"<<'\n';
    else{
        for(int i=0;i<cnt;i++)
        {
            outFile<<t[i].id<<' '<<t[i].start_station<<' '<<t[i].end_station<<' ';
            outFile<<t[i].depature_time_hour<<':'<<t[i].depature_time_min<<' ';
            outFile<<t[i].pass_time<<' '<<t[i].capacity<<' '<<t[i].sailed_ticket;
            outFile<<'\n';
        }
    }
}
void Manage::add(){
    cout<<"您要录入几个车次信息：";
    int k;
    char ch;
    cin>>k;
    cout<<"请按照车号、起点、终点、发车时间、行车时间、载客量、已售票量的顺序输入"<<'\n';
    for(int i=0;i<k;i++)
    {
        cin>>t[i+cnt].id>>t[i+cnt].start_station>>t[i+cnt].end_station>>
        t[i+cnt].depature_time_hour>>ch>>t[i+cnt].depature_time_min>>
        t[i+cnt].pass_time>>t[i+cnt].capacity>>t[i+cnt].sailed_ticket;
    }
    cnt+=k;
}
void Manage::show(){
    cout<<"车号、起点、终点、发车时间、行车时间、载客量、已售票量"<<'\n';
    for(int i=0;i<cnt;i++)
    {
        cout<<t[i].id<<' '<<t[i].start_station<<' '<<t[i].end_station<<' ';
        cout<<t[i].depature_time_hour<<':';
        printf("%02d ",t[i].depature_time_min);
        cout<<t[i].pass_time<<' '<<t[i].capacity<<' '<<t[i].sailed_ticket;
        if(t[i].depature_time_hour<now_hour||t[i].depature_time_hour==now_hour&&t[i].depature_time_min>now_min)
        {
            cout<<' '<<"已发车";
        }
        cout<<'\n';
    }
}
void Manage::search(){
    cout<<"按车次号查询请按1，按终点站查询请按2：";
    int ty;
    cin>>ty;
    if(ty==1)
    {
        int tid;
        cin>>tid;
        for(int i=0;i<cnt;i++)
        {
            if(t[i].id==tid){
                cout<<t[i].id<<' '<<t[i].start_station<<' '<<t[i].end_station<<' ';
                cout<<t[i].depature_time_hour<<':';
                printf("%02d ",t[i].depature_time_min);
                cout<<t[i].pass_time<<' '<<t[i].capacity<<' '<<t[i].sailed_ticket;
                cout<<'\n';
                break;
            }
        }
    }
    else{
        string station;
        cin>>station;
        for(int i=0;i<cnt;i++)
        {
            if(t[i].end_station==station){
                cout<<t[i].id<<' '<<t[i].start_station<<' '<<t[i].end_station<<' ';
                cout<<t[i].depature_time_hour<<':';
                printf("%02d ",t[i].depature_time_min);
                cout<<t[i].pass_time<<' '<<t[i].capacity<<' '<<t[i].sailed_ticket;
                cout<<'\n';
                break;
            }
        }
    }
}
void Manage::buy_ticket()
{
    int id;
    cout<<"请选择购买的车次：";
    cin>>id;
    for(int i=0;i<cnt;i++)
        {
            if(t[i].id==id){
                if(t[i].sailed_ticket<t[i].capacity&&
                (now_hour<t[i].depature_time_hour||now_hour==t[i].depature_time_hour&&now_min<t[i].depature_time_min))
                {
                    cout<<"购票成功"<<'\n';
                    t[i].sailed_ticket+=1;
                }
                else if(t[i].sailed_ticket>=t[i].capacity)
                    cout<<"购票失败，余票不足"<<'\n';
                else
                    cout<<"购票失败，该班次已发车"<<'\n';
            		break;
            }
        }
}
void Manage::refund_ticket(){
    int id;
    cout<<"请选择要退票的车次：";
    cin>>id;
    for(int i=0;i<cnt;i++)
        {
            if(t[i].id==id){
                if(now_hour<t[i].depature_time_hour||now_hour==t[i].depature_time_hour&&now_min<t[i].depature_time_min)
                {
                    cout<<"退票成功"<<'\n';
                    t[i].sailed_ticket-=1;
                }
                else
                    cout<<"退票失败，该班次已发车"<<'\n';
            		break;
            }
        }
}
