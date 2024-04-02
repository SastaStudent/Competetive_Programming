#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 1e5 + 10;
vector<pair<int,int>> Graph[N];

void Prim(int v) {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0, {0, 0}});
    vector<pair<int,pair<int,int>>> Edges;
    int ans = 0;
    vector<bool> visited(v, false);

    while (!pq.empty()) {
        auto take = pq.top();
        pq.pop();
        int node = take.second.second;

        if (!visited[node]) {
            Edges.push_back({take.second.first, {take.second.second,take.first}});
            visited[node] = true;
            ans += take.first;
            for (auto adj : Graph[node]) {
                pq.push({adj.second, {node, adj.first}});
            }
        }
    }

    // cout << "\nMin Cost " << ans << endl;
    for (auto ed = Edges.begin() + 1; ed != Edges.end(); ++ed) {
        int one = (*ed).first;
        int two  = (*ed).second.first;
    cout << min(one,two)<< " " << max(one,two) << " " << (*ed).second.second << endl;
}

}

void addEdge(int u, int v, int weight) {
    Graph[u].push_back({v, weight});
    Graph[v].push_back({u, weight}); // Adding reverse edge for undirected graph
}

void reset() {
    for (int i = 0; i < N; i++) {
        Graph[i].clear();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int first, second, weight;
            cin >> first >> second >> weight;
            addEdge(first, second, weight); // Adding edge to the graph
        }
        Prim(v);
        reset();
    }
    return 0;
}
