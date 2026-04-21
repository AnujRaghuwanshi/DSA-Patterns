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


/******************************************************************/
class Solution {
public:

    int findpivotIndex(vector<int> nums){
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]>nums[mid+1] && mid<r){
                  return mid+1;
            }else if(mid>l && nums[mid]<nums[mid-1]){
                return mid;
            }
            if(nums[mid]>=nums[l]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }

    int binarySearch(vector<int> nums, int low, int high, int target){
        int l = low, h = high-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
       return -1;
    }

    int search(vector<int>& nums, int target) {

        if(nums.size()==1 && nums[0]==target) return 0;

        int pivot = findpivotIndex(nums);
        int index = -1;

        if(pivot == -1){
            index = binarySearch(nums,0,nums.size(),target);
            return index;
        }

        if(nums[pivot]==target) return pivot;

        int before_pivotIndex = binarySearch(nums, 0 ,pivot,target);
       
        int after_pivotIndex = binarySearch(nums, pivot+1, nums.size(),target);
      
        if(before_pivotIndex == after_pivotIndex) return before_pivotIndex;
        return  (before_pivotIndex > after_pivotIndex) ?  before_pivotIndex :after_pivotIndex;
    }
};


/******************************************************************/
class Solution {
public:

    int findpivotIndex(vector<int> nums){
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]>nums[mid+1] && mid<r){
                  return mid+1;
            }else if(mid>l && nums[mid]<nums[mid-1]){
                return mid;
            }
            if(nums[mid]>=nums[l]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }

    int binarySearch(vector<int> nums, int low, int high, int target){
        int l = low, h = high-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
       return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 1 && nums[0] == target) return 0;

        int pivot = findpivotIndex(nums);           //log(n)
        if(pivot == -1){
            return binarySearch(nums,0,nums.size(),target);
        }

        if(nums[pivot] == target) return pivot;

        sort(nums.begin(),nums.end());      //log(n)

        int index = binarySearch(nums,0,n,target);    //log(n)

        return index == -1 ? index : (index + pivot) % n;         
    }
};
