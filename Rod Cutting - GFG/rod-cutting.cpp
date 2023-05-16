//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int index, int N, int price[], vector<vector<int>>& dp)
    {
        if(index==0)
        {
            return N*price[0];
        }
        if(dp[index][N]!=-1)
        {
            return dp[index][N];
        }
        int notPick=f(index-1, N, price, dp);
        int pick=INT_MIN;
    	int rod_length=index+1;
        if(rod_length<=N)
        {
            pick=price[index]+f(index, N-rod_length, price, dp);
        }
        return dp[index][N]=max(notPick,pick);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
	    return f(n-1, n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends