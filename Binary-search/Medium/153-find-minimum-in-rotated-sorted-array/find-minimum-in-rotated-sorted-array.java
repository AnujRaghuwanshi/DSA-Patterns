class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n == 1 || (nums[0] < nums[n-1])) return nums[0];

        int st = 0;
        int end = n-1;
        int ans = Integer.MAX_VALUE;

        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[st] <= nums[mid]){
                ans = Math.min(ans,nums[st]);
                st = mid+1;
            }else{
                ans = Math.min(ans,nums[mid]);
                end = mid-1;
            }
        }
        return ans;
    }
}