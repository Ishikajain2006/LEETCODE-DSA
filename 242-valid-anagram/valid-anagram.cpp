class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false ;
        unordered_map<char , int>mps(0) ;
        unordered_map<char , int>mpt(0);
        for(char ch : s) mps[ch]++ ;
        for(char ch : t) mpt[ch]++ ;
        for(auto m : mps){
            char ch = m.first ;
            int freq1 = m.second;
            if(mpt.find(ch)!=mpt.end()){
                if(freq1 != mpt[ch]) return false ;
            }else return false ;
        }
        return true ;
    }
};