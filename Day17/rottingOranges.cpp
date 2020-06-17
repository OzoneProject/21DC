class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;  //No. of fresh oranges
        
        queue<pair<int, int>> q; // Queue, to store the nodes for BFS, i.e. rotten oranges.
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 2){ // If orange is rotten, we will use BFS on it. Therefore
                    q.push({i, j});  // pushed in queue.
                
                } else if(grid[i][j] == 1) // If orange is fresh, we increment 'fresh' by 1.
                    fresh++;
            }
        }
        
        if(fresh == 0) // If there are no fresh oranges, it won't take any time.
            return 0;
        
        int level = 2;  // Store the level of BFS till which oranges are rotten;
        
        fresh += q.size();  // As we will be subtractng fresh oranges as oranges get rotten
                            // in BFS, and as some rotten oranges are already present in 
                            // queue, we add them too.
        
        while(q.empty() == false){ // While all reachable oranges get rotten.
            
            auto k = q.front();
            int i = k.first, j = k.second;
            q.pop();
            
            level = max(level, grid[i][j]); // Max number of minutes passed + 2 is 'level'
            fresh--;                        // Reduce fresh oranges.
            
            if(i > 0 && grid[i-1][j] == 1){
                q.push({i-1, j});
                grid[i-1][j] = 1 + grid[i][j];      // If conditions matches, that is we don't
            }                                       // go over the boundary and we are going
            if(i < n-1 && grid[i+1][j] == 1){       // towards a fresh orange, we push that 
                q.push({i+1, j});                   // fresh orange in queue to continue BFS
                grid[i+1][j] = 1 + grid[i][j];      // and also change it's value to exceed
            }                                       // it's parent node, i.e. the orange it
            if(j > 0 && grid[i][j-1] == 1) {        // got rotten from.
                q.push({i, j-1});
                grid[i][j-1] = 1 + grid[i][j];
            }
            if(j < m-1 && grid[i][j+1] == 1){
                q.push({i, j+1});
                grid[i][j+1] = 1 + grid[i][j];
            }
        }
                                            // If all oranges get rotten, return mins = lvl - 2
        return fresh != 0 ? -1 : level - 2; // else return -1.
    }
};