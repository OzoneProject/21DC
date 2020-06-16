
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                m=max(m,maxGold(grid,i,j));
            }
        }
        return m;
    }
    int maxGold(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || grid[i][j]==0){
            return 0;
        }
        int temp=grid[i][j];
        grid[i][j]=0;
        int sum=temp+max(max(maxGold(grid,i+1,j),maxGold(grid,i-1,j)),max(maxGold(grid,i,j+1),maxGold(grid,i,j-1)));
        grid[i][j]=temp;
        return sum;
    }