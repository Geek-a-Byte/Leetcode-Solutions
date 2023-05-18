class Solution {
public:
    int f(int s, int e, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(s==0 and e==0)
        {
            return grid[0][0];
        }
        if(s<0 or e<0)
        {
            return 1e9;
        }
        if(dp[s][e]!=-1) return dp[s][e];
        int up = grid[s][e] + f(s-1, e, dp, grid);
        int left = grid[s][e] + f(s, e-1, dp, grid);
        return dp[s][e]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int s=grid.size();
        int e=grid[0].size();
        vector<vector<int>>dp(s, vector<int>(e, -1));
        dp[0][0]=1;
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<e;j++)
            {
                if(i==0 and j==0)
                {
                    dp[0][0]=grid[0][0];
                }
                else
                {
                    int up=1e9;
                    int left=1e9;
                    if(i>0) up=grid[i][j] + dp[i-1][j];
                    if(j>0) left=grid[i][j] + dp[i][j-1];
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[s-1][e-1];
    }
};