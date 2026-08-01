class Solution {
    int[][] dp = new int[22][22];
    int Solve(int i, int j, int[] nums){
        if(i > j) return 0;
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];

        int take_i = nums[i] + Math.min(Solve(i+2,j,nums),Solve(i+1,j-1,nums));
        int take_j = nums[j] + Math.min(Solve(i,j-2,nums),Solve(i+1,j-1,nums));

        return dp[i][j] = Math.max(take_i,take_j);
    }
    public boolean predictTheWinner(int[] nums) {
        for(int[] row : dp){
            Arrays.fill(row,-1);
        }
        int n = nums.length;
        int total = 0;
        for(int val : nums){
            total += val;
        }
        int p1_score = Solve(0,n-1,nums);
        int p2_score = total - p1_score;
        if(p2_score > p1_score) return false;
        return true;

    }
}