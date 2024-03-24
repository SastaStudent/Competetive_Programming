#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
vector<int> Graph[N];

vector<int> Topo(int vertex) {
    vector<int> Indegree(vertex, 0);
    for (int i = 0; i < vertex; i++) {
        for (int child : Graph[i]) {
            Indegree[child]++;
        }
    }
    queue<int> pending;
    vector<int> st;
    for (int i = 0; i < vertex; i++) {
        if (Indegree[i] == 0)
            pending.push(i);
    }
    while (!pending.empty()) {
        int front = pending.front();
        pending.pop();
        st.push_back(front);
        for (int child : Graph[front]) {
            Indegree[child]--;
            if (Indegree[child] == 0)
                pending.push(child);
        }
    }
    return st;
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
            int first, second;
            cin >> first >> second;
            Graph[first].push_back(second);
        }
        vector<int> st = Topo(v);

        for (int ele : st)
            cout << ele << " ";
        cout << endl;
        reset();
    }
    return 0;
}
