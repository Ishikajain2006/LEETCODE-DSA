class Solution {
public:
    void solve(int ind, int parts, string &s, string ans, vector<string>& res) {
        if(parts == 4) {
            if(ind == s.length()) {
                res.push_back(ans) ;
            }
        return;
        }
        if(ind == s.length()) return ;
        for(int len = 1; len <= 3; len++) {
            if(ind + len > s.length()) break;
            string temp = s.substr(ind, len);
            if(temp.length() > 1 && temp[0] == '0') continue;
            int num = stoi(temp) ;
            if(num>255) continue ;
            string updated = ans + temp;
            if(parts < 3) updated += ".";
            solve(ind + len, parts + 1, s, updated , res);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.length() ;
        vector<string>ans ;
        solve(0 , 0 , s , "" , ans) ;
        return ans ;
    }
};