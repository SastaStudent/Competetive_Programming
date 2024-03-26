#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

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
    void printParent()
    {
        for (int e : parent)
        {
            cout << e << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    DisjointSet First(n);
    int i = 0;
    int e;
    cin >> e;
    while (i < e)
    {
        int u, v;
        i++;
        cin >> u >> v;
        First.merge(u, v);
        cout << First.find(u) << " " << First.find(v) << endl;
    }
    First.printParent();
    cout << endl;
    int tc;
    cin >> tc;
    while (tc--)
    {
        int u, v;
        cin >> u >> v;
        cout << First.find(u) << " " << First.find(v) << endl;
    }
    First.printParent();
    return 0;
}
