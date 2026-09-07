class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> freq ;
        for(int x : arr) freq[x]++ ;
        unordered_set<int>s ;
        for(auto x : freq){
            if(s.find(x.second)!=s.end()) return false ;
            s.insert(x.second);
        }
        return true ;
    }
};