class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int total = 0 ;
      int currMax = nums[0] , currMin = nums[0];
      int maxSum = 0 , minSum = 0 ;
      for(int x : nums){
        maxSum = max(x , maxSum + x);
        currMax = max(maxSum , currMax);
        minSum = min(x , minSum+x );
        currMin = min(minSum , currMin);
        total += x ;
      }
      if(currMax<0) return currMax ;
      return max(currMax , total-currMin);
    }
};