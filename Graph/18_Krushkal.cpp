#include <iostream>
#include<utility>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
vector<pair<int,int>> Graph[N];
class DisjointSet
{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int n)
    {
        if (parent[n] != n)
        {
            parent[n] = find(parent[n]); // Applying path compression recursively
        }
        return parent[n];
    }

    void merge(int x, int y)
    {
        int parx = find(x);
        int pary = find(y);
        if (parx != pary)
        {
            if (rank[parx] < rank[pary])
            {
                parent[parx] = pary;
            }
            else if (rank[parx] > rank[pary])
            {
                parent[pary] = parx;
            }
            else
            {
                parent[parx] = pary;
                rank[pary]++;
            }
        }
    }
   
};
int mst(int v)
{
    vector<pair<int,pair<int,int>>> vp;
    for(int i=1;i<=v;i++)
    {
        for(auto edge:Graph[i])
        {
            vp.push_back({edge.second,{i,edge.first}});
        }
    }
    sort(vp.begin(),vp.end());
    DisjointSet unionFind(v);
    int vertex=0;
    int ans=0;
    for(auto take:vp)
    {
        
        int u=take.second.first;
        int v=take.second.second;
        int paru=unionFind.find(u);
        int parv=unionFind.find(v);
        if(paru==parv) continue;
        ans+=take.first;
        unionFind.merge(u,v);

    }
    return ans;

}
void Krushkal(int v)
{
    int ans = mst(v);
    
    cout<<"\nMinimum Weight " <<ans<<endl;

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
        Krushkal(v);
         
        reset();
    }
    return 0;
}
