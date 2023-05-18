class Solution {
public:
    int fn(int i, int j, int n, vector<vector<int>>& tri, vector<vector<int>>& dp)
    {
        if(i==n-1)
        {
            return tri[i][j];
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
        for(int i=0;i<n;i++)
        {
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d=triangle[i][j]+dp[i+1][j];
                int dg=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d, dg);
            }
        }
        return dp[0][0];
    }

};