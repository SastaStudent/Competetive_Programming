#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> BFS(int **arr, bool *visited, int start, int end, int vertex)
{
    // base case
    if (start == end){
        return {end};
    }
    vector<int> parent(vertex);
    queue<int> pending_Vertex;
    pending_Vertex.push(start);
    while (!pending_Vertex.empty() && !visited[end])
    {
        int sv = pending_Vertex.front();
        pending_Vertex.pop();

        visited[sv] = true;
        for (int i = 0; i < vertex; i++)
        {
            if (arr[sv][i] == 1 && !visited[i])
            {
                pending_Vertex.push(i);
                visited[i] = true;
                parent[i] = sv; // kisko kon put kiya queue me
                if (visited[end] == true){
                    break;
                }
            }
        }
    }
    vector<int> path;
    if (visited[end])//if path found
    {
        int temp = end;
        path.push_back(end);
        temp = parent[end];
        while (temp != start)
        {
            path.push_back(temp);
            temp = parent[temp];
        }
        path.push_back(start);
        return path;
    }
    return {};//return null if path not found
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // cout<<"Enter number of Vertex\n";
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
        // track vertex is visited or not
        bool *visited = new bool[v];
        for (int i = 0; i < v; i++){
            visited[i] = false;
        }

        int start, end;
        cin >> start >> end;
        vector<int> path = BFS(arr, visited, start, end, v);
        // deleting dynamic array
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        delete[] visited;
        for (int i = 0; i < v; i++){
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0;
}