#include<iostream>
using namespace std;
int main()
{
    int n;
    //taking input
    cin>>n;
    //taking ith bit
    int i;
    cin>>i;
    //check set or not
    //for this we need to take and with 2^i;
    //calculating 2^i using left shift.
    int calc=1<<i;
    if((n&calc)==0) cout<<"uset"<<endl;
    else cout<<"set"<<endl;
    return 0;
}