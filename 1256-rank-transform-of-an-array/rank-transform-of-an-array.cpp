class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> og = arr;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int n = og.size();
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(arr.begin(), arr.end(), og[i]);
            og[i] = distance(arr.begin(), it) + 1;
        }
        return og;
    }
};