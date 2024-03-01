#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int arr[N];
const int SegSize = 1e7 + 10;
int Segment_tree[SegSize];
void buildTree(int start, int end, int index)
{
    // base case for leaf node
    if (start == end)
    {
        Segment_tree[index] = arr[start];
        return;
    }
    // for internal node
    int mid = start + (end - start) / 2;
    buildTree(start, mid, index * 2 + 1);
    buildTree(mid + 1, end, index * 2 + 2);
    Segment_tree[index] = Segment_tree[2 * index + 1] + Segment_tree[2 * index + 2];
}
void update(int start,int end,int idx,int value,int index)
{
    //base case change on leaf node
    if(start==end)
    {
        arr[idx]=value;
        Segment_tree[index]=value;
        return;
    }
    int mid=start+(end-start)/2;
    if(idx>mid)
    {
        //right-subtree
        update(mid+1,end,idx,value,index*2+2);
    }
    else {
        //left-subtree
        update(start,mid,idx,value,index*2+1);
    }
    //computing again due to changes
    Segment_tree[index] = Segment_tree[2 * index + 1] + Segment_tree[2 * index + 2];

}
int query(int start,int end,int index,int L,int R)
{
    //completely outside
    if(end<L || R<start) return 0;
    //completely inside
    if(start>=L && R>=end) return Segment_tree[index];
    //partially inside or partially outside
    int mid=start+(end-start)/2;
    int ans1=query(start,mid,index*2+1,L,R);
    int ans2=query(mid+1,end,index*2+2,L,R);
    return ans1+ans2;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
         
    }
    int treeSize = 4 * n;
    buildTree(0, n - 1, 0);
   
    int Q;
    cin >> Q;
    while (Q--)
    {
        int idx, value;
        cin >> idx >> value;
        //update
        update(0,n-1,idx,value,0);
        //range find..
        int left,right;
        cin>>left>>right;
        cout<<query(0,n-1,0,left,right)<<endl;
      
    }

    return 0;
}