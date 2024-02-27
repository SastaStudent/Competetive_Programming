#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> Graph[N];
bool visited[N];
void BFS(int vertex)
{
    queue<int>pending;
    pending.push(vertex);
    visited[vertex]=true;
    while(!pending.empty())
    {
        int ver=pending.front();
        cout<<ver<<" ";
        pending.pop();
        for(int child:Graph[ver])
        {
            if(!visited[child]) pending.push(child);
            visited[child]=true;
        }
    }
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
        BFS(0);
        reset();
    }
    return 0;
}