#include <bits/stdc++.h>

using namespace std;

pair<int,int> cnt(string s,int left,int right)
{
    while(left>=0&&right<s.size()&&s[left]==s[right])
    {
        left = left - 1;
        right = right + 1;
    }
    //cout<<left+1<<' '<<right-1<<endl;
    return {left+1,right-1};
}

string solve(string s)
{
    int flag = 0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
                flag = 1;
                break;
        }
        }
        if(flag == 0)
            return s;
        if(s=="")return "";
        else if(s.size()==1)return s;
        string res ;
        int len = s.size();
        int m = 0;
        for(int i=0;i<len;i++)
        {
            auto p1 = cnt(s,i,i);
            auto p2 = cnt(s,i,i+1);
            if(p1.first==0)
                m = max(m,p1.second);
            if(p2.first==0)
                m = max(m,p2.second);
            if(m==(len-2))
                break;
        }
        //cout<<m<<endl;
        if(m==0)
        {
            res = s.substr(1);
            reverse(res.begin(),res.end());
            res = res + s;
        }
        else if(m!=(len-2))
        {
            res = s.substr(m+1);
            reverse(res.begin(),res.end());
            res = res + s;
        }
        else
        {
            res = s[len-1] + s;;
        }
        
        return res;
}

int main()
{
    string s = "abcd";
    cout<<solve(s);
    system("pause");
    return 0;
}