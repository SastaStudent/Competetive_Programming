#include<iostream>
#include<vector>
#include<ctime>
#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

long long computer(long long n)
{
    if(n==0 || n==1) return 0;
    long long result=n;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            result = (result*(i-1))/i;
        }
    }
    //if n>1 then perform line 21 ;
    if(n>1) result=(result*(n-1))/n;
    return result;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        long long n;
        cin >> n;
        auto start = high_resolution_clock::now();
        cout << computer(n) << endl;
        auto stop = high_resolution_clock::now();//
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
    return 0;
}
