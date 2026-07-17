class Solution {
public:
    int gcd(int a , int b){
        while(b!=0){
            int temp = a%b ;
            a=b ;
            b = temp ;
        }
        return a ;
    }
    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y) return false ;
        int div = gcd(x,y);
        if(target%div==0) return true ;
        return false ;
    }
};