#include <iostream>
#include<utility>
#include <vector>
#include <queue>
#include<algorithm>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
const int N = 1e5 + 10;
vector<pair<int,int>> Graph[N];
void Dijkstra(int v)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    vector<int>dist(v,INF);
    dist[0]=0;
    vector<bool>visited(v,false);
    while (!pq.empty())
    {
        auto front = pq.top();
        pq.pop();
        int edge=front.second;
        int weight=front.first;
        if(visited[edge]) continue;
        visited[edge]=true;
        for(auto adj:Graph[edge])
        {
            if(dist[edge]+adj.second < dist[adj.first])
            {
                dist[adj.first]=dist[edge]+adj.second;
                pq.push({dist[adj.first],adj.first});
            }
        }


    }
    for(int a:dist)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    

    

}

void reset() {
    for (int i = 0; i < N; i++) {
        Graph[i].clear(); // Clear the vectors
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int first, second,weight;
            cin >> first >> second >> weight;
            Graph[first].push_back({second,weight});
            Graph[second].push_back({first,weight});
        }
        Dijkstra(v);
         
        reset();
    }
    return 0;
}
