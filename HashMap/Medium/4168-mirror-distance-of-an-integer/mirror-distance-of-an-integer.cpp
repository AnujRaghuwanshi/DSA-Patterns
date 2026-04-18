class Solution {
public:
//reverse function 
    int reverse(int num){
        int rev = 0;
        while(num){
            int digit = num % 10;    //extract last digit using Modulo 10
            rev = rev * 10 + digit;  //multiply rev by 10 and add last digit
            num /= 10;               //divide num by 10 to remove last digit
        }
        return rev;
    }
    int mirrorDistance(int n) {
        if(n >= 1 && n<= 9) return 0;   //if n is less than 10 mirror distance will be 0
        int rev = reverse(n);      // reverse n T.C. O(logN)
        return abs(n-rev);      // return absolute diff
    }
};