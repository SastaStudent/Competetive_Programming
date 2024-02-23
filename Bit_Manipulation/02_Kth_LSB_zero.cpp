#include<iostream>
using namespace std;
int main()
{
    //zero from kth bit
    int n;
    cin>>n;
    int k;
    cin>>k;
    //calc 2^i+1;.
    int calc=1<<(k+1);
    //for 00(k)1111.
    int lesscalc=calc-1;
    int negation=~lesscalc;
    cout<<(n&negation)<<endl;
return 0;
}