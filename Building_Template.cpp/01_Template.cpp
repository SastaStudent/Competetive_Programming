#include<bits/stdc++.h>
#define what_is(x) cerr<<#x<<" "<<x<<endl;
using namespace std;
int main()
{
    int n=40;
    what_is(n);
    what_is(n*2+2);
    int n2=20;
    int hcf=__gcd(n,n2);
    what_is(hcf);
    what_is(__builtin_ffs(10));//1+least significant 1-bit of x..
    /*if x==0 return 0..
    else it return 1+index ... 1-based index
    if you want 0-based then decrease by 1.
    it return the index of first set bit from rightmost*/
    what_is(__builtin_ffs(11));

    what_is(__builtin_clz(16));
    /*number of leading zero from most significant 0-bit
    //(not sure)if(x==0) its returns an undefined value.
    only unsigned int. 32 bits.*/
   long long n3=-16;
   what_is(__builtin_clz(n3));
   what_is(__builtin_clz(0));

   what_is(__builtin_ctz(4));
   /*it gives trailing zero.. count.
   least significant 0-bits.*/
   what_is(__builtin_ctz(16));

   what_is(__builtin_popcount(11));
   /*it gives number of 1-bits*/
   
}