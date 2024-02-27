#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+2;
bool DFS(int vertex, vector<int> adj[], int *visited)
{
    visited[vertex] = 1;
    for (int child : adj[vertex])
    {
        if (visited[child] == 1)
            return true;
        if (visited[child] == 2)
            continue;
        if (visited[child] == 0)
        {
            if (DFS(child, adj, visited))
                return true;
        }
    }
    visited[vertex] = 2;
    return false;
}

bool isCyclic(int v, vector<int> adj[])
{
    int *vis = new int[v];
    for (int i = 0; i < v; i++)
        vis[i] = 0;
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            if (DFS(i, adj, vis))
                return true;
        }
    }
    delete[] vis; // Deallocate memory
    return false;
}
int main()
{
    //Directed Graph
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        vector<int>Graph[v];
        for (int i = 0; i < e; i++)
        {
            int first, second;
            cin >> first >> second;
            Graph[first].push_back(second);
             
        }
        bool ans = isCyclic(v, Graph);
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
       
    }
    return 0;
}