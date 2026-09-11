class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false ;
        unordered_map<char , int> mp1 ;
        for(char ch : word1) mp1[ch]++ ;
        unordered_map<char , int> mp2 ;
        for(char ch : word2) mp2[ch]++ ;
        for(auto x : mp1){
            char ch = x.first ;
            if(mp2.find(ch)==mp2.end()) return false ;
        }
        unordered_map<int , int> freq1 ;
        for(auto x : mp1){
            int ele = x.second ;
            freq1[ele]++ ;
        }
        unordered_map<int , int> freq2 ;
        for(auto x : mp2){
            int ele = x.second ;
            freq2[ele]++ ;
        }
        if(freq1 != freq2) return false ;
        return true ;
    }
};