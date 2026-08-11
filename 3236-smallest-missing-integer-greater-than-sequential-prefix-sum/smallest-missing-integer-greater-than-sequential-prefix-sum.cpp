class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int count = nums[0] ;
        for(int i=1 ; i<n ; i++){
            if(nums[i]==nums[i-1]+1) {
                count += nums[i];
            }
            else break ;
        }
        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (nums[i] == count) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return count;

            count++;
        }
        return count ;
    }
};