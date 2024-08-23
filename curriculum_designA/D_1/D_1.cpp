#include <bits/stdc++.h>
using namespace std;
void menu()
{
    cout<<"1.创建链表"<<'\n';
    cout<<"2.插入节点"<<'\n';
    cout<<"3.删除节点"<<'\n';
    cout<<"4.链表遍历输出"<<'\n';
    cout<<"5.查询节点"<<'\n';
    cout<<"6.退出"<<'\n';
}
template<class T>
class node{
    public:
        T data;
        node* next=NULL;
        node* head=NULL;
    int size=0;
        void creat(T a[],int s)//创建链表
        {
            node* p=head;
            node* q=head;
            size=s;
            for(int i=0;i<s;i++)
            {
                q=new node;
                q->data=a[i];
                if(head==NULL){
                    head=q;
                }
                else{
                    p->next=q;
                }
                p=q;
            }
        }
        T search(int x)//查询
        {
            node* p=head;
            if(x>size)
            {
                cout<<"不存在此节点"<<'\n';
            }
            else{
                for(int i=0;i<x-1;i++)
                {
                    p=p->next;
                }
                return p->data;
            }
        }
        void insert(T data2,int x)//插入
        {
            if(x<0||x>size+1)
            {
                cout<<"输入不合法！"<<'\n';
            }
            else{
	            node* p=head;
	            node* s=new node;
	            s->data=data2;
	            
	            if(x==1){
	                s->next=head;
	                head=s;
	            }
	            else{
	                for(int i=0;i<x-2;i++)
	                {
	                    p=p->next;
	                }
	                s->next=p->next;
	                p->next=s;
	            }
	            
	            size++;
	        }
        }
        void erase(int x)//删除节点
        {
            if(x>size||x<0)
                cout<<"该节点不存在！"<<'\n';
            else{
                node* p=head;
                if(x==1){
                    head=p->next;
                    delete p;
                }
                else{
                    for(int i=0;i<x-2;i++)
                    {
                        p=p->next;
                    }
                    node* s=p->next;
                    p->next=p->next->next;
                    delete s;
                }
            }
        }
        void print()//遍历输出链表
        {
            node* p=head;
            for(int i=0;i<size;i++)
            {
                cout<<p->data<<' ';
                p=p->next;
            }
            cout<<'\n';
        }
};
int main()
{
    int ty=1;
    int cnt=0;
    while(ty!=6)
    {
        menu();
        cout<<"请输入：";
        cin>>ty;
        while(ty<=0||ty>6)
        {
            cout<<"输入不合法，请重新输入:"<<'\n';
            cin>>ty;
    	}
            if(ty==1)
            {
                cout<<"1.   int型"<<'\n';
                cout<<"2.   double型"<<'\n';
                cout<<"3.   char型"<<'\n';
                cout<<"请输入你想创建的链表类型：";
                int ty2;
                cin>>ty2;
                while(ty2<1||ty2>3){
                    cout<<"输入不合法，重新输入";
                    cin>>ty2;
                }
                cout<<"请输入要创建的初始链表的大小：";
                int s;
                cin>>s;
                if(ty2==1)
                {
                    int a[s];
                    for(int i=0;i<s;i++)
                        cin>>a[i];
                    node<int>n;
                    n.creat(a,s);
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
                    while(ty!=6)
                    {
                        while(ty>6||ty<=1){
                            cout<<"输入不合法，请重新输入:";
                            cin>>ty;
                        }
                        if(ty==2){
                            int data2,x;
                            cout<<"输入要插入的数值和位置:";
                            cin>>data2>>x;
                            n.insert(data2,x);
                            n.print();
                        }
                        else if(ty==3)
                        {
                            int x;
                            cout<<"请输入要删除的节点的位置:";
                            cin>>x;
                            n.erase(x);
                            n.print();
                        }
                        else if(ty==4)
                        {
                            n.print();
                        }
                        else if(ty==5)
                        {
                            cout<<"请输入要查询的节点：";
                            int x;
                            cin>>x;
                            cout<<n.search(x)<<'\n';
                        }
                        else if(ty==6)
                        return 0;
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
                    
                }
                else if(ty2==2)
                {
                    double a[s];
                    for(int i=0;i<s;i++)
                        cin>>a[i];
                    node<double>n;
                    n.creat(a,s);
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
                    while(ty!=6)
                    {
                        while(ty>6||ty<=1){
                            cout<<"输入不合法，请重新输入:";
                            cin>>ty;
                        }
                        if(ty==2){
                            double data2;
							int x;
                            cout<<"输入要插入的数值和位置:";
                            cin>>data2>>x;
                            n.insert(data2,x);
                            n.print();
                        }
                        else if(ty==3)
                        {
                            int x;
                            cout<<"请输入要删除的节点的位置:";
                            cin>>x;
                            n.erase(x);
                            n.print();
                        }
                        else if(ty==4)
                        {
                            n.print();
                        }
                        else if(ty==5)
                        {
                            cout<<"请输入要查询的节点：";
                            int x;
                            cin>>x;
                            cout<<n.search(x)<<'\n';
                        }
                        else if(ty==6)
                        	return 0;
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
                    
                }
                else if(ty2==3){
                    char a[s];
                    for(int i=0;i<s;i++)
                        cin>>a[i];
                    node<char>n;
                    n.creat(a,s);
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
                    while(ty!=6)
                    {
                        while(ty>6||ty<=1){
                            cout<<"输入不合法，请重新输入:";
                            cin>>ty;
                        }
                        if(ty==2){
                            char data2;
							int x;
                            cout<<"输入要插入的数值和位置:";
                            cin>>data2>>x;
                            n.insert(data2,x);
                            n.print();
                        }
                        else if(ty==3)
                        {
                            int x;
                            cout<<"请输入要删除的节点的位置:";
                            cin>>x;
                            n.erase(x);
                            n.print();
                        }
                        else if(ty==4)
                        {
                            n.print();
                        }
                        else if(ty==5)
                        {
                            cout<<"请输入要查询的节点：";
                            int x;
                            cin>>x;
                            cout<<n.search(x)<<'\n';
                        }
                        else if(ty==6)
                            return 0;
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
                    
                }
            }
            else if(ty==6)
                break;
            else
            {
                cout<<"还未创建链表";
            }
            cin>>ty;
        
    }
    return 0;
}