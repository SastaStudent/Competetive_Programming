#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> Edge(m);
    vector<int> Edge2(m);
    
    for (int i = 0; i < m; i++) {
        cin >> Edge[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>Edge2[i];
    }

    vector<vector<int>> Graph(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i < m; i++) {
        Graph[Edge[i]][Edge2[i]] = 1;
        Graph[Edge2[i]][Edge[i]] = 1;
    }
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && Graph[i][j] == 1) {
                for (int k = 1; k <= n; k++) {
                    if (Graph[j][k] == 1 && j!=k && k!=i) {
                        if(Graph[i][k]==1)ans++;
                    }
                }
            }
        }
    }
    
    cout << ans / 6;
    
    return 0;
}
