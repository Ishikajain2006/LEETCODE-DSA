class Solution {
public:
    // int f(vector<int>& nums, int i , int j , int sum , int l, int r){
    //     if (j == nums.size()) return INT_MAX;
    //     int take = INT_MAX, left = INT_MAX;
    //     if (j - i + 1 > r) return INT_MAX;
    //     sum += nums[j];
    //     int ans = INT_MAX;
    //     if (j - i + 1 >= l && sum > 0)  ans = sum;  // Check whether current subarray is valid
    //     take = f(nums, i, j + 1, sum, l, r);  // Extend current subarray
    //     if (i + 1 < nums.size()) left = f(nums, i + 1, i + 1, 0, l, r); // Start a new subarray
    //     return min({ans, take, left});
    // }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        // int ans = f(nums , 0 , 0 , 0 , l, r) ;
        // if(ans == INT_MAX ) return -1 ;
        // return ans ;
        int n = nums.size() ;
        int mini = INT_MAX ;
        for(int i=0 ; i<n ; i++){
            int sum = 0 ;
            for(int j=i ; j<n ; j++){
                if(j-i+1 > r) break ;
                sum += nums[j] ;
                if(j - i + 1 >= l && sum > 0) mini = min(sum , mini) ;
            } 
        }
        return mini == INT_MAX ? -1 : mini  ;
    }
};