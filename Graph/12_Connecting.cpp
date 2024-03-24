#include <iostream>
#include <vector>
using namespace std;

void hasCycle(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, int parent_x, int parent_y, char needColor, bool &foundCycle, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != needColor) {
        return;
    }

    if (visited[x][y]) {
        foundCycle = true;
        return;
    }

    visited[x][y] = true;

    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (const auto &dir : directions) {
        int nextX = x + dir.first;
        int nextY = y + dir.second;

        if (nextX == parent_x && nextY == parent_y) {
            continue; // Avoid visiting the parent cell
        }

        hasCycle(board, visited, nextX, nextY, x, y, needColor, foundCycle, n, m);
    }
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    bool foundCycle = false;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                hasCycle(board, visited, i, j, -1, -1, board[i][j], foundCycle, n, m);
                if (foundCycle) {
                    return true; // If a cycle is found, return immediately
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "1" : "0") << endl;

    return 0;
}
