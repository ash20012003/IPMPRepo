class Solution{
public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int V, vector<int> adj[], vector<int> &ans, vector<bool> &visited, int i){
        if(visited[i] == true){
            return;
        }
        visited[i] = true;
        ans.push_back(i);
        for(int j = 0; j < adj[i].size(); j++){
            dfs(V, adj, ans, visited, adj[i][j]);
        }
        return;
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> visited(V, false);
        dfs(V, adj, ans, visited, 0);
        return ans;
    }
};
