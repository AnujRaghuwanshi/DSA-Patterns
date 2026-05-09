class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        int st = 1;
        int end = x;
        int ans = -1;

        while(st <= end){
            int mid = st + (end-st)/2;
            if(mid <= x/mid){
                ans = max(ans,mid);
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};