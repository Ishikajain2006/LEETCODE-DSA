class Solution {
public:
    int f(int n , int m , vector<vector<int>>& dp){
        if(n==0 && m==0) return 1 ;
        if(n<0 || m<0) return 0 ;
        if(dp[n][m] != -1) return dp[n][m];
        int left = f(n-1 , m , dp) ;
        int up = f(n , m-1 , dp);
        return dp[n][m] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n,-1));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 && j==0) dp[0][0]=1 ;
                else{
                    int left=0 , up = 0 ;
                    if(j>0) left = dp[i][j-1] ;
                    if(i>0) up = dp[i-1][j] ;
                    dp[i][j]=up+left ;
                }
            }
        }
        return dp[m-1][n-1] ;
    }
};