class Solution {
public:
   vector<vector<int>> dp{22, vector<int>(22, -1)};

    int Solve(int i, int j, vector<int>& nums){
        if(i > j) return 0;
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int take_i = nums[i] - Solve(i+1,j,nums);
        int take_j = nums[j] - Solve(i,j-1,nums);
        return dp[i][j] = max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int p1_score = Solve(0,n-1,nums);
        return p1_score >= 0 ? true : false;
    }
};