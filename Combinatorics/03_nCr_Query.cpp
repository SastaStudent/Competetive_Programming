#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int N=1e6+10;
int fact[N];
int Inverse[N];
int moduloInverse(int a,int b,int&x,int&y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int small=moduloInverse(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return small;
}
void factorial()
{
    fact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%MOD;
        int x,y;
        int ans =moduloInverse(fact[i],MOD,x,y);
        Inverse[i]=x;
    }
}
int main()
{
    int tc;
    cin>>tc;
    factorial();
    while(tc--)
    {
        int n,r;
        cin>>n>>r;
        int ans=((fact[n]*1LL*Inverse[n-r])%MOD+MOD)%MOD;
        ans =((ans*1LL*Inverse[r])%MOD+MOD)%MOD;
        cout<<"nCr : "<<ans<<endl;
    }
    return 0;
}