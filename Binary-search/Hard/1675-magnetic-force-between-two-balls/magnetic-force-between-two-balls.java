class Solution {

    private boolean isPossible(int[] arr, int n, int m, int force){   //O(N)
        int lastbasket = arr[0];
        m--;
        for(int i = 0; i < n; i++){
            if((arr[i] - lastbasket) >= force){
                m--;
                lastbasket = arr[i];
            }
            if(m == 0) return true;
        }
        return m == 0;
    }
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);     //O(NlogN)
        int n = position.length;
        int st = 1;
        int end = position[n-1] - position[0];

        int ans = 1;
        while(st <= end){   //O(log(range)*N)
            int mid = st + (end - st) / 2;
            if(isPossible(position, n, m, mid)){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
}