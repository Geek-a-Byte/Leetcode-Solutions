//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    vector<pair<int,int>>moves={{-1,0},{+1,0},{0,-1},{0,+1}};
    bool visited[505][505];
    
    bool boundaryCheck(int i,int j, vector<vector<char>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if(i<0 or i>=rows or j<0 or j>=cols) return false;
        return true;
    }
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        visited[i][j] = 1;
        for (auto k : moves)
        {
            int nx=i+k.first;
            int ny=j+k.second;
            if (boundaryCheck(nx,ny,grid) and !visited[nx][ny])
            {
                dfs(nx, ny, grid);
            }
        }
    }
 
     // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // code here
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                char c= grid[i][j];
                if(c=='O')
                {
                    visited[i][j]=1;
                }
                if(c=='X')
                {
                    visited[i][j]=0;
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++){
                if (!visited[i][j])
                {
                    dfs(i,j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        return numIslands(grid);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends