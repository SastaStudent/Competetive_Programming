#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        vector<int>freq(32,0);
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[j]&(1<<i)) freq[i]++;
            }
        }
        //finding unique number
        //if every element present thrice except one(ONEEE) %3
        //if ----------------------twice -------------------%2
        //so. ----------------------------------------------%n.
        int result=0;
        for(int i=0;i<32;i++)
        {
            if(freq[i]%2==1) result+=(1<<i);
            //cout<<freq[i]<<endl;
        }
        cout<<result<<endl;

    }
return 0;
}