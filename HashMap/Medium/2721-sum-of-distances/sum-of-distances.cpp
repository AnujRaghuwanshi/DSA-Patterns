class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n,0);
        if(n == 1) return ans;

        unordered_map<int,long long> indexSum;          //map to store sum of indices
        unordered_map<int,long> freq;                   //map to store frequecny of element

        //calculate sum of |i-j| of left occurring nums[j] == nums[i]
        for(int i = 0; i < n; i++){
            ans[i] += ((long)freq[nums[i]]*i) - indexSum[nums[i]];
            freq[nums[i]]++;
            indexSum[nums[i]] += i;
        }

        indexSum.clear();
        freq.clear();

        //calculate sum of |i-j| of right occurring nums[j] == nums[i]
        for(int i = n-1; i >= 0; i--){
            ans[i] += indexSum[nums[i]] - (freq[nums[i]]*i);
            freq[nums[i]]++;
            indexSum[nums[i]] += i;
        }

        return ans;
    }
};