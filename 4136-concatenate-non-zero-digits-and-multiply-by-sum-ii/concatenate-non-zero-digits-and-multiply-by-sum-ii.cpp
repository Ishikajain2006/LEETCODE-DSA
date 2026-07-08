class Solution {
public:
    long long mod = 1e9 + 7 ;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long> prefixSum(n,0);
        vector<long long> preNonZeroNum(n,0);
        vector<long long> preCount(n,0);
        for(int i=0 ; i<n ; i++){
            int digit = s[i]-'0';
            if(i>0){
                prefixSum[i] = prefixSum[i-1];
                preNonZeroNum[i] = preNonZeroNum[i-1];
                preCount[i] = preCount[i-1];
            }
            if(digit != 0){
                prefixSum[i] += digit ;
                preCount[i] ++ ;
                preNonZeroNum[i] = (preNonZeroNum[i] * 10 + digit) % mod;
            }
        }
        vector<long long> power(n + 1, 1);
        for(int i=1 ; i<=n ; i++){
            power[i]=(power[i-1] * 10) % mod ;
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i=0 ; i<m ; i++){
            int l = queries[i][0] , r = queries[i][1] ;
            long long len = preCount[r]-((l>0) ? preCount[l-1] : 0);
            long long x =  preNonZeroNum[r] ;
            if(l>0) x = (x - preNonZeroNum[l - 1] * power[len] % mod + mod) % mod;
            long long sum = prefixSum[r];
            if (l > 0) sum -= prefixSum[l - 1];
            sum = (sum % mod + mod) % mod;
            ans[i] = (x * sum) % mod;
        }
        return ans ;
    }
};