//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool visited[505]={false};
    void dfs(int parent, int n, vector<vector<int>>graph)
    {
        visited[parent]=1;
        for(int j=0;j<n;j++)
        {
            if(graph[parent][j]==1 and !visited[j])
            {
                visited[j]=1;
                dfs(j, n, graph);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int nodes) {
        // code here
        int cnt=0;
        for(int i=0;i<nodes;i++){
            if(!visited[i]){
                dfs(i, nodes, adj);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends