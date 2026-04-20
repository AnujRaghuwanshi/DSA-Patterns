class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int dist = 0;
        
        int j = n - 1;
        while(j >= 0){
            if(colors[0] != colors[j]){
                dist = max(dist,j-0);
                break;
            }else{
                j--;
            }
        }

        int i = 0;
        while(i < n){
            if(colors[i] != colors[n-1]){
                dist = max(dist,n-1-i);
                break;
            }else{
                i++;
            }
        }
        return dist;
    }
};