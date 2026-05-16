class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int st = 0;
        int end = n-1;
        int ans = Integer.MAX_VALUE;

        while(st <= end){
            if(nums[st] <= nums[end]){
                ans = Math.min(ans,nums[st]);
                end--;
            }else{
                ans = Math.min(ans,nums[st]);
                st++;
            }
        }
        return ans;
    }
}