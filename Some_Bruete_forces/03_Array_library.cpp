#include <iostream>
#include <vector>
#include<array>
#include<algorithm>
using namespace std;
int main()
{
   
    
    constexpr int n=10;
    array<int,n>arr;
    for(int i=0;i<n;i++) arr[i]=rand()%100;
    for(int element :arr) cout<<element<<" ";
    cout<<endl;
    array<int,n>::iterator it =arr.begin();
    array<int,n>::iterator it2=arr.end();
    sort(it,it2);
    for(auto it:arr) cout<<it<<" ";
    if(binary_search(it,it2,64)) cout<<"\nYes"<<endl;
    else cout<<"\nNo\n";
    //copy allow using assignment operator
    //can be access by at();
    int *ptr=arr.data();
    for(int i=0;i<n;i++) cout<<ptr[i]<<" ";
    

    

 

    return 0;
}