#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int x;
        Node* next;
        Node* last;
};
int n,m,stratld;
vector<int>ans;
int main()
{
    //cout<<"分别输入n（总人数），strald（开始的人），m（每m个人出队一个人）"<<'\n';
    cin>>n>>stratld>>m;
    stratld%=n;
    Node* first=new Node;//头节点
    first->x=1;//头节点的值为1
    Node* p=first;//保存头节点
    Node* ptr=NULL;//记录开始的节点，ptr
    Node* t=NULL;//中间节点t，用于循环链表的创建
    if(stratld==1){
        ptr=first;
    }
    for(int i=2;i<=n;i++)
    {
        t=p;//存储现在的节点
        p->next=new Node;//现在节点的下一个节点是新建的节点
        p=p->next;//移动到下一个节点
        p->last=t;//下一个节点的上一个节点为本次的节点
        p->x=i;//赋值
        if(i==stratld){
            ptr=p;//寻找开始循环的位置
        }
        if(i==n){
            p->next=first;
            first->last=p;//末置位处理
        }
    }
    ptr=ptr->last;
    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<m;k++)//数m个数
        {
            ptr=ptr->next;
        }
        ans.push_back(ptr->x);//数到m的出列到新队伍
        ptr->last->next=ptr->next;//出列后上一个节点的下一个节点变为出列节点的下一个节点
        ptr->next->last=ptr->last;//出列后下一个节点的上一个节点变为出列节点的上一个节点
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';//输出新队列
    return 0;
}