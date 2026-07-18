class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st ;
        for (string ch : operations) {
            if (ch == "+") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.push(x);
            st.push(x + y);
            }
            else if (ch == "D") st.push(2 * st.top());
            else if (ch == "C") st.pop();
            else st.push(atoi(ch.c_str()));
        }
        int sum = 0 ;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum ;
    }
};