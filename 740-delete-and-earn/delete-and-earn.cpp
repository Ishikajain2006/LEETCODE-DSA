class Solution {
public:

    // Memoization 
    // int f(int ind , vector<int>&freq , vector<int>& dp){
    //     if(ind<=0) return 0 ;
    //     if(dp[ind]!= -1) return dp[ind];
    //     int pick = freq[ind];
    //     if(ind-2>=0) pick+= f(ind-2 , freq , dp);
    //     int npick = f(ind-1 , freq , dp);
    //     return dp[ind] = max(pick , npick);
    // }


    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin() , nums.end());
        vector<int>freq(n+1 , 0);
        for(int x : nums) freq[x]+=x ;
        int f=freq.size();
        int prev2=0 , prev1=0 ;
        for(int i=1 ; i<f ; i++){
            int pick = freq[i] + prev2 ;
            int npick = prev1 ;
            int curr = max(pick , npick);
            prev2=prev1 ;
            prev1=curr ;
        }
        return prev1 ;

        // tabulation
        // vector<int>dp(freq.size()+1 , -1);
        // dp[0]=0 ;
        // for(int i=1 ; i<freq.size() ; i++){
        //     int pick = freq[i];
        //     if(i-2>=0) pick+= dp[i-2];
        //     int npick = dp[i-1];
        //     dp[i] = max(pick , npick);
        // }
        // return dp[freq.size()-1];
    }
};