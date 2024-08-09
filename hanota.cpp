#include <bits/stdc++.h>

using namespace std;

void move(int n,vector<int>& A, vector<int>& B, vector<int>& C)
{
    if(n==1)
    {
        C.push_back(A.back());
        A.pop_back();
    }
    else
    {
        move(n-1,A,C,B);
        C.push_back(A.back());
        cout<<C[0]<<endl;
        A.pop_back();
        move(n-1,B,A,C);
    }
}

void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
    int n = A.size();
    move(n,A,B,C);
}

int main()
{
    vector<int> A = { 2,1,0};
    vector<int> B;
    vector<int> C;
    hanota(A, B, C);
    for(int i=0;i<C.size();i++)
        cout<<C[i]<<' ';
    system("pause");
    return 0;
}