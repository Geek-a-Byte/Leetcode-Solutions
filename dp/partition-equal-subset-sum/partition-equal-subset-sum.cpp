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
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return false;
        int sum=0;
        for(auto i:arr)
        {
            sum+=i;
        }
        if(sum%2==1)
        {
            return false;
        }
        int k=sum/2;
        vector<vector<bool>>dp(n, vector<bool>(k+1,0));
        for(int i=0;i<n-1;i++)
        {
            dp[i][0]=true;
        }
        if(arr[0]<k) dp[0][arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int t=1;t<=k;t++)
            {
                bool ntake=dp[i-1][t];
                bool take=false;
                if(t>=arr[i]) take=dp[i-1][t-arr[i]];
                dp[i][t]=((take) or (ntake));
            }
        }
        return dp[n-1][k];
    }
};