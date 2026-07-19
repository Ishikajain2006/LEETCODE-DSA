class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26);
        for (int i = 0; i < s.size(); i++) lastIndex[s[i] - 'a'] = i;
        vector<bool> visited(26, false);
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (visited[ch - 'a']) continue;   // Skip if already included
            while (!st.empty() && st.top() > ch &&
                    lastIndex[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = false;    
                st.pop();   // Remove larger characters if they appear later
            }
            st.push(ch);
            visited[ch - 'a'] = true;
        }
        string ans;
        while (!st.empty()) { // Convert stack to string
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};