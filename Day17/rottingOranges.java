class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int fresh = 0;
        
        Queue<int[]> q = new LinkedList<>();
        
        for(int i = 0; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 2) {
                    q.add(new int[]{i , j});
                
                } else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0) 
            return 0;
        
        int level = 2;
        fresh += q.size();
        
        while(q.isEmpty() == false){
            
            int [] k = q.remove();
            int i = k[0], j = k[1];
            
            level = Math.max(level, grid[i][j]);
            fresh--;
            
            if(i > 0 && grid[i-1][j] == 1){
                q.add(new int[]{i-1, j});
                grid[i-1][j] = 1 + grid[i][j];      
            }                                       
            if(i < n-1 && grid[i+1][j] == 1){       
                q.add(new int[]{i+1, j});           
                grid[i+1][j] = 1 + grid[i][j];      
            }                                       
            if(j > 0 && grid[i][j-1] == 1) {        
                q.add(new int[]{i, j-1});
                grid[i][j-1] = 1 + grid[i][j];
            }
            if(j < m-1 && grid[i][j+1] == 1){
                q.add(new int[]{i, j+1});
                grid[i][j+1] = 1 + grid[i][j];
            }
        }
        
        return fresh != 0 ? -1 : level - 2;
    }
}