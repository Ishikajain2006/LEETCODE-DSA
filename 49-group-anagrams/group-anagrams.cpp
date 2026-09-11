class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mp ;
        int n = strs.size();
        for(int i=0 ; i<n ; i++){
            string lexo = strs[i];
            sort(lexo.begin() , lexo.end());
            mp[lexo].push_back(strs[i]);
            // if(mp.find(lexo)!=mp.end()) mp[lexo].push_back(strs[i]);
            // else mp[lexo].push_back(strs[i]);
        }
        vector<vector<string>> ans ;
        for(auto ele : mp)  ans.push_back(ele.second);
        return ans ;
    }
};