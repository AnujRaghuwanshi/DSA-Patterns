class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];

        //first element is single element
        if(nums[0] != nums[1]) return nums[0];
        
        //last element is single element
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int st = 0;
        int end = n-1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            //single element will not be equal to both adjacent elements
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

            //check whether left and right contains even/odd no.of elements
            //if mid is even left and right contains even count of elements
            //if mid is odd left and right contains odd count of elements

            else if(mid % 2 == 0){
                //if mid is even check whether mid is equal to left or right element

                //if mid is equal to mid-1, single element will be on left side
                if(nums[mid-1] == nums[mid]) end = mid-1;

                //if mid is equal to mid+1, single element will be on right side
                else st = mid+1;
            }
            else{
                //if mid is odd check whether mid is equal to left or right element

                //if mid is equal to mid-1, single element will be on right side
                if(nums[mid-1] == nums[mid]) st = mid+1;

                //if mid is equal to mid+1, single element will be on left side
                else end = mid-1;
            }
        }
        return -1;
    }
}