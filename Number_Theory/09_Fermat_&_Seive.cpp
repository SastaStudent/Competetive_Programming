#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void seive(vector<long>&primes,int n)
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
long helper(long a,long k,int n)
{
    if(k==0) return 1;
    if(k==1) return a;
    //return ((a %n)*(helper(a,k-1,n)%n))%n;
    long out;
    if(k%2==0)
    {
        long small=helper(a,k/2,n);
        out=((small%n)*(small%n))%n;
        //return out;
    }
    else{
        long small=helper(a,k-1,n);
        out =(a+n)%n;
        out=((a%n) *(small%n))%n;
    }
    return (out+n)%n;
}
bool fermat(long n)
{
    int t=15;
    if(n==2 || n==3) return true;
     
    while(t-->0)
    {
        //making range (2,n-2)
        //formula min+rand()%(max-min+1);
        long a= 2+ rand()%(n-3);
        long power = helper(a,n-1,n);
        
        //a^p-1 mod p=1; if yes th
        if((power % n) != 1) 
        {
            cout<<power<<" Power"<< "Remainder: "<<power%n<<endl;
            cout<<"A: "<<a<<" Power: "<<n-1<<endl;
            return false;
        }
    }
    return true;
}
int main()
{
    vector<long>arr;
    seive(arr,10000);
    for(int i=0;i<arr.size();i++)
    {
        if(fermat(arr[i])==false) cout<<"NO, "<<arr[i]<<" is not Prime"<<endl;
       // else cout<<"NO, "<<arr[i]<<" is not Prime"<<endl;
       // cout<<arr[i]<<" ";
    }
    return 0;
}