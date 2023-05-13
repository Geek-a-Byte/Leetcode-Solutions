class Solution {
public:
    int fn(int i, int j, int n, vector<vector<int>>& tri, vector<vector<int>>& dp)
    {
        if(i==n-1)
        {
            return tri[n-1][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int d=tri[i][j]+fn(i+1, j, n, tri, dp);
        int dg=tri[i][j]+fn(i+1, j+1, n, tri, dp);
        return dp[i][j]=min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return fn(0, 0, n, triangle, dp);
    }
};