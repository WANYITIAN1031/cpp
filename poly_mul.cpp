#include <bits/stdc++.h>

using namespace std;

void read_poly(char *s,int *col)
{
    while(*s)
    {
        int flag = 1, a = 0, i = 0;//flag代表系数的正负，a代表系数大小，i代表指数大小
        if((*s)=='+')
            s++;
        else if((*s)=='-')
        {
            flag = -1;
            s++;
        }
        while(isdigit(*s))
        {
            a = a*10 + (*s) - '0';
            s++;
        }
        if(a==0)
            a = 1;//当系数为1时，多项式不会显式地表示1x，而是x，故按照之前的程序计算，a=0,但是实际上a=1
        if((*s)!='x')//来到了最后一项，常数项
        {
            col[0] = a*flag;
            return;
        }
        else
            s++;
        if((*s)=='^')
            s++;
        while(isdigit(*s))
        {
            i = i*10 + (*s) - '0';
            s++;
        }
        if(i==0)
            i = 1;
        col[i] = a*flag;
    }
}

void mul_poly(int *col1, int *col2, int *res, int N)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            res[i+j] += col1[i]*col2[j];
}

int main()
{
    int N = 100;
    char sub1[N+1];//存放读入的多项式字符串
    char sub2[N+1];
    cin>>sub1>>sub2;
    int col1[N+1] = {0};//第i项表示指数为i时的系数
    int col2[N+1] = {0};
    read_poly(sub1,col1);
    read_poly(sub2,col2);
    int res[N*2+2] = {0};
    mul_poly(col1,col2,res,N);
    for(int i=2*N+1;i>=0;i--)
        if(res[i]!=0)
            cout<<res[i]<<' ';
    system("pause");
    return 0;
}