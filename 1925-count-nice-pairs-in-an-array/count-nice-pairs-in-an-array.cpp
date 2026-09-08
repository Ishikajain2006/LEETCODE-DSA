class Solution {
public:
    int MOD = 1e9 + 7;
    int reverse(int n ){
        int r = 0 ;
        while(n>0){
            r*=10 ;
            r+=n%10 ;
            n/=10 ;
        }
        return r ;
    }
    int countNicePairs(vector<int>& nums) {
        int count = 0 ;
        // for(int i=0 ; i<nums.size() ; i++) nums[i] -= reverse(nums[i]);
        unordered_map<int , int>freq ;
        for (int num : nums) {
            int diff = num - reverse(num);
            count = (count + freq[diff]) % MOD;
            freq[diff]++;
        }
        return count ;
    }
};