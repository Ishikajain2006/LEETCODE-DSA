class Solution {
public:
    int solve(vector<int>& nums , int start , int end){
        int prev1=0 , prev2=0 ;
        for(int i=start ; i<end ; i++){
            int pick = nums[i]+prev2 ;
            int npick = prev1 ;
            int curr = max(pick , npick);
            prev2 = prev1 ;
            prev1 = curr ;
        }
        return prev1 ;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return  nums[0];
        return max(solve(nums , 1 , nums.size()) , solve(nums , 0 , nums.size()-1));
    }
};