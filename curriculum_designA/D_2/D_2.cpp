#include <bits/stdc++.h>
using namespace std;
void menu()
{
    cout<<"错题本管理程序"<<'\n';
    cout<<"      1.添加错题信息"<<'\n';
    cout<<"      2.浏览错题信息"<<'\n';
    cout<<"      3.查询错题信息"<<'\n';
    cout<<"      4.删除错题信息"<<'\n';
    cout<<"      5.文件导入"<<'\n';
    cout<<"      6.文件导出"<<'\n';
    cout<<"      7.退出"<<'\n';
}
class node
{
    public:
        string title;
        string error;
        string ans_analy;
        string feelings;
        string source;
        string reason;
        string level;
        string type;
        string knowledge;
        node* next=NULL;
    node(string t,string e,string a,string f,string s,string r,string l,
    string tt,string k){
        title=t;
        error=e;
        ans_analy=a;
        feelings=f;
        source=s;
        reason=r;
        level=l;
        type=tt;
        knowledge=k;
    }
};
class List
{
    public:
        node* head=NULL;
        int size=0;
    void add(node data2,int x){
        if(x<1||x>size+1){
            cout<<"输入不合法！"<<'\n';
        }
        if(head==NULL){
            head=new node(data2.title,data2.error,data2.ans_analy,data2.feelings,data2.source,data2.reason
            ,data2.level,data2.type,data2.knowledge);
            size=1;
        }
        else{
	            node* p=head;
	            node* s=new node(data2.title,data2.error,data2.ans_analy,data2.feelings,data2.source,data2.reason
            ,data2.level,data2.type,data2.knowledge); 
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
    void show(){
        node* p=head;
        for(int i=0;i<size;i++)
        {
            cout<<p->title<<' '<<p->error<<' '<<p->ans_analy<<' '<<p->feelings<<' '<<p->source<<' '
            <<p->reason<<' '<<p->level<<' '<<p->type<<' '<<p->knowledge<<'\n';
            p=p->next;
        }
    }
    void search1(string x)
    {
        node* p=head;
        for(int i=0;i<size;i++)
        {
            if(p->type==x){
                cout<<p->title<<' '<<p->error<<p->ans_analy<<' '<<p->feelings<<' '<<p->source<<' '
                <<p->reason<<' '<<p->level<<' '<<p->type<<' '<<p->knowledge<<'\n';
            }
            p=p->next;
        }
    }
    void search2(string x)
    {
        node* p=head;
        for(int i=0;i<size;i++)
        {
            if(p->knowledge==x){
                cout<<p->title<<' '<<p->error<<p->ans_analy<<' '<<p->feelings<<' '<<p->source<<' '
                <<p->reason<<' '<<p->level<<' '<<p->type<<' '<<p->knowledge<<'\n';
            }
            p=p->next;
        }
    }
    void erase(string s1,string s2){
        while(head!=NULL&&head->type==s1&&head->knowledge==s2){
            head=head->next;
            size--;
        }
        node* p=head;
        for(int i=1;i<size;i++)
        {
            if(p->next->type==s1&&p->next->knowledge==s2){
                node* s=p->next;
                p->next=p->next->next;
                delete s;
                size--;
            }
            p=p->next;
        }               
    }
    void file_input()
    {
        ofstream outFile("Error_edition.txt",ios::out);
        if(!outFile)
            cerr<<"Error"<<'\n';
        else{
            node* p=head;
            for(int i=0;i<size;i++)
            {
                outFile<<p->title<<' '<<p->error<<' '<<p->ans_analy<<' '<<p->feelings
                <<' '<<p->source<<' '<<p->reason<<' '<<p->level<<' '<<p->type<<' '<<p->knowledge;
                outFile<<'\n';
                p=p->next;
            }
        }
    }
    void file_output()
    {
        ifstream inFile("Error_edition.txt",ios::in);
        if(!inFile)
            cerr<<"Error"<<'\n';
        else{
            node* p=head;
            for(int i=0;i<size;i++)
            {
                inFile>>p->title>>p->error>>p->ans_analy>>p->feelings
                >>p->source>>p->reason>>p->level>>p->type>>p->knowledge;
                cout<<p->title<<' '<<p->error<<p->ans_analy<<' '<<p->feelings<<' '<<p->source<<' '
                <<p->reason<<' '<<p->level<<' '<<p->type<<' '<<p->knowledge<<'\n';
                p=p->next;
            }
        }
    }
};
int main()
{
    menu();
    int ty=1;
    cin>>ty;
    List L;
    while(ty!=7)
    {
        while(ty<1||ty>7){
            cout<<"输入不合法，请重新输入:";
            cin>>ty;
        }
        if(ty==1)
        {
            cout<<"按照题目、错误信息、答案分析、心得体会、错题来源、错题原因、难易程度、题目类型、知识点的顺序"<<'\n';
            cout<<"请输入新的错题信息：";
            string t,e,a, f, s,r, l, tt,k;
            cin>>t>>e>>a>>f>>s>>r>>l>>tt>>k;
            node data2(t,e,a,f,s,r,l,tt,k);
            cout<<"请输入插入位置";
            int x;
            cin>>x;
            L.add(data2,x);
        }
        else if(ty==2)
        {
            L.show();
        }
        else if(ty==3){
            cout<<"按题目类型查询还是按知识点查询"<<'\n'<<"1.按类型"<<'\n'<<"2.按知识点"<<'\n';
            int x;
            cin>>x;
            if(x==1){
                string s;
                cout<<"请输入类型：";
                cin>>s;
                L.search1(s);
            }
            else if(x==2){
                string s;
                cout<<"请输入知识点：";
                cin>>s;
                L.search2(s);
            }
            else{
                cout<<"输入不合法";
            }
        }
        else if(ty==4)
        {
            cout<<"请输入指定的题目类型和知识点:";
            string s1,s2;
            cin>>s1>>s2;
            L.erase(s1,s2);
            L.show();
        }
        else if(ty==5){
            L.file_input();
        }
        else if(ty==6){
            L.file_output();
        }
        else if(ty==7)
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