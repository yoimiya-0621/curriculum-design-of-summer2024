#include <bits/stdc++.h>
#include <conio.h>
#include <Windows.h>
using namespace std;
const int N=1e3+10;
char ch;//用于判定玩家行进方向
char mp[N][N];
char Map[N][N];//棋盘
bool a[N][N];
int n,cnt=0,ans=0,flag=0;
int dx[4]={0,1,0,-1};//用于判定方向
int dy[4]={1,0,-1,0};
map<vector<int>,bool>path;//以下三个都用于生成棋盘
map<pair<int,int>,pair<int,int>>path2;
vector<pair<int,int>>past;
int x,y;//玩家坐标
void menu()//菜单
{
    cout<<"   1.开始游戏"<<'\n';
    cout<<"   0.退出"<<'\n';
}
void init()//初始化
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            mp[i][j]=' ';
            a[i][j]=false;
        }
    cnt=0,ans=0,flag=0;
    path.clear(),path2.clear(),past.clear();
    x=0,y=0;
}
void create(int x,int y)//生成棋盘
{
    if(!a[x][y])
    {
        cnt++;
        //cout<<x<<' '<<y<<'\n';
    }
    if(x==n&&y==n&&flag==0){
        ans++;
        flag=1;
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
void print(int x,int y)//打印棋盘和玩家位置
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
    {
        cout<<"■";
        //cout<<'X';
    }
    cout<<'\n';
    for(int i=1;i<=2*n-1;i++)
    {
        cout<<"■";
        //cout<<'X';
        for(int j=1;j<=2*n-1;j++)
        {
            if(i==x&&j==y&&Map[i][j]==' ')
            {
                cout<<"我";
                continue;
            }
            if(Map[i][j]=='X')
            cout<<"■";
            else
            cout<<"  ";
            //cout<<Map[i][j];
        }
        cout<<"■";
        //cout<<'X';
        cout<<'\n';
    }
    for(int i=1;i<=2*n+1;i++)
    {
        cout<<"■";
        //cout<<'X';
    }
}
void game()
{
    int step=0;
    cout<<"请输入迷宫大小n：";
    cin>>n;
    init();
    past.push_back({1,1});
    if(n%2==0)
    n++;
    n=(n+1)/2;
    create(1,1);
    x=1,y=1;
    mp[1][1]='O';
    print(1,1);
    vector<pair<int,int>>process;
    int start=time(NULL);
    while(1)
    {
        cin>>ch;
        step++;
        system("cls");
        if(ch=='w'){
            x-=1;
            if(Map[x][y]=='X'||x<1||y<1||x>2*n-1||y>2*n-1){
                print(++x,y);
                continue;
            }
        }
        else if(ch=='s'){
            x+=1;
            if(Map[x][y]=='X'||x<1||y<1||x>2*n-1||y>2*n-1){
                print(--x,y);
                continue;
            }
        }
        else if(ch=='a'){
            y-=1;
            if(Map[x][y]=='X'||x<1||y<1||x>2*n-1||y>2*n-1){
                print(x,++y);
                continue;
            }
        }
        else if(ch=='d'){
            y+=1;
            if(Map[x][y]=='X'||x<1||y<1||x>2*n-1||y>2*n-1){
                print(x,--y);
                continue;
            }
        }
        process.push_back({x,y});
        print(x,y);
        if(x==2*n-1&&y==2*n-1){
            int now=time(NULL);
            //得分与时间与步数有关
            cout<<"恭喜你到达终点,一共走了"<<cnt<<"步,用时"<<now-start<<"秒,得分为"<<(double)cnt/step*100<<'\n';
            break;
        }
    }
    int ty=0;
    cout<<"是否查看回放"<<'\n';
    cout<<"1.  查看"<<'\n';
    cout<<"0.  不查看"<<"\n";
    cin>>ty;
    if(ty==1){
        system("cls");
        for(int i=0;i<process.size();i++)
        {
            print(process[i].first,process[i].second);
            Sleep(300);
            system("cls");
        }
    }
    else
        return;
}
int main()
{
    int T;
    while(1){
        menu();
        cin>>T;
        if(T==1){
            system("cls");
            game();
            cout<<"要继续吗"<<'\n';
            cout<<"1.  继续"<<'\n';
            cout<<"0.  退出"<<'\n';
            cin>>T;
            if(T==0)
                break;
        }
        else if(T==0)
            break;
        system("cls");
    }
    return 0;
}