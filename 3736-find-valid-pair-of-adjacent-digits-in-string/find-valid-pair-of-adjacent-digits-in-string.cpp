class Solution {
public:
    string findValidPair(string s) {
       vector<int> freq(10,0);
       freq[0]=-1 ;
       for(char ch : s){
           freq[ch - '0']++ ;
       }
       for (int i = 0; i < s.size() - 1; i++) {
            int d1 = s[i] - '0' , d2 = s[i + 1] - '0';
            if (d1 != d2 && freq[d1] == d1 && freq[d2] == d2)  return s.substr(i, 2);
        }
       return "" ;
    }
};