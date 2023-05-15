//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int index, int capacity, int weights[], int profits[], vector<vector<int>>& dp)
    {
        if(index==0)
    	{
    		if(weights[index]<=capacity)
    		{
    			return profits[0];
    		}
    		return 0;
    	}
    	if(dp[index][capacity]!=-1) return dp[index][capacity];
    
    	int notPick=f(index-1, capacity, weights, profits, dp);
    	int pick=INT_MIN;
    	if(weights[index]<=capacity)
    	{
    		pick=profits[index]+f(index-1, capacity-weights[index], weights, profits, dp);
    	}
    	return dp[index][capacity]=max(pick, notPick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        return f(n-1, W, wt, val, dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends