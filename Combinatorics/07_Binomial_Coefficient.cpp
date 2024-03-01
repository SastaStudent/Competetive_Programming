#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int binomial_dp(int n,int r)
{
    //tc O(n*r) sp O(n*r)
    int dp[n+1][r+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=r;j++)
        {
            dp[i][j]=0;
        }
    }
     // Base cases
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=min(i,r); ++j) {
            // nCr = (n-1)C(r-1) + (n-1)Cr
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
     

    return dp[n][r];

}
int binomial_Optimized_dp(int n,int r)
{
    //tc O(n*r) sp O(r)
    int dp[r+1];
    for(int i=0;i<=r;i++) dp[i]=0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,r);j>0;j--)
        {
            dp[j]=dp[j]+dp[j-1];
        }
    }
    return dp[r];

}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n,r;
        cin>>n>>r;
        //where n>=r
        //if r>n then ans is 0.. we can't compute nCr;
        //if modulo is needed then i take care of it.
        cout<<"nCr :"<< binomial_dp(n,r)<<endl;
        cout<<"nCr :"<<binomial_Optimized_dp(n,r)<<endl;
    }
    return 0;
}