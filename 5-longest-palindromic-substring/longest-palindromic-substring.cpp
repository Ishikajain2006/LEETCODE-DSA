class Solution {
public:
    bool palindrome(string &s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxLen = 1;
        int startIdx = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(palindrome(s, i, j)){
                    int len = j - i + 1;
                    if(len > maxLen){
                        maxLen = len;
                        startIdx = i;
                    }
                }
            }
        }
        return s.substr(startIdx, maxLen);
    }
};