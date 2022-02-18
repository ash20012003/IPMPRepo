
class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int V, vector<int> adj[], vector<bool> &visited, stack<int> &st, int i){
	    visited[i] = true;
	    for(auto &e : adj[i]){
	        if(visited[e] == false){
	            dfs(V, adj, visited, st, e);
	        }
	    }
	    st.push(i);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    stack<int> s;
	    vector<bool> visited(V,false);
	    for(int i = 0; i< V;i++){
	        if(!visited[i]){
	            dfs(V,adj,visited,s,i);
	        }
	    }
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};
