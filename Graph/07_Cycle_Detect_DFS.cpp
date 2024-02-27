#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> Graph[N];
bool visited[N];
bool DFS(int vertex,int parent)
{
     
     
    visited[vertex] = true;
    for (int child : Graph[vertex])
    {
        if(visited[child] && parent==child) continue;
         
        if (visited[child]) return true;
       
        bool found = DFS(child,vertex);
        if(found) return true;
        
    }
    return false;
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
        bool ans = DFS(0,-1);
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
        reset();
    }
    return 0;
}