class Solution {
    int Solve(int i, int j, int[] nums){
        if(i > j) return 0;
        if(i == j) return nums[i];
        int take_i = nums[i] - Solve(i+1,j,nums);
        int take_j = nums[j] - Solve(i,j-1,nums);
        return Math.max(take_i,take_j);
    }
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        int p1_score = Solve(0,n-1,nums);
        if(p1_score >= 0) return true;
        return false;
    }
}