#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include<numeric>
#include <algorithm>
#define ln '\n'
#define ll long long
using namespace std;
class inc
{
public:
    ll take()
    {
        ll t;
        cin >> t;
        return t;
    }
    vector<ll> takeVect(ll t)
    {
        vector<ll> vect(t);
        for (int i = 0; i < t; i++)
        {
            cin >> vect[i];
        }
        return vect;
    }
    string takeString()
    {
        string s;
        cin >> s;
        return s;
    }
};
class pri
{
    public:
    void pvect(ll s, ll end, vector<ll> vect)
    {
        for (ll i = s; i < end; i++)
        {
            cout << vect[i] << " ";
        }
        cout << endl;
    }

    void pf()
    {
        cout << "No" << endl;
    }
    void pt()
    {
        cout << "Yes" << endl;
    }
};
class sor
{
    public:
    void sora(vector<ll>& v)
    {
        sort(v.begin(), v.end());
         
    }
    void sord(vector<ll>& v)
    {
        sort(v.begin(), v.end(), greater<int>());
       
    }
    void sos(string &s)
    {
        sort(s.begin(),s.end());
    }
    void sod(string &s)
    {
        sort(s.begin(),s.end(),greater<int>());
    }

};
inc input;
sor st;
class solution{
    public:
    
    
    ll sum(int *arr,int n)
    {
         ll sum=0;
        for(int i=0;i<n-1;i++)
        {
            sum=sum+ (arr[i]+arr[i+1]);
        }
        return sum;
        
    }
    ll sueem(vector<ll>&arr,int n)
    {
         ll sum=0;
        for(int i=0;i<n-1;i++)
        {
            sum=sum+ (arr[i]+arr[i+1]);
        }
        return sum;
        
    }
    void solve()
    {
        ll n=input.take();
        ll query=input.take();
        vector<ll>arr = input.takeVect(n);
        
        ll sum=accumulate(arr.begin(),arr.end(),0LL);
        sum*=2;
        while(query--)
        {
            bool flag=true;
            int x=input.take();
            x=sum-x;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(arr[i]+arr[j]==x && flag==true)
                    {
                        
                        cout<<arr[i]<<" ";
                        for(int k=0;k<n;k++)
                        {
                            if(k!=i && k!=j) cout<<arr[k]<<" ";

                        }
                        cout<<arr[j]<<" ";
                        flag=false;
                    }
                }
            }
            if(flag) cout<<"-1";
            cout<<endl;
        }
    }
};
solution sol;

pri print;

int main()
{

    ll t = input.take();
    while (t--)
    {
        sol.solve();
    }
}
 