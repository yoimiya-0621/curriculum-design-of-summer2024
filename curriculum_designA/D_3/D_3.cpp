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
    //cout<<"�ֱ�����n������������strald����ʼ���ˣ���m��ÿm���˳���һ���ˣ�"<<'\n';
    cin>>n>>stratld>>m;
    stratld%=n;
    Node* first=new Node;//ͷ�ڵ�
    first->x=1;//ͷ�ڵ��ֵΪ1
    Node* p=first;//����ͷ�ڵ�
    Node* ptr=NULL;//��¼��ʼ�Ľڵ㣬ptr
    Node* t=NULL;//�м�ڵ�t������ѭ������Ĵ���
    if(stratld==1){
        ptr=first;
    }
    for(int i=2;i<=n;i++)
    {
        t=p;//�洢���ڵĽڵ�
        p->next=new Node;//���ڽڵ����һ���ڵ����½��Ľڵ�
        p=p->next;//�ƶ�����һ���ڵ�
        p->last=t;//��һ���ڵ����һ���ڵ�Ϊ���εĽڵ�
        p->x=i;//��ֵ
        if(i==stratld){
            ptr=p;//Ѱ�ҿ�ʼѭ����λ��
        }
        if(i==n){
            p->next=first;
            first->last=p;//ĩ��λ����
        }
    }
    ptr=ptr->last;
    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<m;k++)//��m����
        {
            ptr=ptr->next;
        }
        ans.push_back(ptr->x);//����m�ĳ��е��¶���
        ptr->last->next=ptr->next;//���к���һ���ڵ����һ���ڵ��Ϊ���нڵ����һ���ڵ�
        ptr->next->last=ptr->last;//���к���һ���ڵ����һ���ڵ��Ϊ���нڵ����һ���ڵ�
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';//����¶���
    return 0;
}