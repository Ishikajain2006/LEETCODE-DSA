class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int duplicate = 0 ;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[i]==nums[i+1]){
                duplicate = nums[i];
                break ;
            }
        }
        int original_total = (n*(n+1))/2 ;
        int duplicate_total = accumulate(nums.begin() , nums.end() , 0);
        int missing_element = duplicate+(original_total - duplicate_total);

        return {duplicate , missing_element } ;
    }
};