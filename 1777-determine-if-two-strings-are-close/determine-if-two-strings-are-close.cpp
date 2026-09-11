class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false ;
        unordered_map<char , int> mp1 , mp2 ;
        for(int i=0 ; i<word1.size() ; i++){
            mp1[word1[i]]++ ;
            mp2[word2[i]]++ ;
        }
        for(auto x : mp1){
            char ch = x.first ;
            if(mp2.find(ch)==mp2.end()) return false ;
        }
        unordered_map<int , int> freq1 , freq2 ;
        for(auto x : mp1)freq1[x.second]++ ;
        for(auto x : mp2) freq2[x.second]++ ;
        return freq1 == freq2 ;
    }
};