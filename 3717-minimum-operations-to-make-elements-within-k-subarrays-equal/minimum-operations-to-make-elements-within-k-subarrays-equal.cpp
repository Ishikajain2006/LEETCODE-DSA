class Solution {
public:
    long long cost(vector<int>& nums, int i, int j) {
        vector<int> v(nums.begin() + i, nums.begin() + j);
        sort(v.begin(), v.end());
        int mid = v.size() / 2;
        long long ans = 0;
        for (int a : v)   ans += abs((long long)a - v[mid]);
        return ans;
    }
    long long f(vector<int>& nums, int i , int k , int x , vector<vector<int>>& dp){
        if(k == 0) return 0;
        if(nums.size() - i < k * x) return LLONG_MAX / 4;
        if(dp[i][k] != -1) return dp[i][k] ;
        long long take = cost(nums , i , i+x) + f(nums , i+x , k-1 , x , dp) ;
        long long ntake = f(nums , i+1 , k , x , dp) ;
        return dp[i][k] = min(take , ntake) ;
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4 ;
        vector<long long> windowCost(n - x + 1, 0);
        multiset<int> left, right;
        long long sumL = 0, sumR = 0;
        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(left.find(val));
                sumL -= val;
                right.insert(val);
                sumR += val;
            }
            while (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.find(val));
                sumR -= val;
                left.insert(val);
                sumL += val;
            }
        };
        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            } else {
                right.insert(val);
                sumR += val;
            }
            balance();
        };
        auto remove = [&](int val) {
            auto it = left.find(val);
            if (it != left.end()) {
                left.erase(it);
                sumL -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }
            balance();
        };
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                int start = i - x + 1;
                long long median = *left.rbegin();
                windowCost[start] = median * (long long)left.size() - sumL + sumR - median * (long long)right.size();
            }
        }
        vector<long long> prev(n + 1, 0), curr(n + 1, INF);
        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF) ;
            for (int i = n - x; i >= 0; i--) {
                long long ntake = curr[i + 1];
                long long take = INF;
                if (prev[i + x] != INF) take = windowCost[i] + prev[i + x];
                curr[i] = min(take, ntake);
            }
            prev = curr;
        }
    return prev[0];
    }
};