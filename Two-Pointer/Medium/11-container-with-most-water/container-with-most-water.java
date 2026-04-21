class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int max_water = 0;

        while(l < r){
            int width = r - l;
            int len = Math.min(height[l],height[r]);    //length will be minimum vertical line

            max_water = Math.max(max_water,len * width);
             //increment left if height of left pointer is less or right
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }           
        }
        
        return max_water;
    }
}


//skip additional calculations using while loop
/********************************************************************************/

class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int max_water = 0;

        while(l < r){
            int width = r - l;
            int len = Math.min(height[l],height[r]);    //length will be minimum vertical line

            max_water = Math.max(max_water,len * width);
             //increment left if height of left pointer is less or right
            while(l < r && height[l] <= len) l++;
            while(l < r && height[r] <= len) r--;          
        }
        
        return max_water;
    }
}
