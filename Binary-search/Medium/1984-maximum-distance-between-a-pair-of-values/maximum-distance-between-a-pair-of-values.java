class Solution {

    int searchFarElement(int i, int nums1_ele, int[] nums2, int n2){
        int low = 0;
        int high = n2 - 1;
        int j = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums2[mid] >= nums1_ele){
                j = Math.max(mid, j);
                low = mid + 1;
            }
            else if(nums2[mid] < nums1_ele){
                high = mid - 1;
            }
        }
        return j;
    }

    public int maxDistance(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;

        int dist = 0;
        if(n1 == 1 && n2 == 1) return dist;

        for(int i = 0; i < n1; i++){
            int j = searchFarElement(i, nums1[i], nums2, n2);
            if(j != -1){
                dist = Math.max(dist, j-i);
            }
        }
        return dist;
    }
}