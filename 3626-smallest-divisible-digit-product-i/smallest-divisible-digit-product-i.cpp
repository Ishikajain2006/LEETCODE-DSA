class Solution {
public:
    int smallestNumber(int n, int t) {
        int og = n ;
        int num = 1 ;
        while(og>0){
            int digit = og%10 ;
            og = og/10 ;
            num *= digit ;
        }
        if(num % t ==0) return n ;
        return smallestNumber(n+1 , t);
    }
};