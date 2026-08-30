class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = *min_element(nums.begin() , nums.end());
        int mx = *max_element(nums.begin() , nums.end());
        int n = nums.size();
        int mnPos, mxPos;
        for(int i = 0; i < n; i++) {
            if(nums[i] == mn) mnPos = i;
            if(nums[i] == mx) mxPos = i;
        }
        int left = min(mnPos, mxPos);  // left most mn , mx index
        int right = max(mnPos, mxPos);  // rightmost mn , mx index
        int front = right + 1;        // aage se element hatate h to right+1 tak hatana pdega
        int back = n - left;          // piche se hatate h to n-left tak hatana pdega
        int both = (left + 1) + (n - right);   // aage piche dono taraf se hatate h to thoda aage se thoda piche se hatna pdega
        return min({front, back, both}); // return kr denge in tino me se sabse kaam ele kab remove krne h
    }
};