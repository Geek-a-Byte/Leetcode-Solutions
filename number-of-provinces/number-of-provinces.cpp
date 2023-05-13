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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        return numProvinces(isConnected, n);
    }
};