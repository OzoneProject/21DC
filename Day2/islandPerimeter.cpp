class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int perimeter = 0;
        int m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if((i - 1 < 0) || (i - 1 >= 0 && grid[i-1][j] == 0))
                        perimeter++;
                    if((i + 1 == m) || (i + 1 < m && grid[i+1][j] == 0))
                        perimeter++;
                    if((j - 1 < 0) || (j - 1 >= 0 && grid[i][j-1] == 0))
                        perimeter++;
                    if((j + 1 == n) || (j + 1 < n && grid[i][j+1] == 0))
                        perimeter++;
                }
            }
        }
        
        return perimeter;
    }
};