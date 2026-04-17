class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> char_cnt(26,0);
        for(auto ch : s){
            char_cnt[ch - 'a']++;
        }

        for(auto c : t){
            if(char_cnt[c - 'a'] > 0){
               char_cnt[c - 'a']--;
            }else{
                return false;
            }
        }
        return true;
    }
};