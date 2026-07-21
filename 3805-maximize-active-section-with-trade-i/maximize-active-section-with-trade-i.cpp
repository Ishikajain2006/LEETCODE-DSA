class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        vector<pair<char,int>> runs ;
        for (char c : t) {
            if (runs.empty() || runs.back().first != c) runs.push_back({c, 1});
            else  runs.back().second++;
        }
        int totalOnes = 0;
        for (char c : s)  if (c == '1') totalOnes++;
        int ans = totalOnes;
        for (int i = 1; i + 1 < runs.size(); i++) { 
            // t ke aage aur piche 1 add kre the issliye
            if (runs[i].first == '1' && runs[i - 1].first == '0' 
                && runs[i + 1].first == '0'){ // 00 | 111 | 00
                int removed = runs[i].second;
                int mergedZero = runs[i - 1].second + removed + runs[i + 1].second;
                if (i - 1 == 0) mergedZero--; // aage jo one lagaya vo hata do
                if (i + 1 == runs.size() - 1) mergedZero--; // piche wala 1 hata do
                ans = max(ans, totalOnes - removed + mergedZero);
            }
        }
        return ans ;
    }
};