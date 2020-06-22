class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        c=0
        for i in range(len(grid)) :
            for j in range(len(grid[i])) :
                if grid[i][j]==1 :
                    if i==0 :
                        c+=1
                    else :
                        if grid[i-1][j]!=1 :
                            c+=1
                    if i==len(grid)-1 :
                        c+=1
                    else :
                        if grid[i+1][j]!=1 :
                            c+=1
                    if j==0 :
                        c+=1
                    else :
                        if grid[i][j-1]!=1 :
                            c+=1
                    if j==len(grid[i])-1 :
                        c+=1
                    else :
                        if grid[i][j+1]!=1 :
                            c+=1
        return c
            
