#include<cmath>
class Solution {
public:
    long long power(long long x, long long y) { 
        long long ans = 1; 
        long long MOD = 1e9 + 7; 
        while (y > 0) {
            if (y % 2 == 1)  ans = (ans * x) % MOD;
            x = (x * x) % MOD; 
            y /= 2; 
        } 
        return ans; 
    }
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0; 
        long long MOD = 1e9 + 7; 
        for (int i = 0; i < nums.size(); i++) { 
            long long num = nums[i]; 
            int width = num % 10; 
            long long d = num / 10; 
            string s = to_string(d); 
            string x = s.substr(0, width);
            string y = s.substr(width);
            long long base = stoll(x); 
            long long exp = stoll(y); 
            sum = (sum + power(base, exp)) % MOD; 
        } 
        return sum;
    }
};