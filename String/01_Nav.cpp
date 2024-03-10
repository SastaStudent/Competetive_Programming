#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void FindPattern(string s,string pat)
{
    int wordSize=s.size();
    int patSize=pat.size();
    for(int i=0;i<=wordSize-patSize;i++)
    {
        bool found=true;
        for(int j=0;j<patSize;j++)
        {
            //cout<<i<<endl;
            if(s[i+j]!=pat[j]){
                found=false;
                break;
            }
        }
        if(found) cout<<i<<endl;
    }
}
int main()
{
    string s;
    string pat;
    cin>>s>>pat;
    FindPattern(s,pat);
    return 0;
}