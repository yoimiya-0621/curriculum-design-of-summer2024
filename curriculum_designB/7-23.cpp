#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.size()==1){//个位数特判
        printf("%c",s[0]-'0'+'a');
        return 0;
    }
    char ch[10]={' ','S','B','Q','W','S','B','Q','Y'};
    //个 十 百 千 万 十 百 千 亿
    for(int i=s.size(),j=0;i>0,j<s.size();j++,i--)
    {
        
        if(s[j]!='0'){//非零直接读
            printf("%c",s[j]-'0'+'a');
            if(i>1)
                cout<<ch[i-1];//输出单位
        }
        else{//遇到零
            while(j<s.size()&&s[j]=='0'){//判断从这里开始后面有多少个连续的零
                j++;
                if(j==s.size()-4&&s.size()>4){
                    cout<<'W';//如果数字大于10000，需要单独输出W，
                }
                i--;
            }
            if(j<s.size())//保证是中间的0，末尾零不读
                cout<<'a';//输出一个0，按照习惯多个连续的0只读一个
            j--;
            i++;
        }
    }
    return 0;
}