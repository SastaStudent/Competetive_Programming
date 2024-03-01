#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
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
    // ll sum(int *arr,int n)
    // {
    //      ll sum=0;
    //     for(int i=0;i<n-1;i++)
    //     {
    //         sum=sum+ (arrc[i]+arrc[i+1]);
    //     }
    //     return sum;
        
    // }
    void solve()
    {
        ll n=input.take();
        ll half=(n+1)/2;
        if(n%2==1)
        {
           
            cout<<half*1LL*half<<endl;
            return;
        }
        cout<<(half+1)*1LL*(n/2)<<endl;
        return;
        
        

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
 