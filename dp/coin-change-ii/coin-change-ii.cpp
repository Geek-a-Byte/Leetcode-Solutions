class Solution {
public:
    int f(int index, int sum, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(index==0)
        {
            if(sum%coins[index]==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[index][sum]!=-1)
        {
            return dp[index][sum];
        }
        int notPick=f(index-1, sum, coins, dp);
        int pick=0;
        if(coins[index]<=sum)
        {
            pick=f(index, sum-coins[index], coins, dp);
        }
        return dp[index][sum]=notPick+pick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return f(n-1, amount, coins, dp);
    }
};