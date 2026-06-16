class Solution {
public:
    string processStr(string s) {
        string result = "";
        int n = s.length();
        for(int i=0 ; i<n ; i++){
            if(s[i]>='a' && s[i]<='z') result += s[i];
            if(s[i]=='#') result += result ;
            if(s[i]=='%') reverse(result.begin(),result.end());
            if(s[i]=='*'){
                if(result.length()>=1) result.pop_back();
            }
        }
        return result ;
    }
};