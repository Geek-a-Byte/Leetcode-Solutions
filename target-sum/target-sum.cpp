class Solution {
public:
    int f(int index, int sum, vector<int>& a, vector<vector<int>>& dp)
    {   
        if(index==0)
        {
            if(a[index]==0 and sum==0)
            {
                return 2; // i can pick it or not pick it coz it would not alter the sum = 0
            }
            if(a[index]!=0 and sum==0)
            {
                return 1; // not pick it as it will alter the sum
            }
            if(sum==a[0])
            {
                return 1; // pick it as it will alter the sum to 0 
            }
            else
            {
                return 0;
            }
        }
        
        
        if(dp[index][sum]!=-1)
        {
            return dp[index][sum];
        }
        int notPick=f(index-1, sum, a, dp);
        int pick=0;
        if(a[index]<=sum)
        {
            pick=f(index-1, sum-a[index], a, dp);
        }

        return dp[index][sum]=(notPick+pick);
        
    }

    int findWays(vector<int> &num, int tar)
    {
        // Write your code here.
        int n=num.size();
        vector<vector<int>>dp(n, vector<int>(tar+1, -1));
        return f(n-1, tar, num, dp);
    }
    int findTargetSumWays(vector<int>& arr, int d) {
        int tot_sum=0;
        for(auto i:arr)
        {
            tot_sum+=i;
        }
        if(tot_sum-d<0)
        {
        return 0;
        }
        if((tot_sum-d)%2==1)
        {
        return 0;
        }
        int tar=(tot_sum-d)/2;
        return findWays(arr, tar);
    }
};