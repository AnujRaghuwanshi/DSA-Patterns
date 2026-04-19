class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int dist = 0;

        if(n1 == 1 && n2 == 1) return dist;

        int i = 0;
        int j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                j++;                  //if nums1[i] <= nums2[j] increment j to find farthest element
            }
            else{
                dist = Math.max(dist, j-i-1);    //calculate dist using (j-i-1) becz j++ will move it one pos ahead
                i++;
                if(i > j) j = i;        //check whether i is greater then j or not
            }
        }
        return Math.max(dist, j-i-1);
    }
}