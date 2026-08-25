class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        for(int i=0 , a=1 ; i<nums.size() ; i++){
            int num = k*a ;
            if(nums[i]<num) continue ;
            else if(nums[i]==num) a++ ;
            else{
                return k*a ;
            }
        }
        // if(nums[nums.size()-1]%k==0) return nums[nums.size()-1]+k ;
        int ans = nums[nums.size()-1]+1;
        while(ans%k!=0) ans++ ;
        return ans ;
    }
};