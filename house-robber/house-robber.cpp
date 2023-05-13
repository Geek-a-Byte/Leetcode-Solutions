class Solution {
public:
    int fn(int n, vector<int>& nums, vector<int>& dp)
    {
        if(dp[n]!=-1) return dp[n];
        if(n==0) return nums[n];
        if(n<0) return 0;
        int p=nums[n]+fn(n-2, nums, dp);
        int np=0+fn(n-1, nums, dp);
        return dp[n]=max(p,np);
    }
    int rob(vector<int>& nums) {
        // Write your code here.
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int p=nums[i];
            if(i>1) p+=dp[i-2];
            int np=0+dp[i-1];
            dp[i]=max(p,np);
        }
        return dp[n-1];
    }
};