class Solution {
public:
    bool fn(int i, int t, vector<int>& arr, vector<vector<int>>& dp)
    {
        if(t==0)
        {
            return true;
        }
        if(i==0)
        {
            return (arr[0]==t);
        }
        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }
        bool ntake=fn(i-1, t, arr, dp);
        bool take=false;
        if(t>=arr[i]) take=fn(i-1, t-arr[i], arr, dp);
        return dp[i][t]=((take) or (ntake));
    }
    bool canPartition(vector<int>& nums) {
         int sum=0;
         for(auto i:nums)
         {
             sum+=i;
         }
         if(sum%2==1)
         {
             return false;
         }
         int k=sum/2;
         int n=nums.size();
         vector<vector<int>>dp(n, vector<int>(k+1,-1));
         return fn(n-1, k, nums, dp);
    }
};