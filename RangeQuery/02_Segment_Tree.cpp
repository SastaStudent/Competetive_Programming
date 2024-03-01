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
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // arr[i]=i+1;
    }
    int treeSize = 4 * n;
    buildTree(0, n - 1, 0);
    for (int i = 0; i < treeSize; i++){
        cout << Segment_tree[i] << " ";
    }
    cout << endl;
    int Q;
    cin >> Q;
    while (Q--)
    {
        int idx, value;
        cin >> idx >> value;
        //update
        update(0,n-1,idx,value,0);
        for (int i = 0; i < treeSize; i++){
            cout << Segment_tree[i] << " ";
        }
        cout << endl;
    }

    return 0;
}