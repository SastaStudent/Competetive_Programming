#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
bool Yes=false;
void back(int n, string &word, vector<vector<char>> &board, vector<vector<int>> &visited, int x, int y, int row, int col, int idx) {
    if (!valid(x, y, row, col) || visited[x][y] == 1 || board[x][y] != word[idx])
        return;
    
    visited[x][y] = 1;
    
    if (idx == n - 1) {
        Yes = true;
        visited[x][y] = 0; // Reset after finding the word
        return;
    }

    // Explore all four directions
    back(n, word, board, visited, x - 1, y, row, col, idx + 1);
    back(n, word, board, visited, x + 1, y, row, col, idx + 1);
    back(n, word, board, visited, x, y - 1, row, col, idx + 1);
    back(n, word, board, visited, x, y + 1, row, col, idx + 1);

    visited[x][y] = 0; // Reset after exploring all directions
}

bool present(vector<vector<char>> &board, string &word, int n, int m) {
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0]) {
                vector<vector<int>> visited(n, vector<int>(m, 0));
                back(word.size(), word, board, visited, i, j, n, m, 0);
                if (Yes) {
                    return true;
                }
            }
        }
    }
    return false;
}
/*These code are input part*/


class Runner
{
    string s;
    int n,m;
    vector<vector<char>> mat;

public:
    
    void takeInput()
    {
        cin >> s >> n >> m;
        mat = vector<vector<char>> (n,vector<char> (m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> mat[i][j];
    }
    void execute()
    {
        // make copy if vector
        auto cmat = mat;
        present(cmat,s,n,m);
    }
    void executeAndPrintOutput()
    {
        auto cmat = mat;
        if(present(cmat,s,n,m))cout << "true";
        else cout << "false";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}