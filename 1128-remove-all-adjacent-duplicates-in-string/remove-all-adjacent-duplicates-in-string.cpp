class Solution {
public:
    string sttoa(stack<char>st){
        string s="";
        while(!st.empty()){
        s += st.top();
        st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string removeDuplicates(string s) {
         string ans;

        for (char ch : s) {
            if (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
        // int n = s.length();
        // stack<char>st ;
        // for(char ch : s){
        //    if(!st.empty() && st.top()==ch) st.pop();
        //    else st.push(ch);
        // }
        // string ans = sttoa(st);
        // bool found = true ;
        // for(int i=0 ; i<ans.size()-2 ; i++){
        //     if(ans[i]==ans[i+1]) found = false ;
        // }
        // if(found==false){
        //    ans =  removeDuplicates(ans);
        // }
        // return ans ;
    }
};