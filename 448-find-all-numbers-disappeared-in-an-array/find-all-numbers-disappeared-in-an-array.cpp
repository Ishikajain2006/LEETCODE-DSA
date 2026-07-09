class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans ;
        sort(nums.begin() , nums.end());
        int expected = 1;
        for (int x : nums) {
            while (expected < x) {
                ans.push_back(expected);
                expected++;
            }
            if (expected == x)  expected++;
        }
        while (expected <= nums.size()) {
            ans.push_back(expected);
            expected++;
        }
        return ans ;
    }
};