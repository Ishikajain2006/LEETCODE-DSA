class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxele(n);
        vector<int>minele(n) ;
        maxele[0]=nums[0];
        minele[n-1]=nums[n-1];
        for(int i=1 ; i<n ; i++){
           maxele[i]=max(maxele[i-1] , nums[i]);
        }
        for(int i=n-2 ; i>=0 ; i--){
            minele[i]=min(minele[i+1] , nums[i]);
        }
        for(int i=0 ; i<n ; i++){
            if(maxele[i]-minele[i] <= k) return i ;
        }
        return -1 ;
    }
};