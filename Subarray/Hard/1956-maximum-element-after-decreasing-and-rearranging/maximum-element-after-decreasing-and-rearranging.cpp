class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(arr[0] != 1) arr[0] = 1;
        if(n == 1) return arr[0];

        int max_ele = INT_MIN;

        for(int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i-1]) > 1){
                arr[i] = arr[i-1] + 1;
            }
           max_ele = max(max_ele,arr[i]);
               
        }
        return max_ele;
    }
};