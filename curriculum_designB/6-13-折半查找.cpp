
#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType  *R; 
  int  length;
} SSTable;                      

void  Create(SSTable &T)
{ int i;
  T.R=new ElemType[MAXSIZE+1];
  cin>>T.length;
  for(i=1;i<=T.length;i++)
     cin>>T.R[i].key;   
}

int  Search_Bin(SSTable T, KeyType k);

int main () 
{  SSTable T;  KeyType k;
   Create(T);
   cin>>k;
   int pos=Search_Bin(T,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

/* 请在这里填写答案 */
int  Search_Bin(SSTable T, KeyType k)
{
    int l=1,r=T.length,mid,flag=0;
    while(l<r){
        mid=(l+r)>>1;
        if(k>T.R[mid].key)
            l=mid+1;
        else if(k<T.R[mid].key)
            r=mid;
        else{
            flag=1;
            break;
        }
    }
    if(flag)
        return mid;
    else
        return 0;
}