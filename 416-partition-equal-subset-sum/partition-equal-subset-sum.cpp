class Solution {
public:
    bool f(int ind , vector<int>& nums , int target , vector<vector<int>>& dp){
        if(target == 0) return true ;
        if(ind==0  ) return (nums[0]==target) ;
        if(dp[ind][target] != -1) return dp[ind][target] ;
        bool ntake = f(ind-1 , nums , target , dp);
        bool take = false ;
        if(target >= nums[ind]) take = f(ind-1 , nums , target-nums[ind] , dp) ;
        return dp[ind][target] = (ntake || take) ;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = accumulate(nums.begin() , nums.end() , 0) ;
        vector<vector<int>>dp(n , vector<int>((sum/2)+1 , -1));
        if(sum%2 != 0) return false ;
        return f(n-1 , nums , sum/2 , dp) ;
    }
};