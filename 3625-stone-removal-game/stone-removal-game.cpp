class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false ;
        bool aliceturn = true ;
        for(int i=10 ; i>=0 ; i--){
            if(n<i && i%2==0){
               aliceturn=false ;
               break ; 
            }
            else if(n<i && i%2!=0) return true ;
            else n=n-i ;
        }
        return aliceturn ;
    }
};