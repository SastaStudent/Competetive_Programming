#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int Segment[4*N];
int arr[N];
void buildTree(int start, int end, int index)
{
    if (start == end)
    {
        Segment[index] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(start, mid, index * 2);
    buildTree(mid + 1, end, index * 2 + 1);
    Segment[index] = min(Segment[index * 2], Segment[index * 2 + 1]);
}
void update(int start, int end, int it, int value, int index)
{
    if (start == end)
    {
        arr[start] = value;
        Segment[index] = value;
        return;
    }
    int mid = start + (end - start) / 2;
    if (mid >= it)
    {
        update(start, mid, it, value, index * 2);
    }
    else
    {
        update(mid + 1, end, it, value, index * 2 + 1);
    }
    Segment[index] = min(Segment[index * 2], Segment[index * 2 + 1]);
}
int queryfind(int start, int end, int r1, int r2, int index)
{
    if (end < r1 || r2 < start)
    {
        return INT_MAX;
    }
    if (start >= r1 && r2 >= end)
    {
        return Segment[index];
    }
    int mid = start + (end - start) / 2;
    int left = queryfind(start, mid, r1, r2, 2 * index);
    int right = queryfind(mid + 1, end, r1, r2, 2 * index + 1);
    return min(left, right);
}
int main()
{
    int n, Query;
    cin >> n >> Query;
    int segsize = 4 * n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    buildTree(1, n, 1);
  
    while (Query--)
    {
        char uq;
        int i, b;
        cin >> uq >> i >> b;
        if (uq == 'q')
        {
            cout << queryfind(1, n, i, b, 1) << endl;
        }
        else
        {
            update(1, n, i, b, 1);
        }
    }
    return 0;
}