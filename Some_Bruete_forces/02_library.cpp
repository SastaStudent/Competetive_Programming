#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define loop(i,n) for(int k=i;k<n;k++)
using namespace std;
int main()
{
    list<int>ans;
    for(int i=1;i<=15;i++) ans.push_back((rand()%100));
    
    for(auto it=ans.begin();it!=ans.end();it++)
    {
        cout<<*it<<" ";//print
    }
    cout<<endl;
    for(auto it=ans.rbegin();it!=ans.rend();it++)
    {
        cout<<*it<<" ";//reverse print
    }
    ans.sort();//inbuilt sort
    cout<<"\nSorted"<<endl;
     for(auto elements:ans)
    {
        cout<<elements<<" ";//print
    }
    cout<<"\n";
    cout<<ans.front()<<" front"<<endl;//front data access
    cout<<"back "<<ans.back()<<endl;//back data access
    ans.push_back(123);//insert at back(last)
    ans.push_front(321);//insert at front(start)
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
    ans.reverse();//reverse inbuilt
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
    //merge fn.. both list must be sorted
    list<int>second={1,2,3,4,5,6,7};
    ans.sort();
    ans.merge(second);//merge two list into one.
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
    /*list.clear()
    list.erase(iterator)
    list.remove(value)//all occurence of value is deleted*/
    return 0;
}