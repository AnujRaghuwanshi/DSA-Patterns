class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n < 2) return n;
        int len = 1;
        int i = 0;
        int j = 0;

        vector<int> Characters(255,-1);
        while(j < n){
            if(Characters[s[j]] != -1){
                i = max(Characters[s[j]]+1 , i);
            }
            Characters[s[j]] = j;
            len = max(len,j-i+1);
            j++;
        }
        return len;
    }
};