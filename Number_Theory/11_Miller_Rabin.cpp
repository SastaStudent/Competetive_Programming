#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
long binaryExpo(long a,long s,long n)
{
    long res=1;
    while(s>0)
    {
        if(s&1)
        {
            //set
            res =((res%n)*(a%n))%n;
        }
        s>>=1;
        a=((a%n)*(a%n))%n;
    }
    return res;
}
bool check_composite(long a,long s,long d,long n)
{
    long x=binaryExpo(a,d,n);//a^d
    //next term is squre of previous term
    //like a^d -->a^2d --> a^4d --->a^8d...>so on
    //if anyone divides by n.. then number is prime else composite..
    //(a^d-1)(a^d+1)(a^2d+1)(a^4d+1)..(s-1)times... (a)^2^s *d. and so on...
    //in case of (a^d-1)%n= ..from property a^d%n - 1%n...
    /* a^d%n range from 0 to n-1.. and -1%n= n-1 due to property (-a)%m = (-a+m)%m...
    so, if a^d%n =1 .. then we can say it is divisible by n
    
    for other case..
    (a^2d+1)%n = a^2d %n + 1%n
               = 0 to n-1 + 1.... so if a^2d%n = -1 or n-1... using property (-a)%m..
               we can say it is divisible by n*/

    if(x==1 or x==n-1) return false;//not composite
    for(int i=1;i<s;i++)
    {
        x=(x*x)%n;
        if(x==n-1) return false;//not composite.


    }
    return true;//if not divisible then composite.

}
bool miller_Rabin_NFA(long n)
{
    if(n<=0) return false;
    if(n<4) return n==2 || n==3;
    /*n-1 = (a)^2^s *d */
    long d=n-1;
    long s=0;
    while(d%2==0)
    {
        s++;
        d/=2;
    }
    int t=15;
    //cout<<"Enter test cases"<<endl;
    //cin>>t;
    while(t--)
    {
        long a=2+rand() %(n-3);
        if(check_composite(a,s,d,n)==true) return false;

    }
    return true;//number is prime
    //cout<<s<<" "<<d<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        bool ans=miller_Rabin_NFA(n);
        if(ans==true) cout<<"Yes, "<<n<<" is Prime"<<endl;
        else cout<<"No, "<<n<<" is not Prime"<<endl;
    }
    return 0;
}