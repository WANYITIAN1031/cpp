#include <bits/stdc++.h>

using namespace std;

/*两种求最大公因数的方法*/

long long gcd(long long a, long long b)
{
    if(a<b)
    {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    while(b>0)
    {
        long long r = a%b;
        a = b;
        b = r;
    }
    return a;
}

long long gcd1(long long a, long long b)
{
    while(a!=b)
    {
        if(a>b)
        {
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;
}

int main()
{
    int a,b;
    cin >> a >> b;
    cout<<gcd1(a,b);
    system("pause");
    return 0;
}