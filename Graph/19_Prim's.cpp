#include <iostream>
#include<utility>
#include <vector>
#include <queue>
#include<algorithm>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<pair<int,int>> Graph[N];
void Prim(int v)
{
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}});
    vector<pair<int,int>>Edges;
    int ans=0;

    vector<bool>visited(v,false);
    while(!pq.empty())
    {
        auto take = pq.top();
        pq.pop();
        int node = take.second.second;
       
        if(!visited[node])
        {
            Edges.push_back({take.second.first,take.second.second});
            visited[node]=true;
            ans+=take.first;
            for(auto adj:Graph[node])
            { 
                pq.push({adj.second,{node,adj.first}});
                 
            }
        }


    }
    cout<<"\n Min Cost "<<ans<<endl;
    for(auto ed:Edges)
    {
    cout<<ed.first<<" "<<ed.second<<endl;
    }

    

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
        }
        Prim(v);
         
        reset();
    }
    return 0;
}
/*Input
1
6 10
0 1 3
0 2 1
0 3 2
2 3 1
1 3 3
2 4 2
2 5 6
3 5 3
4 5 2
4 3 1
*/