class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int cum_sum = 0;
        mp[cum_sum] = 1;
        long long result = 0;

        long long valid_left_point = 0;

        for(auto const& val : nums){
            if(val == target){
                valid_left_point += mp[cum_sum];
                cum_sum += 1;
            }else{
                cum_sum -= 1;
                valid_left_point -= mp[cum_sum];
            }
            result += valid_left_point;
            mp[cum_sum] += 1;
        }
        return result;

    }
};