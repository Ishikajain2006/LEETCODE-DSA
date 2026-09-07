class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans ;
        unordered_map<int , int> freq ;
        for(int x : digits) freq[x]++ ;
        for(int i=100 ; i<1000 ; i+=2){
            int x = i ;
            int a = x%10 ;
            x/=10 ;
            int b = x%10 ;
            x/=10 ;
            int c = x ;
            if(freq.find(a)!=freq.end()){
                freq[a]-- ;
                if(freq[a]==0) freq.erase(a);
                if(freq.find(b)!=freq.end()){
                    freq[b]-- ;
                    if(freq[b]==0) freq.erase(b);
                    if(freq.find(c)!=freq.end()) ans.push_back(i);
                    freq[b]++ ;
                }
                freq[a]++ ;
            }

        }
        return ans ;
    }
};