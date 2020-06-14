class Solution {
    public int getMaximumGold(int[][] grid) {
        int max=Integer.MIN_VALUE;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                max=Math.max(max,maxGold(grid,i,j));
            }
        }
        return max;
    }
    public int maxGold(int[][] grid,int i,int j){
        if(i<0 || i>grid.length-1 || j<0 || j>grid[0].length-1 || grid[i][j]==0){
            return 0;
        }
        int temp=grid[i][j];
        grid[i][j]=0;
        int sum=temp+Math.max(Math.max(maxGold(grid,i+1,j),maxGold(grid,i-1,j)),Math.max(maxGold(grid,i,j+1),maxGold(grid,i,j-1)));
        grid[i][j]=temp;
        return sum;
    }
}
