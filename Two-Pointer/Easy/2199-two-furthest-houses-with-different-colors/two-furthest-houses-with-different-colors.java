class Solution {
    public int maxDistance(int[] colors) {
        int n = colors.length;
        int i = 0;
        int j = n-1;

        int dist = 0;

        //Fix the pointer at 0 and Check from backward for different color
        while(colors[i] == colors[j]) j--;
        dist = Math.max(dist,j-i);

        //Fix the pointer at n-1 and Check from forward for different color
        while(colors[i] == colors[n-1]) i++;
        dist = Math.max(dist,n-1-i);

        return dist;
    }
}