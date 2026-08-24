class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sn = s.length() , tn = t.length();
        int cnt=0 ;
        for(int i=0 , j=0 ; i<sn && j<tn ; j++){
            if(cnt == sn) return true ;
            if(s[i]==t[j]){
                i++ ;
                cnt++ ;
            }
        }
        return cnt == sn ;
    }
};