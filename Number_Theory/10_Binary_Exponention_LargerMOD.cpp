#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e18+7;
long long binary_multiply(long long a,long long b)
{
    long long ans=0;
    while(b>0)
    {
        if(b&1)
        {
            //set bit
            ans=(ans+a)%mod;
        }
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
long long binary_expo(long long n,long long k)
{
    long long res=1;
    while(k>0)
    {
        if(k&1)
        {
            //set bit
            res=binary_multiply(res,n);
        }
        k>>=1;
        n=binary_multiply(n,n);
    }
    return res;
}
int main()
{
    long long n, k;
    cin >> n >> k;
    cout << binary_expo(n, k);
    return 0;
}