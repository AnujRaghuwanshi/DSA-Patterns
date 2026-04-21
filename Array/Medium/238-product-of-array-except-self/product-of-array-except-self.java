class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Arrays.fill(ans,1);

        for(int i = 1; i<n ; i++){              //calculate prefix product
            ans[i] = ans[i-1] * nums[i-1];
        }

        int suffix = 1;

        for(int i=n-2; i>=0; i--){              //calculate suffix product
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        return ans;
    }
}