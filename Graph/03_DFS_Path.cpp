#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
bool DFS(int **arr, bool *visited, int start, int end, int vertex, vector<int> &path)
{
    // cout<<start<<" ";
    if (start == end)
    {
        path.push_back(start);
        return true;
    }
    path.push_back(start);
    visited[start] = true;
    for (int i = 0; i < vertex; i++)
    {
        if (arr[start][i] == 1)
        {
            // if already visited then no need to call
            if (visited[i] == true)
                continue;
            bool found = DFS(arr, visited, i, end, vertex, path);
            if (found)
                return true;
            path.pop_back();
            // cout<<i<<" ";
        }
    }
    return false;
}
int main()
{
    // cout<<"Enter number of Vertex\n";
    int t;
    cin >> t;
    while (t--)
    {
        int v;
        cin >> v;
        // cout<<"Enter number of edges\n";
        int e;
        cin >> e;
        // Adjacency Matrix
        int **arr = new int *[v];
        for (int i = 0; i < v; i++)
        {
            arr[i] = new int[v];
            for (int j = 0; j < v; j++)
            {
                arr[i][j] = 0;
            }
        }
        // cout<<"Enter edges\n";
        for (int i = 0; i < e; i++)
        {
            int first, second;
            cin >> first >> second;
            arr[first][second] = 1;
            arr[second][first] = 1;
        }
        int start, end;
        cin >> start >> end;
        // track vertex is visited or not
        bool *visited = new bool[v];
        for (int i = 0; i < v; i++){
            visited[i] = false;
        }

        vector<int> path;
        bool yes = DFS(arr, visited, start, end, v, path);
        if (yes){
            for (int i = path.size() - 1; i >= 0; i--){
                cout << path[i] << " ";
            }
        }
        // if (ans)
        //   cout << "true" << endl;
        // else
        cout << endl;
        // deleting dynamic array
        delete[] visited;
        for (int i = 0; i < v; i++){
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0;
}