class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || (nums[0] < nums[n-1])) return nums[0];

        int st = 0;
        int end = n-1;
        int ans = INT_MAX;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[st] <= nums[mid]){
                ans = min(ans,nums[st]);
                st = mid+1;
            }else{
                ans = min(ans,nums[mid]);
                end = mid-1;
            }
        }
        return ans;
    }
};

/*************************************************************************************/

class Solution {
public:
    int Solve(vector<int>& nums, int n){
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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || (nums[0] < nums[n-1])) return nums[0];
        int idx = Solve(nums,n);   //find index of maximum element
        return nums[idx+1 %  n];   //minimum element will be on idx of maximum element + 1
    }
};
