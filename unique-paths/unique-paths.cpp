class Solution {
public:
    int f(int s, int e, vector<vector<int>>& dp)
    {
        if(s==0 and e==0)
        {
            return 1;
        }
        if(s<0 or e<0)
        {
            return 0;
        }
        if(dp[s][e]!=-1) return dp[s][e];
        int up=f(s-1, e, dp);
        int left=f(s, e-1, dp);
        return dp[s][e]=up+left;
    }
    int uniquePaths(int s, int e) {
        vector<vector<int>>dp(s, vector<int>(e, -1));
        return f(s-1, e-1, dp); 
    }
};