#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char ch;
char mp[N][N];
char Map[N][N];
bool a[N][N];
int n,cnt=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
map<vector<int>,bool>path;
map<pair<int,int>,pair<int,int>>path2;
vector<pair<int,int>>past;
int last_x,last_y,x,y;
void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            mp[i][j]=' ';
        }
}
void create(int x,int y)
{
    if(!a[x][y])
    {
        cnt++;
        //cout<<x<<' '<<y<<'\n';
    }
    a[x][y]=true;
    mp[x][y]='*';
    if(cnt==n*n)
    {
        return;
    }
    int k,flag=0;
    for(int k=0;k<4;k++){
        if(x+dx[k]<1||y+dy[k]<1||x+dx[k]>n||y+dy[k]>n||a[x+dx[k]][y+dy[k]])
            flag++;
    }
    if(flag==4)
    {
        create(path2[{x,y}].first,path2[{x,y}].second);
        return;
    }
    map<int,int>kk;
    int flag2=0;
    do{
        k=rand()%4;
        if(kk[k]==0)
            flag2++;
        // if(flag2==4)
        //     break;
    }while(x+dx[k]<1||y+dy[k]<1||x+dx[k]>n||y+dy[k]>n||a[x+dx[k]][y+dy[k]]);
    if(!(x+dx[k]<1||y+dy[k]<1||x+dx[k]>n||y+dy[k]>n||a[x+dx[k]][y+dy[k]])){
        path2[{x+dx[k],y+dy[k]}]={x,y};
        path[{x,y,x+dx[k],y+dy[k]}]=true;
        past.push_back({x+dx[k],y+dy[k]});
        create(x+dx[k],y+dy[k]);
    }
}
void print()
{
    // for(int i=1;i<=2*n+1;i++)
    //     cout<<"X";
    // cout<<'\n';
    for(int i=1;i<=n;i++)
    {
        //cout<<"X";
        for(int j=1;j<=n;j++)
        {
            //cout<<" ";
            Map[i*2-1][j*2-1]=' ';
            if(j!=n){
                if(path[{i,j,i,j+1}]||path[{i,j+1,i,j}])
                {
                    //cout<<" ";
                    Map[i*2-1][j*2]=' ';
                }
                else
                {
                    //cout<<"X";
                    Map[i*2-1][j*2]='X';
                }
            }
        }
        //cout<<"X";
        //cout<<'\n';
        if(i!=n)
        {
            //cout<<"X";
            for(int k=1;k<=n*2-1;k++)
            {
                if(k%2==0)
                    {
                        //cout<<"X";
                        Map[i*2][k]='X';
                        continue;
                    }
                if(path[{i,(k+1)/2,i+1,(k+1)/2}]||path[{i+1,(k+1)/2,i,(k+1)/2}])
                {
                    Map[i*2][k]=' ';
                    //cout<<" ";
                }
                else
                {
                    Map[i*2][k]='X';
                    //cout<<"X";
                }
            }
        }
        if(i!=n)
        {
            //cout<<"X";
            //cout<<'\n';
        }
    }
    // for(int i=1;i<=2*n+1;i++)
    //     cout<<"X";
    for(int i=1;i<=2*n+1;i++)
        cout<<'X';
    cout<<'\n';
    for(int i=1;i<=2*n-1;i++)
    {
        cout<<'X';
        for(int j=1;j<=2*n-1;j++)
        {
            cout<<Map[i][j];
        }
        cout<<'X';
        cout<<'\n';
    }
    for(int i=1;i<=2*n+1;i++)
        cout<<'X';
}
int main()
{
    cout<<"请输入迷宫大小n：";
    cin>>n;
    init();
    past.push_back({1,1});
    create(1,1);
    x=1,y=1;
    mp[1][1]='O';
    while(1)
    {
        ch=getchar();
        system("cls");
        if(ch=='w'){
            //mp[x+dx[0]][y+dy[0]]='O';
        }
        print();
    }
    
    return 0;
}