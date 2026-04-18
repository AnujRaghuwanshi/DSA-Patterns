class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int  l = 0;
        int r = str.size()-1;
        while(l<=r){
            if(str[l]==str[r]){
                l++;
                r--;
            }else{
                return false;
            }
        }
        return true;
    }
};