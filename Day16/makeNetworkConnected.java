class Solution {
    private void dfs(List<Integer> g[], int x, boolean v[]){
        
        v[x] = true;
        
        for(int i = 0; i < g[x].size(); i++){
            if(v[g[x].get(i)] == false)
                dfs(g, g[x].get(i), v);
        }
    }
    
    public int makeConnected(int n, int[][] conn) {
        if(conn.length < n-1)
            return -1;
        
        List<Integer>[] g = new ArrayList[n];
        for(int i = 0; i < n; i++)
            g[i] = new ArrayList<Integer>();
        
        for(int i = 0; i < conn.length; i++){
            
            g[conn[i][0]].add(conn[i][1]);
            g[conn[i][1]].add(conn[i][0]);
        
        }
        
        boolean[] visited = new boolean[n];
        
        int comp = 0;
        
        for(int i = 0; i < n; i++){
            
            if(visited[i] == false){
                dfs(g, i, visited);
                comp++;
            }
        }
        
        return comp-1;
    }
}