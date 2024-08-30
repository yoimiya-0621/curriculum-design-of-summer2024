#include <bits/stdc++.h>
using namespace std;
const double Zero=1e-6;//用于判断是否为0
class Point
{
public:
    double x;
    double y;
    double z;
    Point( double x=0,double y=0,double z=0):x(x),y(y),z(z) {}
    Point( Point &p )
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }
    bool operator == ( Point &p )
    {
        return x==p.x && y==p.y &&
               z==p.z;
    }
    friend double Pdistance( Point &A, Point &B );//计算两点间距离
    ~Point() {}
};
double Pdistance( Point &A, Point &B )//计算两点间距离
{
    return sqrt( pow(A.x-B.x,2) + pow(A.y-B.y,2) + pow(A.z-B.z,2));
}
class Line : public Point
{
public:
    Point pA;
    Point pB;
    Line( double x=0,double y=0,double z=0,double xx=0,double yy=0,double zz=0)
        :pA(x,y,z), pB(xx,yy,zz) {}
    Line( Point &p1, Point &p2 ):pA(p1),pB(p2) {}
    void TwoPoint();//两点式
    void PointDirection();//点斜式
    void Canshu();//参数式
    void LineDirection();//计算空间直线的单位方向向量
    friend double Ldistance( Point & S, Line & L );//计算点到直线距离
    ~Line() {}
};
class plne: public Point
{
public:
    double da;
    double db;
    double dc;
    double dd;
    Point pC;
    plne( double x=0,double y=0,double z=0,double a=0,double b=0,double c=0,double d=0)
        :pC(x,y,z),da(a),db(b),dc(c),dd(d) {}
    void ThreePoint();//三点创建一个平面
    void Pointfa();//点法式
    void plnefa();//计算空间平面的单位法向量
    friend double PLdistance( Point &S, plne&P );//计算点到平面的距离
};
void Line::TwoPoint()//两点式
{
    if( pA == pB )
    {
        cout<<"两点相同，无法构成直线"<<endl;
    }
    else
    {
        cout<<"直线方程为: ";
        cout<<"(x-"<<pA.x<<")/"<<pB.x - pA.x<<" = ";
        cout<<"(y-"<<pA.y<<")/"<<pB.y - pA.y<<" = ";
        cout<<"(z-"<<pA.z<<")/"<<pB.z - pA.z<<endl;
    }
}
void Line::PointDirection()//点斜式
{
    if( pA == pB )
    {
        cout<<"两点相同，无法构成直线"<<endl;
    }
    else
    {
        double dm = pB.x - pA.x;
        double dn = pB.y - pA.y;
        double dp = pB.z - pA.z;//(dm,dn,dp)为直线的方向向量
        cout<<"直线方程为: ";
        cout<<"(x-"<<pA.x<<")/"<<dm<<" = ";
        cout<<"(y-"<<pA.y<<")/"<<dn<<" = ";
        cout<<"(z-"<<pA.z<<")/"<<dp<<endl;
    }
}
void Line::Canshu()//参数式
{
    if( pA == pB )
    {
        cout<<"两点相同，无法构成直线"<<endl;
    }
    else
    {
        //(dm,dn,dp)为直线的方向向量
        double dm = pB.x - pA.x;
        double dn = pB.y - pA.y;
        double dp = pB.z - pA.z;
        cout<<"直线方程为: ";
        cout<<"x=";
        if(dm!=0)
        {
            if(dm!=1)
            {
                if(dm==-1)
                {
                    cout<<"-";
                }
                else
                {
                    cout<<dm;
                }
            }
            cout<<"t";
            if(pA.x>0)
            {
                cout<<"+";
            }
        }
        cout<<pA.x<<"   y=";
        if(dn!=0)
        {
            if(dn!=1)
            {
                if(dn==-1)
                {
                    cout<<"-";
                }
                else
                {
                    cout<<dn;
                }
            }
            cout<<"t";
            if(pA.y>0)
            {
                cout<<"+";
            }
        }
        cout<<pA.y<<"   z=";
        if(dp!=0)
        {
            if(dp!=1)
            {
                if(dp==-1)
                {
                    cout<<"-";
                }
                else
                {
                    cout<<dp;
                }
            }
            cout<<"t";
            if(pA.z>0)
            {
                cout<<"+";
            }
        }
        cout<<pA.z<<endl;
    }
}
void Line::LineDirection()//计算单位向量
{
    //(dm,dn,dp)为直线的方向向量
    double dm = pB.x - pA.x;
    double dn = pB.y - pA.y;
    double dp = pB.z - pA.z;
    cout<<"直线的单位方向向量为: ";
    double ds = sqrt( dm*dm + dn*dn + dp*dp );
    cout<<"("<<dm/ds<<","<<dn/ds<<","<<dp/ds<<")"<<endl;
}
double Ldistance( Point & S, Line & L )//计算距离
{
    double dLAB = Pdistance( L.pA, L.pB );
    double dLAS = Pdistance( S, L.pA );
    double dLBS = Pdistance( S, L.pB );
    double cost = (dLAB*dLAB + dLAS*dLAS - dLBS*dLBS) / ( 2*dLAB*dLAS );
    double sint = sqrt(1-cost*cost);
    return dLAS*sint;
}
void plne::ThreePoint()//三点式
{
    cout<<"请输入三个点的x,y,z坐标: ";
    double x1,y1,z1,x2,y2,z2,x3,y3,z3;
    cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3;
    da = y1*z2 - y1*z3 - y2*z1 + y2*z3 + y3*z1 - y3*z2;
    db = x1*z3 - x1*z2 + x2*z1 - x2*z3 - x3*z1 + x3*z2;
    dc = x1*y2 - x1*y3 - x2*y1 + x2*y3 + x3*y1 - x3*y2;
    dd = x1*y3*z2 - x1*y2*z3 + x2*y1*z3 - x2*y3*z1 - x3*y1*z2 + x3*y2*z1;
    cout<<"平面方程为: ";
    if(da!=0)
    {
        if(da!=1)
        {
            if(da==-1)
            {
                cout<<"-";
            }
            else
            {
                cout<<da;
            }
        }
        cout<<"x";
        if(db>=0)
        {
            cout<<"+";
        }
    }
    if(db!=0)
    {
        if(db!=1)
        {
            if(db==-1)
            {
                cout<<"-";
            }
            else
            {
                cout<<db;
            }
        }
        cout<<"y";
        if(dc>=0)
        {
            cout<<"+";
        }
    }
    if(dc!=0)
    {
        if(dc!=1)
        {
            if(dc==-1)
            {
                cout<<"-";
            }
            else
            {
                cout<<dc;
            }
        }
        cout<<"z";
        if(dd>0)
        {
            cout<<"+";
        }
    }
    if(dd!=0)
    {
        cout<<dd;
    }
    cout<<"=0"<<endl;
}
void plne::Pointfa()//点法式
{
    cout<<"平面方程为: ";
    if(da!=0)
    {
        if(da!=1)
        {
            if(da==-1)
            {
                cout<<"-";
            }
            else
            {
                cout<<da;
            }
        }
        cout<<"(x";
        if(pC.x>=0)
        {
            cout<<"-"<<pC.x<<")+";
        }
        if(pC.x<0)
        {
            cout<<pC.x<<")+";
        }
    }
    if(db!=0)
    {
        if(db!=1)
        {
            if(db==-1)
            {
                cout<<"-";
            }
            else
            {
                cout<<db;
            }
        }
        cout<<"(y";
        if(pC.y>=0)
        {
            cout<<"-"<<pC.y<<")+";
        }
        if(pC.y<0)
        {
            cout<<pC.y<<")+";
        }
    }
    if(dc!=0)
    {
        if(dc!=1)
        {
            if(dc==-1)
            {
                cout<<"-";
            }
            else
            {
                cout<<dc;
            }
        }
        cout<<"(z";
        if(pC.z>=0)
        {
            cout<<"-"<<pC.z<<")=0";
        }
        if(pC.z<0)
        {
            cout<<pC.z<<")=0";
        }
    }
    cout<<endl;
}
void plne::plnefa()//计算法向量
{
    double ds = sqrt( da*da + db*db +dc*dc );
    cout<<"平面的单位法向量为: ";
    cout<<"("<<da/ds<<","<<db/ds<<","<<dc/ds<<")"<<endl;
}
double PLdistance( Point &S, plne&P )//计算点线距离
{
    return abs( S.x*P.da + S.y*P.db + S.z*P.dc + P.dd) /
           sqrt( P.da*P.da + P.db*P.db + P.dc*P.dc );
}
void PL( Point &p, Line &l )//判断点线
{
    cout<<"点与线的位置关系为: ";
    double da1 = (p.x-l.pA.x)/(l.pB.x-l.pA.x);
    double da2 = (p.y-l.pA.y)/(l.pB.y-l.pA.y);
    double da3 = (p.z-l.pA.z)/(l.pB.z-l.pA.z);
    if(da1==da2&&da2==da3)
    {
        cout<<"点在线上"<<endl;
    }
    else
    {
        cout<<"点在线外"<<endl;
    }
}
void LL( Line &l1, Line &l2 )//判断线线位置关系
{
    cout<<"两线的位置关系为: ";
    if( l1.pA==l2.pA && l1.pB==l2.pB )
    {
        cout<<"两线重合"<<endl;
        return ;
    }
    double dm1 = l1.pB.x - l1.pA.x;
    double dn1 = l1.pB.y - l1.pA.y;
    double dp1 = l1.pB.z - l1.pA.z;
    double dm2 = l2.pB.x - l2.pA.x;
    double dn2 = l2.pB.y - l2.pA.y;
    double dp2 = l2.pB.z - l2.pA.z;
    if( dm1/dm2==dn1/dn2 && dn1/dn2==dp1/dp2 )
    {
        cout<<"两线平行"<<endl;
    }
    else
    {
        if( (dm1*dm2 + dn1*dn2 + dp1*dp2) <= Zero )
        {
            cout<<"两线垂直"<<endl;
        }
        else
        {
            cout<<"两线相交"<<endl;
        }
    }
}
void PP( Point & p, plne& pl )
{
    cout<<"点与面的位置关系为: ";
    if( (p.x*pl.da + p.y*pl.db + p.z*pl.dc + pl.dd) <= Zero )
    {
        cout<<"点在面上"<<endl;
    }
    else
    {
        cout<<"点在面外"<<endl;
    }
}//判断点与面的位置关系
void LP( Line &l, plne&pl )
{
    cout<<"线与面的位置关系为: ";
    bool b1 = (l.pA.x*pl.da + l.pA.y*pl.db + l.pA.z*pl.dc + pl.dd) <= Zero;
    bool b2 = (l.pB.x*pl.da + l.pB.y*pl.db + l.pB.z*pl.dc + pl.dd) <= Zero;
    if(b1&&b2)
    {
        cout<<"线在面内"<<endl;
        return ;
    }
    double dm = l.pB.x - l.pA.x;
    double dn = l.pB.y - l.pA.y;
    double dp = l.pB.z - l.pA.z;
    if( ( dm*pl.da + dn*pl.db + dp*pl.dc ) <= Zero )
    {
        cout<<"线面平行"<<endl;
    }
    else
    {
        if(dm/pl.da==dn/pl.db && dn/pl.db==dp/pl.dc )
        {
            cout<<"线面垂直"<<endl;
        }
        else
        {
            cout<<"线面相交"<<endl;
        }
    }
}//判断线与面的位置关系
void PPL( plne& pl1, plne& pl2 )
{
    cout<<"面与面的位置关系为: ";
    if( pl1.da/pl2.da==pl1.db/pl2.db && pl1.db/pl2.db==pl1.dc/pl2.dc )
    {
        cout<<"面面平行"<<endl;
    }
    else
    {
        if( (pl1.da*pl2.da + pl1.db*pl2.db + pl1.dc*pl2.dc) <= Zero )
        {
            cout<<"面面垂直"<<endl;
        }
        else
        {
            cout<<"面面斜交"<<endl;
        }
    }
}//判断面与面的位置关系
int main()
{
    int x1,y1,z1,x2,y2,z2,x3,y3,z3;
    cout<<"请输入两个点的坐标：";
    cin>>x1>>y1>>z1>>x2>>y2>>z2;
    Point pa1(x1,y1,z1),pa2(x2,y2,z2);
    double s1;
    s1=Pdistance( pa1, pa2 );//计算pa1,pa2两点间距离
    cout<<"两点间距离为: "<<s1<<endl;
    Line la1(pa1,pa2);
    la1.TwoPoint();//两点式
    la1.PointDirection();//点斜式
    la1.Canshu();//参数式
    la1.LineDirection();//计算空间直线的单位方向向量
    Point pa3(x3,y3,z3);
    cout<<"请输入另外一点的坐标：";
    cin>>x3>>y3>>z3;
    double s2;
    s2=Ldistance( pa3, la1 );//计算点pa3到直线la1距离
    cout<<"点到直线距离为: "<<s2<<endl;
    plne pl1,pl2(2,3,5,1,2,4,-28);
    pl1.ThreePoint();//三点创建一个平面
    pl2.Pointfa();//点法式
    pl2.plnefa();//计算空间平面的单位法向量
    double s3;
    s3=PLdistance( pa3, pl2 );//计算点pa3到平面pl2的距离
    cout<<"点到平面的距离为: "<<s3<<endl;
    PL( pa3, la1 );//判断点pa3与线la1的位置关系
    Line la2(2,6,4,5,1,2),la3( pa1, pa3);
    LL( la2, la3 );//判断线la2与线la3的位置关系
    PP( pa3, pl1 );//判断点pa3与面pl1的位置关系
    LP( la3, pl1 );//判断线la3与面pl1的位置关系
    PPL( pl1, pl2 );//判断面与面的位置关系
    return 0;
}
