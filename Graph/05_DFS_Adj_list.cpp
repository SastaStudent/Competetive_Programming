#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> Graph[N];
bool visited[N];
void DFS(int vertex)
{
    // take action on vertex
    cout << vertex << " ";
    visited[vertex] = true;
    for (int child : Graph[vertex])
    {
        // take action on child of vertex before calling on it.
        if (visited[child])
            continue;
        DFS(child);
        // take action before returning of child
    }
    // take action before return vertex
}
void reset()
{
    for(int i=0;i<N;i++) visited[i]=false;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<Graph[i].size();j++)
        {
            Graph[i][j]=0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; i++)
        {
            int first, second;
            cin >> first >> second;
            Graph[first].push_back(second);
            Graph[second].push_back(first);
        }
        DFS(0);
        reset();
    }
    return 0;
}