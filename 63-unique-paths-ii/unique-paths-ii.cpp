class Solution {
public:
    int f(int i , int j , vector<vector<int>>& nums , vector<vector<int>>& dp){
        if(i==0 && j==0) return 1 ;
        if(i<0 || j<0 || nums[i][j]==1 ) return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ;
        int left = f(i-1 , j , nums , dp) ;
        int up = f(i , j-1 , nums , dp) ;
        return dp[i][j] = up+left ;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size() ;
        int m = nums[0].size() ;
        vector<vector<int>>dp(n , vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(nums[i][j]==1){
                    dp[i][j] = 0 ;
                    continue ;
                }
                else if(i==0 && j==0){
                    dp[i][j] = 1 ;
                    continue ;
                }
                else{
                    int left = 0, up=0 ;
                    if(j>0) left = dp[i][j-1] ;
                    if(i>0) up = dp[i-1][j] ;
                    dp[i][j] = left+up ;
                }
            }
        }

        return dp[n-1][m-1];
    }
};