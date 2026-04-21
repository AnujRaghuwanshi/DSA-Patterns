class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_water = 0;

        while(l < r){
            int width = r - l;
            int len = min(height[l],height[r]);    //length will be minimum vertical line

            max_water = max(max_water,len * width);
            height[l] < height[r] ? l++ : r--;     //increment left if height of left pointer is less or right
        }
        
        return max_water;
    }
};

//skip additional calculations using while loop
/************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_water = 0;

        while(l < r){
            int width = r - l;
            int len = min(height[l],height[r]);    //length will be minimum vertical line

            max_water = max(max_water,len * width);
            while(l < r && height[l] < len) l++;     //increment left if height of left pointer is less
            while(l < r &&  height[r] < len) r--;    //increment right if height of right pointer is less
        }
        
        return max_water;
    }
};
