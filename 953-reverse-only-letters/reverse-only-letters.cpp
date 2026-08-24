class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int i=0 , j=n-1 ;
        while(i<j){
            while(!isalpha(s[i])){
                i++ ;
                if(i==j) return s ;
            }
            while(!isalpha(s[j])){
                j-- ;
                if(j==i) return s ;
            }
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i] , s[j]);
                i++ , j-- ;
            }
        }
        return s ;
    }
};