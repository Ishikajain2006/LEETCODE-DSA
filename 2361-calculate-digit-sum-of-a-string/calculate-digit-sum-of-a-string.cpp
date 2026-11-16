class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k) return s ;
        int n = s.length() ;
        vector<int>temp ;
        for(int i=0 ; i<n ; i+=k){
            int sum = 0 ;
            for(int j=i ; j < min(i+k, n) ; j++){
                sum += s[j] - '0';
            }
            temp.push_back(sum) ;
        }
        int size = temp.size() ;
        string newstr = "" ;
        for(int i=0 ; i<size ; i++) newstr += to_string(temp[i]);
        return digitSum(newstr , k) ;
    }
};