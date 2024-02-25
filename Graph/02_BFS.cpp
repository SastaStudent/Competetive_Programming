#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void BFS(int **arr,bool *visited,int start,int vertex)
{
    queue<int>pending_Vertex;
    pending_Vertex.push(start);
    while(!pending_Vertex.empty())
    {
        int sv=pending_Vertex.front();
        pending_Vertex.pop();
        cout<<sv<<" ";
        visited[sv]=true;
        for(int i=0;i<vertex;i++)
        {
            if(arr[sv][i]==1 && !visited[i])
            {
                pending_Vertex.push(i);
                visited[i]=true;
            }
        }
    }

     

}
int main()
{
    cout<<"Enter number of Vertex\n";
    int v;
    cin>>v;
    cout<<"Enter number of edges\n";
    int e;
    cin>>e;
    //Adjacency Matrix
    int **arr = new int*[v];
    for(int i=0;i<v;i++)
    {
        arr[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            arr[i][j]=0;
        }
    }
    cout<<"Enter edges\n";
    for(int i=0;i<e;i++)
    {
        int first,second;
        cin>>first>>second;
        arr[first][second]=1;
        arr[second][first]=1;

    }
    //track vertex is visited or not
    bool *visited = new bool[v];
    for(int i=0;i<v;i++) visited[i]=false;
    BFS(arr,visited,0,v);
    //deleting dynamic array
    delete [] visited;
    for(int i=0;i<v;i++) delete [] arr[i];
    delete [] arr;
    return 0;
}