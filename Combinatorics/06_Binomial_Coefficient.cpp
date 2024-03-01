#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int binomial_Coefficient(int n,int r)
{
    //cout<<n<<" "<<r<<endl;
    if(r==0 || r==n) return 1;
    return binomial_Coefficient(n-1,r-1)+binomial_Coefficient(n-1,r);
}
int helper(int n,int r,int **memo)
{
     if(r==0 || r==n) return 1;
     if(memo[n][r]!=0) return memo[n][r];
    int small = binomial_Coefficient(n-1,r-1)+binomial_Coefficient(n-1,r);
    memo[n][r]=small;
    return small;
    

}
int binomial_memo(int n,int r)
{ 
    int **memo = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        memo[i] = new int[r+1];
        for(int j=0;j<=r;j++)
        {
            memo[i][j]=0;
        }
    }
    int ans= helper(n,r,memo);
    for(int i=0;i<=n;i++) delete[] memo[i];
    delete [] memo;
    return ans;

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
        cout<<"nCr :"<< binomial_Coefficient(n,r)<<endl;
        cout<<"nCr :"<<binomial_memo(n,r)<<endl;
    }
    return 0;
}