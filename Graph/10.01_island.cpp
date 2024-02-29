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

        // up
        if (i - 1 >= 0 && graph[i - 1][j] == '1' && !visited[i - 1][j])
        {
            pending.push({i - 1, j});
            visited[i - 1][j] = true;
        }
        // down
        if (i + 1 < n && graph[i + 1][j] == '1' && !visited[i + 1][j])
        {
            pending.push({i + 1, j});
            visited[i + 1][j] = true;
        }
        // left
        if (j - 1 >= 0 && graph[i][j - 1] == '1' && !visited[i][j - 1])
        {
            pending.push({i, j - 1});
            visited[i][j - 1] = true;
        }
        // right
        if (j + 1 < m && graph[i][j + 1] == '1' && !visited[i][j + 1])
        {
            pending.push({i, j + 1});
            visited[i][j + 1] = true;
        }
        // top-right
        if (i - 1 >= 0 && j + 1 < m && graph[i - 1][j + 1] == '1' && !visited[i - 1][j + 1])
        {
            pending.push({i - 1, j + 1});
            visited[i - 1][j + 1] = true;
        }
        // bottom-left
        if (i + 1 < n && j - 1 >= 0 && graph[i + 1][j - 1] == '1' && !visited[i + 1][j - 1])
        {
            pending.push({i + 1, j - 1});
            visited[i + 1][j - 1] = true;
        }
        // top-left
        if (i - 1 >= 0 && j - 1 >= 0 && graph[i - 1][j - 1] == '1' && !visited[i - 1][j - 1])
        {
            pending.push({i - 1, j - 1});
            visited[i - 1][j - 1] = true;
        }
        // bottom-right
        if (i + 1 < n && j + 1 < m && graph[i + 1][j + 1] == '1' && !visited[i + 1][j + 1])
        {
            pending.push({i + 1, j + 1});
            visited[i + 1][j + 1] = true;
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