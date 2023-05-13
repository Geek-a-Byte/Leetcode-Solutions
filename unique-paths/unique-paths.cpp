class Solution {
public:
    int uniquePaths(int s, int e) {
        vector<vector<int>>dp(s, vector<int>(e, -1));
        dp[0][0]=1;
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<e;j++)
            {
                if(i==0 and j==0)
                {
                    dp[0][0]=1;
                }
                else
                {
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[s-1][e-1];
    }
};