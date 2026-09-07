class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false ;
        unordered_map<char , int>mps(0) ;
        for(char ch : s) mps[ch]++ ;
        // unordered_map<char , int>mpt(0);
        // for(char ch : t) mpt[ch]++ ;
        // for(auto m : mps){
        //     char ch = m.first ;
        //     int freq1 = m.second;
        //     if(mpt.find(ch)!=mpt.end()){
        //         if(freq1 != mpt[ch]) return false ;
        //     }else return false ;
        // }
         for(char ch : t){
            if(mps.find(ch)!=mps.end()){
                mps[ch]-- ;
                if(mps[ch]==0) mps.erase(ch);
            }else return false ;
         }

        return mps.empty() ;
    }
};