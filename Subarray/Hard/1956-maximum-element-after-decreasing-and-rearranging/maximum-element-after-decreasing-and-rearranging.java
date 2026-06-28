class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        if(arr[0] != 1) arr[0] = 1;
        if(n == 1) return arr[0];

        int max_ele = Integer.MIN_VALUE;
        for(int i = 1; i < n; i++){
            if(Math.abs(arr[i] - arr[i-1]) > 1){
                arr[i] = arr[i-1] + 1;
            }
            max_ele = Math.max(max_ele,arr[i]);
        }
        return max_ele;
    }
}