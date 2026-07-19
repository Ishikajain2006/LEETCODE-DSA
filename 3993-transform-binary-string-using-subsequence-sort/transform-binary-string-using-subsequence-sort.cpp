class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
       int n = s.length() , m = strs.size();
       int freq=0 ;
       vector<bool>ans ;
       vector<int> pre(n, 0);
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1') freq++ ;
            pre[i] = freq ;
        } 
        for(auto &it : strs){
            int one = 0 , query=0 ;
            for(auto &i : it){
                if(i=='1') one++ ;
                if(i=='?') query++ ;
            }
            if(one>freq || one+query <freq){
                ans.push_back(false);
                continue ;
            }
            int want = freq-one ;
            string target = it ;
            for(int i = n-1 ; i >= 0 ; i--){
                if(target[i] == '?'){
                    if(want > 0){
                        target[i] = '1';
                        want-- ;
                    } else {
                        target[i] = '0';
                    }
                }
            }
            bool possible = true ;
            int curr = 0 ;
            for(int i = 0 ; i < n ; i++){
                if(target[i] == '1') curr++ ;
                if(curr > pre[i]){
                    possible = false ;
                    break ;
                }
            }
            ans.push_back(possible);
        }
        return ans ;
    }
};