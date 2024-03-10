#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void FindPattern(string s,string pat)
{
    int wordSize=s.size();
    int patSize=pat.size();
    int sumWord=0;
    for(int i=0;i<patSize;i++) sumWord+=s[i]-'a'+1;
    int sumPat=0;
    for(int i=0;i<patSize;i++) sumPat+=pat[i]-'a'+1;

    //taking hashValue a=1, b=2,c=3....so on
    for(int i=0;i<=wordSize-patSize;i++)
    {
        if(sumWord==sumPat)
        {
            bool found=true;
            for(int j=0;j<patSize;j++)
            {
                if(s[i+j]!=pat[j])
                {
                    found=false;
                    break;
                }

            }
            if(found) cout<<"Yes, Pattern found at index "<<i<<endl;
        }
        sumWord=sumWord-(s[i]-'a'+1);
        sumWord=sumWord+(s[i+patSize]-'a'+1);
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