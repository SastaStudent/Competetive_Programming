#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    //10^6 number
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        long arr[n+1];
        for(int i=0;i<=n;i++)
        {
            arr[i]=i;
        }
        arr[1]=0;
        for(int i=2;i<=n;i++)
        {
            
            if(arr[i]==i)//
            {
                arr[i]=i-1;
                for(int j=i*2;j<=n;j+=i)
                {
                    arr[j]=(long)(arr[j]*(i-1))/i;
                }
            }
        }
        for(int i=0;i<=n;i++) cout<<arr[i]<<" ";
        cout<<endl;
        //cout<<arr[n]<<endl;
         
    }

    return 0;
}