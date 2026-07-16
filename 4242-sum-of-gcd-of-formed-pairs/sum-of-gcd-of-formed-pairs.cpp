class Solution {
public:
    int gcd(int a , int b){
        int temp ;
        while(b!=0){
           temp = a%b ;
           a=b ;
           b=temp ;
        }
        return a ;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd(n,0) ;
        int maxi = INT_MIN ;
        for(int i=0 ; i<n ; i++){
            maxi = max(nums[i] , maxi);
            prefixGcd[i] = gcd(nums[i] , maxi);
        }
        sort(prefixGcd.begin() , prefixGcd.end());
        long long sum = 0 ;
        for(int i=0 , j=n-1 ; i<j ; i++ , j--){
            sum+=gcd(prefixGcd[i] , prefixGcd[j]);
        }
        return sum ;
    }
};