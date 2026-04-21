class Solution {
public:
    int binarySearch(vector<int>& nums, int n, int target){
        int st = 0;
        int end = n-1;
        while(st <= end){
            int mid = st + (end - st) / 2;

            if(nums[mid] == target) return mid;

            if(nums[st] <= nums[mid]){     //left sorted
               if(target >= nums[st] && target <= nums[mid]) end = mid - 1;
               else st = mid + 1;
            }else{                          //right sorted
                if(target >= nums[mid] && target <= nums[end]) st = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1 && target == nums[0]) return 0;
        if(n == 1 && target != nums[0]) return -1;

        return binarySearch(nums,n,target);       
    }
};