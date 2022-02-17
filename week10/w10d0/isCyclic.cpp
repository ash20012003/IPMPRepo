class Solution{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int flag = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int c1 = 0;
            int c2 = 0;
            for(auto it : adj[node]){
                c1++;
                if(!vis[it]){
                    c2++;
                    q.push(it);
                    vis[it] = 1;
                }
            }
            if(c1==c2) continue;
            else {flag = 1;
                break;
            }
        }
        if(flag==1) return true;
        else return false;
    }
};

/*  OR  */
  bool dfs(int V, vector<int> adj[], vector<bool> &visited, vector<bool> &recstack, int i){
        visited[i] = true;
        recstack[i] = true;
        for(auto &e : adj[i]){
            if(visited[e] == false && dfs(V, adj, visited, recstack, e)){
                return true;
            }
            else if(recstack[e] == true){
                return true;
            }
        }
        recstack[i] = false;
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recstack(V, false);
        bool isCyclic = false;
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                isCyclic = dfs(V, adj, visited, recstack, i);
            }
            if(isCyclic){
                return true;
            }
        }
        return false;
    }
