class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = "";
        while(n>0){
            int digit = n%10;
            n/=10;
            if(digit != 0) s += to_string(digit);
        }
        reverse(s.begin(),s.end());
        int sum = 0 ;
        for(int i=0 ; i<s.size() ; i++){
            sum+=s[i] - '0';
        }
        int x = atoi(s.c_str());
        return 1LL * x * sum;
    }
};