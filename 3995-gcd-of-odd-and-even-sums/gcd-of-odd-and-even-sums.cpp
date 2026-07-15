class Solution {
public:
    int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
    int gcdOfOddEvenSums(int n) {
        int a = n*n ;
        int b = n*n + n ;
        return gcd(max(a,b) , min(a,b));
    }
};