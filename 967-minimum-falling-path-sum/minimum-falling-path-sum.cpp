class Solution {
public:
    int f(int i , int j , vector<vector<int>>& matrix , vector<vector<int>>& dp){
        if(i==matrix.size()-1 ) return matrix[i][j] ;
        if(dp[i][j] != -1) return dp[i][j] ;
        int left , right ;
        int down = matrix[i][j] + f(i+1 , j , matrix , dp) ;
        if(j>0) left = matrix[i][j] + f(i+1 , j-1 , matrix , dp);
        else left = 1e9 ;
        if(j+1<matrix[0].size()) right = matrix[i][j] + f(i+1 , j+1 , matrix , dp) ;
        else right = 1e9 ;
        return dp[i][j] = min(down , min(left , right)) ;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size();
        vector<int>prev(m,0);
        for(int j=0 ; j<m ; j++) prev[j] = matrix[0][j] ;
        for(int i=1 ; i<n ; i++){
            vector<int> cur(m,0) ;
            for(int j=0 ; j<m ; j++){
                int down = matrix[i][j] + prev[j];

                int left = matrix[i][j];
                if (j > 0) left += prev[j - 1];
                else left = 1e9;

                int right = matrix[i][j];
                if (j + 1 < m) right += prev[j + 1];
                else right = 1e9;

                cur[j] = min(down , min(left , right)) ;
            }
            prev = cur ;
        }
        return *min_element(prev.begin() , prev.end()) ;


        // vector<vector<int>>dp(n , vector<int>(m,-1)) ;
        // int mini = 1e9 ;
        // for(int i=0 ; i<matrix[0].size() ; i++){
        //    mini = min(mini , f(0 , i , matrix , dp)) ;
        // }
        // for(int j=0 ; j<m ; j++) dp[0][j] = matrix[0][j] ;
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         int down = matrix[i][j] + dp[i - 1][j];

        //         int left = matrix[i][j];
        //         if (j > 0) left += dp[i - 1][j - 1];
        //         else left = 1e9;

        //         int right = matrix[i][j];
        //         if (j + 1 < m) right += dp[i - 1][j + 1];
        //         else right = 1e9;

        //         dp[i][j] = min(down, min(left, right));
        //     }
        // }
        // return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};