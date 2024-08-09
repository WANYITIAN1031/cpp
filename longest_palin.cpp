#include <bits/stdc++.h>

using namespace std;

string cnt(string s,int left,int right)
{
    while(left>=0&&right<s.size()&&s[left]==s[right])
    {
        left = left -1;
        right = right +1;
    }
    return s.substr(left+1,right-left-1);
}

string solve(string s)
{
    string res = "";
    for(int i=0;i<s.size();i++)
    {
        /*偶数个数的回文串*/
        string tmp1 = cnt(s,i,i+1);
        res = res.size()>tmp1.size()?res:tmp1;
        /*奇数个数的回文串*/
        string tmp2 = cnt(s,i,i);
        res = res.size()>tmp2.size()?res:tmp2;
        cout<<res<<endl;
    }
    return res;
}

int main()
{
    string s = "babad";
    cout<<solve(s);
    system("pause");
    return 0;
}