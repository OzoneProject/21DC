class Solution {
private:
    
    void dfs(vector<int> g[], int x, vector<bool>& v){
        
        v[x] = true; // We are on node 'x', so we set 'visited' as true.
        
        for(int i = 0; i < g[x].size(); i++){ // Iterate through its neighbours.
            
            if(v[g[x][i]] == false)     // If neighbour is not visited, we apply dfs on it
                dfs(g, g[x][i], v);     // and visit it.
        }
    }

public:
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        
        if(conn.size() < n-1) return -1; // If edges < n-1 that is, even a tree cannot be
                                         // formed, it is impossible to connect the system.
        
        vector<int> g[n];   // Defining an adjacency list.
        
        for(int i = 0; i < conn.size(); i++){ // Iterating through connections
            
            g[conn[i][0]].push_back(conn[i][1]); // Creating adjacency list, that is, an
            g[conn[i][1]].push_back(conn[i][0]); // undirected graph.
        
        }
        
        vector<bool> visited(n, false); // Visited array to store if the node is already 
                                        // visited, initially set to false.
        
        int comp = 0; // Stores number of distinct connected components.
        
        for(int i = 0; i < n; i++){ // Traversing graph, i.e. adjacency list.
            
            if(visited[i] == false){     // If not visited yet, we apply dfs on that node to 
                dfs(g, i, visited);  // traverse the connected component. The number of times
                comp++;              // we call dfs is the number of distinct connected 
            }                        // components we have in our graph.
        }
        
        return comp-1; // n distinct connected components can be joined using n-1 cables.
    }
};