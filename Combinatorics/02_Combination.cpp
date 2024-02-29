#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int factorial(int n)
{
    int res=1;
    for(int i=1;i<=n;i++)
    {
        res=(res*1LL*i)%MOD;
    }
    return (int)(res)%MOD;
}
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
int Combination(int n,int r)
{
    //formuls nCr = n!/(n-r)!*r!
    int first = factorial(n);
    int second=factorial(n-r);
    int third =factorial(r);
    //modulor inverse
    int b=MOD;
    int x,y;
    second =moduloInverse(second,b,x,y);
    int x1,y1;
    third = moduloInverse(third,b,x1,y1);
    int res=((first*1LL*x) %MOD + MOD)%MOD;
    res =((res*1LL*x1)%MOD+MOD)%MOD;
    return res;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,r;
        cin>>n>>r;
        int ans=Combination(n,r);
        cout<<"nCr : "<<ans<<endl;
    }
    return 0;
}