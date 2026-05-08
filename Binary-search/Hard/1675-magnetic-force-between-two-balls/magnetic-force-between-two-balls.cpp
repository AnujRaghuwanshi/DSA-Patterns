class Solution {
public:
    bool isPossible(vector<int>& arr,int n, int m, int force){  //O(N)
        int lastbasket = arr[0], balls = 1;
        m--;
        for(int i = 1; i < n; i++){
            if((arr[i] - lastbasket) >= force){
                lastbasket = arr[i];
                m--;
            }
            if(m == 0) return true;
        }
        return m == 0;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());   //O(NlogN)
        int n = position.size();

        int st = 1;
        int end = position[n-1] - position[0];

        int ans = -1;

        while(st <= end){     //O(log(Range)*N)
            int mid = st + (end-st)/2;
            if(isPossible(position,n,m,mid)){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};
