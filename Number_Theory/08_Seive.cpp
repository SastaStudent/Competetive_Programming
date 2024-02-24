#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void seive(vector<int>&primes,int n)
{
    bool arr[n+1];
    for(int i=0;i<=n;i++) arr[i]=true;
    arr[0]=arr[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(arr[i]==true)
        {
            for(int p=i*i;p<=n;p+=i)
            {
                arr[p]=false;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(arr[i]==true) primes.push_back(i);
    }
}
int main()
{
    vector<int>primes;
    seive(primes,100000);
    for(int i=0;i<primes.size();i++) cout<<primes[i]<<" ";
    return 0;
}