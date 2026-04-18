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
    int mirrorDistance(int n) {
        if(n >= 1 && n<= 9) return 0;
        int rev = reverse(n);
        return abs(n-rev);
    }
};