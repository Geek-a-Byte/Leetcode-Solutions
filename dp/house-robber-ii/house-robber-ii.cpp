class Solution {
public:
    int fn(int n, vector<int>& nums, vector<int>& dp)
    {
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int p=nums[n]+fn(n-2, nums, dp);
        int np=0+fn(n-1, nums, dp);
        return dp[n]=max(p,np);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                temp1.push_back(nums[i]);
            }
            if(i!=n-1)
            {
                temp2.push_back(nums[i]);
            }
        }
        vector<int>dp(n-1,-1);
        vector<int>dp2(n-1,-1);
        int ans1=fn(n-2, temp1, dp);
        int ans2=fn(n-2, temp2, dp2);
			
        return max(ans1,ans2);
    }
};