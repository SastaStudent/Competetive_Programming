/*Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void DFS(int si, int sj, int n, int m, vector<vector<char>> &graph, vector<vector<bool>> &visited)
{
    // base case
    //valid co-ordinate or not...
    if (si < 0 || sj < 0 || si >= n || sj >= m){
        return;
    }
    // valid call or not we call DFS for '1'
    if (graph[si][sj] == '0'){
        return;
    }
    //if already visited then return (don't call)
    if (visited[si][sj] == true){
        return;
    }
    visited[si][sj] = true;
    DFS(si, sj + 1, n, m, graph, visited);
    DFS(si, sj - 1, n, m, graph, visited);
    DFS(si - 1, sj + 1, n, m, graph, visited);
    DFS(si + 1, sj - 1, n, m, graph, visited);
    DFS(si - 1, sj, n, m, graph, visited);
    DFS(si + 1, sj, n, m, graph, visited);
    DFS(si - 1, sj - 1, n, m, graph, visited);
    DFS(si + 1, sj + 1, n, m, graph, visited);
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
                DFS(i, j, n, m, grid, visited);
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
        cout << numIsland(grid)<<endl;
    }
    return 0;
}