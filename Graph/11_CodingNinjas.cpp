#include <iostream>
#include <vector>
using namespace std;

const int n = 1e3;
char arr[n][n];
string word = "CODINGNINJA";
bool visited[n][n]; // Define visited array here

// Define the directions: Up, Down, Left, Right, and diagonals
const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool DFS(int x, int y, int pos, int n, int m) {
    // Base case: If we reach the end of the word, return true
    if (pos == word.length()) return true;

    // Mark the current cell as visited
    visited[x][y] = true;

    // Check all neighbors
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (valid(nx, ny, n, m) && !visited[nx][ny] && arr[nx][ny] == word[pos]) {
            if (DFS(nx, ny, pos + 1, n, m)) // Continue DFS if a matching character is found
                return true;
        }
    }

    // Unmark the cell before backtracking
    visited[x][y] = false;

    return false; // If the entire word cannot be formed starting from this cell
}

bool findWord(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 'C' && !visited[i][j]) {
                if (DFS(i, j, 1, n, m)) // Start DFS from cell containing 'C'
                    return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    // Initialize visited array to false
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
    
    // Input the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    // Call the function to find the word
    if (findWord(n, m))
        cout << "1" << endl;
    else
        cout << "0" << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc-- > 0) {
        solve();
    }
    return 0;
}
