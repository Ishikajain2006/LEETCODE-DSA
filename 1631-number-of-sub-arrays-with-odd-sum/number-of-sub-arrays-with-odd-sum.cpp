class Solution {
public:
    const int mod = 1e9 + 7 ;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size() ;
        long long ans = 0 ;
        int odd = 0 , even = 1 ;
        int sum = 0 ;
        for(int i=0 ; i<n ; i++){
            sum = (sum+arr[i])%2 ;
            if(sum==1){
                ans+=even ;
                odd++ ;
            }else{
                ans+= odd ;
                even++ ;
            }
        }
        return ans %= mod ;
    }
};