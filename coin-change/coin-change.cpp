class Solution {
public:
    int f(int index, int sum, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(index==0)
        {
            if(sum%coins[index]==0)
            {
                return sum/coins[index];
            }
            return 1e9;
        }
        if(dp[index][sum]!=-1)
        {
            return dp[index][sum];
        }
        int notPick=f(index-1, sum, coins, dp);
        int pick=1e9;
        if(coins[index]<=sum)
        {
            pick=1+f(index, sum-coins[index], coins, dp);
        }
        return dp[index][sum]=min(notPick, pick);
    }
    int coinChange(vector<int>& num, int x) {
        int n=num.size();
        vector<vector<int>>dp(n, vector<int>(x+1, -1));
        if(f(n-1, x, num, dp)>=1e9) return -1;
        return f(n-1, x, num, dp);
    }
};