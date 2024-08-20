#include <bits/stdc++.h>
using namespace std;
const int N=1010;
void menu();//�˵�
class Manage;//����ϵͳ��
class Train_Ticket{//���γ�Ʊ��
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
        void add();//¼�복��
        void show();//���
        void search();//��ѯ
        void buy_ticket();//��Ʊ
        void refund_ticket();//��Ʊ
        void save();//���浽�ļ�
};
int n,cnt=0;
Train_Ticket t[N];//��Ʊ���Σ�������n������cnt������
Manage p;//����ϵͳ�Ķ�����Ҫ���������ó�Ա����
int now=time(NULL);//��ȡ��ǰʱ��
int now_hour=now%(3600*24)/3600+8;//����Ϊ���ڵ�ʱ��
int now_min=now%(3600*24)%3600/60;
int main()
{
    cin>>n;
    int ty=0;
    while(1){
        menu();
        cin>>ty;
        while(ty<1||ty>6){
            cout<<"���벻�Ϸ������������룺";
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
    }
    return 0;
}
void menu()
{
    cout<<"~~~~~~��ӭʹ�ó�Ʊ����ϵͳ!~~~~~~"<<'\n';
    cout<<"     =====================     "<<'\n';
    cout<<"        1.¼�복Ʊ��Ϣ          "<<'\n';
    cout<<"        2.�����Ʊ��Ϣ          "<<'\n';
    cout<<"        3.��ѯ��Ʊ��Ϣ          "<<'\n';
    cout<<"        4.��Ʊ                 "<<'\n';
    cout<<"        5.��Ʊ                 "<<'\n';
    cout<<"        6.�˳�ϵͳ             "<<'\n';
    cout<<"��ѡ��";
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
    cout<<"��Ҫ¼�뼸��������Ϣ��";
    int k;
    char ch;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>t[i+cnt].id>>t[i+cnt].start_station>>t[i+cnt].end_station>>
        t[i+cnt].depature_time_hour>>ch>>t[i+cnt].depature_time_min>>
        t[i+cnt].pass_time>>t[i+cnt].capacity>>t[i+cnt].sailed_ticket;
    }
    cnt+=k;
}
void Manage::show(){
    for(int i=0;i<cnt;i++)
    {
        cout<<t[i].id<<' '<<t[i].start_station<<' '<<t[i].end_station<<' ';
        cout<<t[i].depature_time_hour<<':';
        printf("%02d ",t[i].depature_time_min);
        cout<<t[i].pass_time<<' '<<t[i].capacity<<' '<<t[i].sailed_ticket;
        if(t[i].depature_time_hour<now_hour||t[i].depature_time_hour==now_hour&&t[i].depature_time_min>now_min)
        {
            cout<<' '<<"�ѷ���";
        }
        cout<<'\n';
    }
}
void Manage::search(){
    cout<<"�����κŲ�ѯ�밴1�����յ�վ��ѯ�밴2��";
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
    cout<<"��ѡ����ĳ��Σ�";
    cin>>id;
    for(int i=0;i<cnt;i++)
        {
            if(t[i].id==id){
                if(t[i].sailed_ticket<t[i].capacity&&
                (now_hour<t[i].depature_time_hour||now_hour==t[i].depature_time_hour&&now_min<t[i].depature_time_min))
                {
                    cout<<"��Ʊ�ɹ�"<<'\n';
                    t[i].sailed_ticket+=1;
                }
                else if(t[i].sailed_ticket>=t[i].capacity)
                    cout<<"��Ʊʧ�ܣ���Ʊ����"<<'\n';
                else
                    cout<<"��Ʊʧ�ܣ��ð���ѷ���"<<'\n';
                break;
            }
            
        }
}
void Manage::refund_ticket(){
    int id;
    cout<<"��ѡ��Ҫ��Ʊ�ĳ��Σ�";
    cin>>id;
    for(int i=0;i<cnt;i++)
        {
            if(t[i].id==id){
                if(now_hour<t[i].depature_time_hour||now_hour==t[i].depature_time_hour&&now_min<t[i].depature_time_min)
                {
                    cout<<"��Ʊ�ɹ�"<<'\n';
                    t[i].sailed_ticket-=1;
                }
                else
                    cout<<"��Ʊʧ�ܣ��ð���ѷ���"<<'\n';
                break;
            }
        }
}