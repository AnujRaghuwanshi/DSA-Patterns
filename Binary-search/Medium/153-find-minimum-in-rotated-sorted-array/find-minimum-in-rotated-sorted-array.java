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

/*************************************************************************************/

class Solution {

    private int Solve(int[] nums, int n){
        int st = 0;
        int end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[mid] > nums[mid+1]) return mid;

            else if(nums[mid] < nums[mid-1]) return mid-1;

            else if(nums[st] < nums[mid]) st = mid+1;

            else end = mid-1;
        }
        return -1;
    }
    public int findMin(int[] nums) {
        int n = nums.length;
        if(n == 1 || (nums[0] < nums[n-1])) return nums[0];

        int indx = Solve(nums,n);
        return nums[indx+1 % n];
    }
}
