class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0 , product = 1 ;
        int og = n ;
        while(og>0){
            int digit = og%10 ;
            og= og/10 ;
            sum+=digit ;
            product*=digit ;
        }
        return n%(sum+product)==0 ;
    }
};