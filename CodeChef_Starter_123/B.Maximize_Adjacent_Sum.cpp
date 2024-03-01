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
    void solve()
    {
        ll n=input.take();
        vector<ll>arr = input.takeVect(n);
        st.sora(arr);
        //sort(arr.begin()+n/2,arr.end());
        // int start=0,end=n-1;
        // int arrc[n];
        // int tc=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(i%2==0) arrc[start++]=arr[i];
        //     else arrc[end--]=arr[i];
        // }
        // ll sum=0;
        // for(int i=0;i<n-1;i++)
        // {
        //     sum=sum+ (arrc[i]+arrc[i+1]);
        // }
        ll sum=accumulate(arr.begin(),arr.end(),0LL);
        sum*=2;
        sum=sum-arr[0]-arr[1];
        cout<<sum<<endl;
        

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
 