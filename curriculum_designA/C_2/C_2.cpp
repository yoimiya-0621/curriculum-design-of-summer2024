#include <bits/stdc++.h>
using namespace std;
void menu()//菜单
{
    cout<<"      1.开始游戏"<<'\n';
    cout<<"      0.退出"<<'\n';
}
class Chess{//棋类
    public:
        char board[10][10];//棋盘
        char p='O',c='X';//p是玩家的棋子，c是电脑的棋子
        int row=3,col=3;//行，列
        void init()//初始化棋盘
        {
            for(int i=1;i<=row;i++)
                for(int j=1;j<=col;j++)
                    board[i][j]='*';
        }
        void print()//打印现在的棋盘
        {
            for(int i=1;i<=row;i++){
                if(row==3)
                cout<<"——————————"<<'\n';
                else if(row==4)
                cout<<"—————————————"<<'\n';
                else if(row==5)
                cout<<"—————————————————"<<'\n';
                for(int j=1;j<=col;j++)
                {
                    cout<<' '<<board[i][j]<<' ';
                }
                cout<<'\n';
            }
                if(row==3)
                cout<<"——————————"<<'\n';
                else if(row==4)
                cout<<"——————————————"<<'\n';
                else if(row==5)
                cout<<"——————————————————"<<'\n';
        }
        void player()//玩家下棋
        {
            int x,y;
            cin>>x>>y;
            while(board[x][y]!='*'){
                cout<<"该位置已经有棋子，请重新输入"<<'\n';
                cin>>x>>y;
            }
            board[x][y]=p;
        }
        void computer()//电脑下棋
        {
            if(row==3){//仅在棋盘大小为3的时候设置了智能AI
            //判断对角线电脑是否能直接获胜，如有则直接下
            if(board[1][1]==board[2][2]&&board[3][3]=='*'&&board[1][1]==c)
                {board[3][3]=c;return;}
            if(board[1][1]==board[3][3]&&board[2][2]=='*'&&board[1][1]==c)
                {board[2][2]=c;return;}
            if(board[3][3]==board[2][2]&&board[1][1]=='*'&&board[2][2]==c)
                {board[1][1]=c;return;}
            if(board[3][1]==board[2][2]&&board[1][3]=='*'&&board[3][1]==c)
                {board[1][3]=c;return;}
            if(board[3][1]==board[1][3]&&board[2][2]=='*'&&board[3][1]==c)
                {board[2][2]=c;return;}
            if(board[1][3]==board[2][2]&&board[3][1]=='*'&&board[2][2]==c)
                {board[3][1]=c;return;}
            for(int i=1;i<=3;i++)//判断行列电脑是否能直接获胜，如有则直接下
            {
                if(board[i][1]==board[i][2]&&board[i][1]==c&&board[i][3]=='*')
                {
                    board[i][3]=c;
                    return;
                }
                if(board[i][1]==board[i][3]&&board[i][1]==c&&board[i][2]=='*')
                {
                    board[i][2]=c;
                    return;
                }
                if(board[i][2]==board[i][3]&&board[i][2]==c&&board[i][1]=='*')
                {
                    board[i][1]=c;
                    return;
                }
                if(board[1][i]==board[2][i]&&board[1][i]==c&&board[3][i]=='*')
                {
                    board[3][i]=c;
                    return;
                }
                if(board[1][i]==board[3][i]&&board[1][i]==c&&board[2][i]=='*')
                {
                    board[2][i]=c;
                    return;
                }
                if(board[3][i]==board[2][i]&&board[3][i]==c&&board[1][i]=='*')
                {
                    board[1][i]=c;
                    return;
                }
            }
            //判断对角线玩家是否能直接获胜，如有则堵住
            if(board[1][1]==board[2][2]&&board[3][3]=='*'&&board[1][1]==p)
                {board[3][3]=c;return;}
            if(board[1][1]==board[3][3]&&board[2][2]=='*'&&board[1][1]==p)
                {board[2][2]=c;return;}
            if(board[3][3]==board[2][2]&&board[1][1]=='*'&&board[2][2]==p)
                {board[1][1]=c;return;}
            if(board[3][1]==board[2][2]&&board[1][3]=='*'&&board[3][1]==p)
                {board[1][3]=c;return;}
            if(board[3][1]==board[1][3]&&board[2][2]=='*'&&board[3][1]==p)
                {board[2][2]=c;return;}
            if(board[1][3]==board[2][2]&&board[3][1]=='*'&&board[2][2]==p)
                {board[3][1]=c;return;}
            //判断行列玩家是否能直接获胜，如有则堵住
            for(int i=1;i<=3;i++)
            {
                if(board[i][1]==board[i][2]&&board[i][1]==p&&board[i][3]=='*')
                {
                    board[i][3]=c;
                    return;
                }
                if(board[i][1]==board[i][3]&&board[i][1]==p&&board[i][2]=='*')
                {
                    board[i][2]=c;
                    return;
                }
                if(board[i][2]==board[i][3]&&board[i][2]==p&&board[i][1]=='*')
                {
                    board[i][1]=c;
                    return;
                }
                if(board[1][i]==board[2][i]&&board[1][i]==p&&board[3][i]=='*')
                {
                    board[3][i]=c;
                    return;
                }
                if(board[1][i]==board[3][i]&&board[1][i]==p&&board[2][i]=='*')
                {
                    board[2][i]=c;
                    return;
                }
                if(board[3][i]==board[2][i]&&board[3][i]==p&&board[1][i]=='*')
                {
                    board[1][i]=c;
                    return;
                }
            }
            //其他情况，优先联通电脑自己的棋子
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(board[i][j]==c)
                    {
                        for(int k=1;k<=3;k++){
                            if(board[i][k]=='*'&&k!=j)
                            {
                                board[i][k]=c;
                                return;
                            }
                            if(board[k][j]=='*'&&k!=i)
                            {
                                board[k][j]=c;
                                return;
                            }
                        }
                    }
                }
            }
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(board[i][j]==p)
                    {
                        for(int k=1;k<=3;k++){
                            if(board[i][k]=='*'&&k!=j)
                            {
                                board[i][k]=c;
                                return;
                            }
                            if(board[k][j]=='*'&&k!=i)
                            {
                                board[k][j]=c;
                                return;
                            }
                        }
                    }
                }
            }
            board[2][2]=c;//没有棋子，直接下中间
            }
            while(1)//非智能AI，随机落子
            {
                int x=rand()%row+1;
                int y=rand()%col+1;
                if(board[x][y]=='*')
                {
                    board[x][y]=c;
                    break;
                }
            }
        }
        int check()//判断是否有人获胜
        {
            if(row==3){
            for(int i=1;i<=3;i++)
            {
                if(board[i][1]==board[i][2]&&board[i][3]==board[i][1]&&board[i][1]==p)
                    return 1;
                if(board[1][i]==board[2][i]&&board[3][i]==board[1][i]&&board[1][i]==p)
                    return 1;
            }
            if(board[1][1]==board[2][2]&&board[3][3]==board[1][1]&&board[1][1]==p)
                return 1;
            if(board[3][1]==board[2][2]&&board[3][1]==board[1][3]&&board[1][3]==p)
                return 1;

            for(int i=1;i<=3;i++)
            {
                if(board[i][1]==board[i][2]&&board[i][3]==board[i][1]&&board[i][1]==c)
                    return 2;
                if(board[1][i]==board[2][i]&&board[3][i]==board[1][i]&&board[1][i]==c)
                    return 2;
            }
            if(board[1][1]==board[2][2]&&board[3][3]==board[1][1]&&board[1][1]==c)
                return 2;
            if(board[3][1]==board[2][2]&&board[3][1]==board[1][3]&&board[1][3]==c)
                return 2;
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(board[i][j]=='*')
                    return 0;
                }
            }
            return 3;
            }
            else{
                int win=0;
                for(int i=1;i<=row;i++)//判断行
                {
                    char ok=board[i][1];
                    win=0;
                    for(int j=1;j<=col;j++)
                    {
                        if(board[i][j]==ok)
                            win++;
                    }
                    if(win==row){
                        if(ok==c)
                        return 2;
                        else if(ok==p)
                        return 1;
                    }
                }
                for(int j=1;j<=col;j++)//判断列
                {
                    char ok=board[1][j];
                    win=0;
                    for(int i=1;i<=row;i++)
                    {
                        if(board[i][j]==ok)
                            win++;
                    }
                    if(win==row){
                        if(ok==c)
                        return 2;
                        else if(ok==p)
                        return 1;
                    }
                }
                win=0;
                char ok=board[1][1];
                for(int i=1;i<=row;i++)//判断主对角线
                {
                    if(board[i][i]==ok)
                    win++;
                }
                if(win==row){
                        if(ok==c)
                        return 2;
                        else if(ok==p)
                        return 1;
                    }

                win=0;
                ok=board[1][row];
                for(int i=1;i<=row;i++)//判断副对角线
                {
                    if(board[i][row+1-i]==ok)
                    win++;
                }
                if(win==row){
                        if(ok==c)
                        return 2;
                        else if(ok==p)
                        return 1;
                    }
                for(int i=1;i<=row;i++)//判断是否下满
                    for(int j=1;j<=col;j++)
                        if(board[i][j]=='*')
                            return 0;
                return 3;
            }
        }
        void game()
        {
            int flag=1;
            cout<<"请选择先后手:"<<'\n'<<"1.先手,2.后手"<<'\n';
            cin>>flag;
            cout<<"请选择棋子:"<<'\n'<<"1   O"<<'\n'<<"2   X"<<'\n';
            int x;
            cin>>x;
            while(x<1||x>2)
            {
                cout<<"输入不合法，请重新输入"<<'\n';
                cin>>x;
            }
            if(x==1){
                p='O';
                c='X';
            }
            else{
                p='X';
                c='O';
            }
            cout<<"请选择棋盘大小："<<'\n';
            cout<<"1.  3x3"<<'\n';
            cout<<"2.  4x4"<<'\n';
            cout<<"3.  5x5"<<'\n';
            cin>>x;
            while(x<1||x>3)
            {
                cout<<"输入不合法，请重新输入"<<'\n';
                cin>>x;
            }
            if(x==1){
                row=3;
                col=3;
            }
            else if(x==2){
                row=4;
                col=4;
            }
            else{
                row=5;
                col=5;
            }
            init();
            print();
            while(1)
            {
                if(flag==1)
                player();
                else
                computer();
                system("cls");
                print();
                if(check()==1){
                    cout<<"玩家获胜"<<'\n';
                    break;
                }
                else if(check()==2)
                {
                    cout<<"电脑获胜"<<'\n';
                    break;
                }
                else if(check()==3)
                {
                    cout<<"平局"<<'\n';
                    break;
                }
                flag=(flag+1)%2;
            }
        }
};
int main()
{
    int ty=1;
    while(ty!=0){
        system("cls");
        Chess chess;
        chess.game();
        menu();
        cin>>ty;
    }
    return 0;
}