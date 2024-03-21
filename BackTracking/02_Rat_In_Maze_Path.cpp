#include <bits/stdc++.h> 
using namespace std;

bool isValid(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

void helper(vector<vector<int>>& arr, int x, int y, int n, vector<string>& ans) {
    static string str;
    if (!isValid(x, y, n) || arr[x][y] == 0) return;
    if (x == n - 1 && y == n - 1) {
        ans.push_back(str);
        return;
    }
    arr[x][y] = 0; // Mark as visited
    str.push_back('D');
    helper(arr, x + 1, y, n, ans);
    str.pop_back();
    str.push_back('L');
    helper(arr, x, y - 1, n, ans);
    str.pop_back();
    str.push_back('R');
    helper(arr, x, y + 1, n, ans);
    str.pop_back();
    str.push_back('U');
    helper(arr, x - 1, y, n, ans);
    str.pop_back();
    // Backtrack
    arr[x][y] = 1; // Mark as unvisited
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<string> ans;
    helper(arr, 0, 0, n, ans);
    return ans;
}

/*Driver code*/
class Runner {
    vector<vector<int>> arr;

public:
    void takeInput() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            arr.push_back(vector<int>());
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                arr[i].push_back(x);
            }
        }
    }

    void executeAndPrintOutput() {
        vector<string> ans = searchMaze(arr, arr.size());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
};

int main() {
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
