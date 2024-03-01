#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int N=1e2+10;
int Catalan[N];
void precompute()
{
    Catalan[0]=Catalan[1]=1;
    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<i;j++)
        {
            //formuls Ci += Cj*Ci-j-1;
            Catalan[i] = (Catalan[i] + ((Catalan[j] * 1LL * Catalan[i - j - 1]) % MOD)) % MOD;
        }

    }
}
int main()
{
    int tc;
    cin>>tc;
    //precompute catalan series  1 1 2 5 14 42 ..so on
    /*C0 =C1 =1.
    for n<2 Ci = 1.
    for n>=2 Cn=Sigma i= 0 to n-1 (Ci * Cn-i-1).*/
    precompute();
    while(tc--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<Catalan[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}