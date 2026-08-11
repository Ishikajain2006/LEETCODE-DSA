class Solution {
public:
    const int MOD = 1e9 + 7;
    int rev(int num){
        string s = to_string(num);
        reverse(s.begin() , s.end());
        int revele = atoi(s.c_str());
        return revele ;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int> diff;
        for (int x : nums)  diff.push_back(x - rev(x));
        sort(diff.begin(), diff.end());
        long long ans = 0 , cnt = 1 ;
        for (int i = 1; i < diff.size(); i++) {
            if (diff[i] == diff[i - 1]) cnt++;
            else {
                ans = (ans + cnt * (cnt - 1) / 2) % MOD;
                cnt = 1;
            }
        }
        ans = (ans + cnt * (cnt - 1) / 2) % MOD;
        return ans;
    }
};