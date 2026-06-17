class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if ('a' <= ch && ch <= 'z')  cur++;
            else if (ch == '#')   cur = min(cur * 2, (long long)4e18);
            else if (ch == '%') ;
            else if (ch == '*') {
                if (cur > 0) cur--;
            }
            len[i] = cur;
        }
        if (k >= cur) return '.';
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long prev = (i == 0 ? 0 : len[i - 1]);
            if ('a' <= ch && ch <= 'z') {
                if (k == prev)  return ch;
            }
            else if (ch == '#') {
                if (k >= prev)  k -= prev;
            }
            else if (ch == '%')  k = prev - 1 - k;
            else if (ch == '*');
        }
        return '.';
    }
};