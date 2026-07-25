class Solution {
public:
    int maxProduct(int n){
       string s = to_string(n);
       sort(s.rbegin() , s.rend());
       int num1 = s[0]-'0';
       int num2 = s[1]-'0';
       return num1*num2 ;
    }
};