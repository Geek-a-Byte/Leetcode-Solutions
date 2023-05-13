class Solution {
public:
    int f(int s, int e, vector<vector<int>>& dp, vector<vector<int>>& grid)
    {
        if(s>=0 and e>=0 and grid[s][e]==1)
        {
            return 0;
        }
        if(s==0 and e==0)
        {
            return 1;
        }
        if(s<0 or e<0)
        {
            return 0;
        }
        if(dp[s][e]!=-1) return dp[s][e];
        int up=f(s-1, e, dp, grid);
        int left=f(s, e-1, dp, grid);
        return dp[s][e]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return f(n-1, m-1, dp, obstacleGrid); 
    }
};