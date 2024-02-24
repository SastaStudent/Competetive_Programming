#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
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
    int t;
    cout<<"Enter number of times to check a number"<<endl;
    cin>>t;
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
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cout<<"Enter number to check prime or not"<<endl;
        cin>>n;
        if(fermat(n)) cout<<"Yes,"<<n<<" is Prime"<<endl;
        else cout<<"No, "<<n<<" is not Prime"<<endl;
        
    }
return 0;
}