class Solution {
public:
    int lengthOfLastWord(string s) {
       int cnt = 0 ;
       int n = s.size()-1;
       while(n>=0 && s[n]==' ') n-- ;
       for(int i=n ; i>=0 ; i--){
        
        char ch = s[i];
          if(ch <= 90 && ch >= 65 || ch >= 97 && ch <= 122) cnt++ ;
          else if(ch == ' ') return cnt ;
       }
       return cnt ; 
    }
};