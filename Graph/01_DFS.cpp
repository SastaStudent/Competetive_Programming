#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void DFS(int **arr,bool *visited,int start,int vertex)
{
    cout<<start<<" ";
    visited[start]=true;
    for(int i=0;i<vertex;i++)
    {
        if(arr[start][i]==1)
        {
            //if already visited then no need to call
            if(visited[i]==true) continue;
            DFS(arr,visited,i,vertex);
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
    DFS(arr,visited,0,v);
    //deleting dynamic array
    delete [] visited;
    for(int i=0;i<v;i++) delete [] arr[i];
    delete [] arr;
    return 0;
}