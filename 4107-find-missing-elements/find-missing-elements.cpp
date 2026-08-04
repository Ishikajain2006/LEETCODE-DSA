class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int mn = nums[0];
        int mx = *max_element(nums.begin() , nums.end());
        vector<int>ans ;
        int j=0 ;
        for(int i=mn ; i<=mx ; i++){
            if(nums[j]!=i){
                ans.push_back(i);
            }
            else{
                j++ ;
            }
        }
        return ans ;
    }
};