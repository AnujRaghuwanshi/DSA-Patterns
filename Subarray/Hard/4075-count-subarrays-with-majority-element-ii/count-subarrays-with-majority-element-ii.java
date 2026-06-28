class Solution {
    public long countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        Map<Integer,Integer> mp = new HashMap<>();
        int cum_sum = 0;
        mp.put(cum_sum,1);
        long result = 0;

        long valid_left_point = 0;

        for(int val : nums){
            if(val == target){
                valid_left_point +=  mp.getOrDefault(cum_sum, 0);
                cum_sum += 1;
            }else{
                cum_sum -= 1;
                valid_left_point -=  mp.getOrDefault(cum_sum, 0);
            }
            result += valid_left_point;
            mp.put(cum_sum,mp.getOrDefault(cum_sum,0)+1);
        }
        return result;
    }
}