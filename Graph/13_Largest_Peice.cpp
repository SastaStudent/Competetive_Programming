#include <iostream>
#include <vector>
using namespace std;
bool valid(int x,int y,int n)
{
    return x>=0&&y>=0 && x<n && y<n;
}
const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void DFS(int &ans,vector<vector<char>>&board,vector<vector<bool>>&visited,int x,int y,int n)
{
    if(!valid(x,y,n)|| board[x][y]=='0') return;
    if(visited[x][y]==true) return;
    visited[x][y]=true;
    // static int ans=1;
    ans++;
    for(auto ele:directions)
    {
        int newx=x+ele.first;
        int newy=y+ele.second;
        DFS(ans,board,visited,newx,newy,n);

    }
    // return ans;

}
void solve(vector<vector<char>> &board,int n)
{
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    int count=0;
     for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                
                if(!visited[i][j]&&board[i][j]=='1')
                {
                    int ans=0;
                    DFS(ans,board,visited,i,j,n);
                    count=max(count,ans);
                }
                 
            }
        }
        cout<<count<<endl;

}
int main()
{
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        int n, m;
        cin >> n;
        m = n;

        vector<vector<char>> board(n, vector<char>(n));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> board[i][j];
            }
        }
        solve(board,n);
    }

    return 0;
}
