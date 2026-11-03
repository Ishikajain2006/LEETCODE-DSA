class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        int diff = 0 , n = nums.size() ;
        for(int i=0 ; i<n-1 ; i++)  diff += abs(nums[n-1] - nums[i]) ;
        return diff ;
    }
}; 