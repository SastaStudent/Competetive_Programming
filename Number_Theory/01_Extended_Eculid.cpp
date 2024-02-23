#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Triplet{
    public:
    int gcd,x,y;
};
Triplet Extended(int a,int b)
{
    if(b==0)
    {
        Triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    Triplet smallOut=Extended(b,a%b);
    Triplet ans;
    ans.gcd=smallOut.gcd;
    ans.x=smallOut.y;
    ans.y=smallOut.x - (a/b)*smallOut.y;
    return ans;
}
int main()
{
    //
    Triplet ans=Extended(3,7);
    int inv = ans.x;
    if(inv<0) inv+=7;
    cout<<ans.gcd<<" "<<inv<<" "<<ans.y<<endl;
return 0;
}