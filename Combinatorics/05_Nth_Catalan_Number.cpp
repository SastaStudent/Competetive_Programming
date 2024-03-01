#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int C(int n,int k)
{
    int nk=k+1;
    int dp[nk]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(k,i);j>0;j--)
        {
            dp[j]=dp[j]+dp[j-1];
        }
    }
    return dp[k];
}
int Nth(int n)
{
    if(n<0) return 0;
    if(n<2) return 1;
    int nCr =C(2*n,n);
    int res= nCr/(n+1);
    return res;


}
int Cmod(int n,int k)
{
    int nk=k+1;
    int dp[nk]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(k,i);j>0;j--)
        {
            dp[j]=(((long long)dp[j]+dp[j-1])%mod+mod)%mod;
        }
    }
    return dp[k];
}
int modInverse(int n,int m,int &x,int&y)
{
    if(m==0)
    {
        x=1;
        y=0;
        return n;
    }
    int x1,y1;
    int small = modInverse(m,n%m,x1,y1);
    x=y1;
    y=x1 - (n/m)*y1;
    return small;
}
int NthMod(int n)
{
    if(n<0) return 0;
    if(n<2) return 1;
    int nCr=Cmod(2*n,n);
    int x,y;
    int modinv = modInverse(n+1,mod,x,y);
    int res = ((nCr *1LL*x)%mod+mod)%mod;
    return res;

     
}
int main()
{
    int tc;
    cin>>tc;
    /*Nth calatalan = (1/(n+1))*2nCn*/
    while(tc--)
    {
        int n;
        cin>>n;
        cout<<"Nth Catalan number :"<<Nth(n)<<endl;
        cout<<"Nth Catalan number :"<<NthMod(n)<<endl;
        cout<<endl;
        
    }
    return 0;
}