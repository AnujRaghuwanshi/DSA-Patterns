class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(hashmap.contains(complement)){
                return {hashmap[complement],i};
            }
            hashmap.insert({nums[i],i});
        }
        return {};
    }
};