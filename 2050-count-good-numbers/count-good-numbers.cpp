class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        if (exp == 0) return 1;
        long long half = power(base, exp / 2);
        long long result = (half * half) % MOD;
        if (exp % 2) result = (result * base) % MOD;
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        
        return (power(5, evenPos) * power(4, oddPos)) % MOD;
    }
};