class Solution {

    private boolean isValid(int[] nums, int k, int allowedSum){
        int k_val = 1, maxSum = 0;
        for(int val : nums){
            if(val > allowedSum) return false;
            if(maxSum + val <= allowedSum){   //add in first subarray until it exceeds allowedSum
                maxSum += val;
            }else{
                //start new subarray and increment k_val
                k_val++;
                maxSum = val;
            }
        }
        if(k_val <= k) return true;     //if k_val <= k return true
        else return false;              //if k_val > k return false
    }
    public int splitArray(int[] nums, int k) {
        //task is to fild minimum possible largest sum
        int sum = 0;
        for(int val : nums){     //O(n)
            sum += val;
        }

        int st = 0;         //min possible = 0
        int end = sum;      //max possible = sum of array

        //answer lies between 0 to sum
        int ans = -1;

        //T.C. O(nlog(sum))
        while(st <= end){      //O(log(sum))
            int mid = st + (end-st)/2;
            
            if(isValid(nums,k,mid)){    //O(n)
            //if mid is valid search in left because we need to find minimum largest sum
                ans = mid;
                end = mid-1;
            }else{
            //if mid is invalid search in right because all elemnts in left will be invalid
                st = mid+1;
            }
        }
        return ans;
    }
}