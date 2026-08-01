class Solution {
public:
    int Solve(int i, int j, vector<int>& nums){
        if(i > j) return 0;
        if(i == j) return nums[i];
        int take_i = nums[i] + min(Solve(i+2,j,nums),Solve(i+1,j-1,nums));
        int take_j = nums[j] + min(Solve(i,j-2,nums), Solve(i+1,j-1,nums));

        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int p1_score = Solve(0,n-1,nums);
        int p2_score = total - p1_score;
        return p1_score >= p2_score;
    }
};