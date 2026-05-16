class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int ans = INT_MAX;

        while(st <= end){
            if(nums[st] <= nums[end]){
                ans = min(ans,nums[st]);
                end--;
            }else{
                ans = min(ans,nums[st]);
                st++;
            }
        }
        return ans;
    }
};