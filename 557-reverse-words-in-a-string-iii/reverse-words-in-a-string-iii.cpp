class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        for(int i=0 ; i<n ; i++){
            int j=i ;
            while(s[i]!=' '){
                i++ ;
                if(i==n) break ;
            }
            reverse(s.begin()+j , s.begin()+i);
        }
        return s ;
    }
};