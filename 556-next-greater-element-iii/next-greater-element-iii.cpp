class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int size = s.size();
        int breakpoint = -1 ;
        for(int i=size-2 ; i>=0 ; i--){
            if(s[i]<s[i+1]){
                breakpoint = i ;
                break ;
            }
        }
        if(breakpoint == -1) return -1 ;
        for (int i = size - 1; i > breakpoint; i--){
            if (s[i] > s[breakpoint]) {
                swap(s[i], s[breakpoint]);
                break;
            }
        }
        reverse(s.begin()+breakpoint+1 , s.end());
        long long ans = stoll(s);
        if (ans > INT_MAX) return -1;
        return  ans ;
    }
};