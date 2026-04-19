class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int dist = 0;
        if(n1 == 1 && n2 == 1) return dist;

        int i = 0;
        int j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                j++;
            }
            else{
                dist = max(dist, j-i-1);
                i++;
                if(i > j) j = i;
            }
        }
        return max(dist, j-i-1);
    }
};