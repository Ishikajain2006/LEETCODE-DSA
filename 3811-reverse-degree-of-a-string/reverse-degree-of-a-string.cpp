class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char , int> character ;
        int add=0 ;
        for(int i=26 ; i>0 ; i-- , add++)  character['a'+add]=i ;
        int sum = 0 ;
        for(int i=0 ; i<s.length() ; i++) sum += (i+1)*(character[s[i]]);
        return sum ;
    }
};