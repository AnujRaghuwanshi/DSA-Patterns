class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int dist = 0;
        
        int j = n - 1;
        //Fix the pointer at 0 and Check from backward for different color
        while(j >= 0){
            if(colors[0] != colors[j]){
                dist = max(dist,j-0);
                break;
            }else{
                j--;
            }
        }

        int i = 0;
        //Fix the pointer at n-1 and Check from forward for different color
        while(i < n){
            if(colors[i] != colors[n-1]){
                dist = max(dist,n-1-i);
                break;
            }else{
                i++;
            }
        }
        //retrun furthest houses distance
        return dist;
    }
};
