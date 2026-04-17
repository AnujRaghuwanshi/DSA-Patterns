class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num){
            int digit = num % 10;
            rev = rev * 10 + digit;
            num /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return -1;

        int ans = INT_MAX;

        unordered_map<int,int> mp;
        mp.insert({reverse(nums[0]),0});

        for(int i = 1; i < n; i++){
            if(mp.count(nums[i])){
                ans = min(abs(mp[nums[i]] - i), ans);
                if(ans == 1) return ans;

            }
                int rev = reverse(nums[i]);
                if(mp.count(rev)){
                    mp[rev] = i;
                }else{
                    mp.insert({rev,i});
                }
        
        }

        return ans == INT_MAX ? -1 : ans;
    }
};