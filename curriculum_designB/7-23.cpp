#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.size()==1){//��λ������
        printf("%c",s[0]-'0'+'a');
        return 0;
    }
    char ch[10]={' ','S','B','Q','W','S','B','Q','Y'};
    //�� ʮ �� ǧ �� ʮ �� ǧ ��
    for(int i=s.size(),j=0;i>0,j<s.size();j++,i--)
    {
        
        if(s[j]!='0'){//����ֱ�Ӷ�
            printf("%c",s[j]-'0'+'a');
            if(i>1)
                cout<<ch[i-1];//�����λ
        }
        else{//������
            while(j<s.size()&&s[j]=='0'){//�жϴ����￪ʼ�����ж��ٸ���������
                j++;
                if(j==s.size()-4&&s.size()>4){
                    cout<<'W';//������ִ���10000����Ҫ�������W��
                }
                i--;
            }
            if(j<s.size())//��֤���м��0��ĩβ�㲻��
                cout<<'a';//���һ��0������ϰ�߶��������0ֻ��һ��
            j--;
            i++;
        }
    }
    return 0;
}