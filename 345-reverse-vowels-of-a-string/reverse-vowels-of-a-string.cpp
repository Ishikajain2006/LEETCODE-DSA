class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
       vector<char> vowel ;
       for(int i=0 ; i<n ; i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||  s[i]=='u'){
            vowel.push_back(s[i]);
        }
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            vowel.push_back(s[i]);
        }
       }
       reverse(vowel.begin() , vowel.end());
       int a=0 ;
       string ans ="";
       for(int i=0 ; i<n ; i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            ans+=vowel[a];
            a++ ;
            continue ;
        }
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            ans+=vowel[a];
            a++ ;
            continue ;
        }
        else ans += s[i];
       } 
       return ans ;
    }
};