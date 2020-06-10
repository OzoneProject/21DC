class Solution {
   public boolean canPartition(int[] nums) {
	int total = 0;
	for(int i : nums) total+=i; 
	if(total%2 != 0) return false; 
	int max = total/2; 
	int[][] results = new int[nums.length][max];
	return isPartitionable(max,0,0,nums,results);
}

public boolean isPartitionable(int max,int curr, int index, int[] nums, int[][] results) {
	if(curr>max || index>nums.length-1) return false;
	if(curr==max) return true; 
	if(results[index][curr]==1) return true;
	if(results[index][curr]==2) return false; 
	boolean res = isPartitionable(max, curr+nums[index], index+1, nums, results) || isPartitionable(max, curr, index+1, nums, results); 
	results[index][curr] = res ? 1 : 2; 
	return res;
}
}