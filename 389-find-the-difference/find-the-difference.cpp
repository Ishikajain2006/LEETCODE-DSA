class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size() < t.size()) return findTheDifference(t , s);
        int sfreq[26]={0};
        int tfreq[26]={0};
        for(char ch : s){
            sfreq[ch-'a']++ ;
        }
        for(char ch : t){
            tfreq[ch-'a']++ ;
        }
        for(int i=0 ; i<26 ; i++){
            if(sfreq[i]!=tfreq[i]) return (char)(i+97);
        }
        return 'a' ;
    }
};