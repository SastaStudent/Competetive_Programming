#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> movements={
    {0,1},{-1,1},{-1,0},{-1,-1},
    {0,-1},{+1,-1},{1,0},{1,1},
};
bool isvalid(int i,int j,int n,int m)
{
    return (i>=0 && j>=0 && i<n && j<m);
}
void BFS(int si, int sj, int n, int m, vector<vector<char>> &graph, vector<vector<bool>> &visited)
{
    visited[si][sj] = true;
    queue<pair<int, int>> pending;
    pending.push({si, sj});
    while (!pending.empty())
    {
        pair<int, int> p = pending.front();
        pending.pop();
        int i = p.first;
        int j = p.second;
        for(pair<int,int> movement:movements)
        {
            int newi=movement.first+i;
            int newj=movement.second+j;
            if(!isvalid(newi,newj,n,m)) continue;
            if(graph[newi][newj]!='1' || visited[newi][newj]==true) continue;
            visited[newi][newj]=true;
            pending.push({newi,newj});
            
        }

    }
}
int numIsland(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                c++;
                BFS(i, j, n, m, grid, visited);
            }
        }
    }
    return c;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '0'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << numIsland(grid) << endl;
    }
    return 0;
}