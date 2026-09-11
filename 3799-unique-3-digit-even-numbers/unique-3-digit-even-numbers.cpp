class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        if(n<=2) return 0 ;
        unordered_map<int,int> freq ;
        for(int digit : digits) freq[digit]++ ;
        int cnt=0 ;
        for(int i=100 ; i<999 ; i+=2){
            int num = i;
            int a = num % 10;        // Units digit
            int b = (num / 10) % 10; // Tens digit
            int c = num / 100;
            if(freq.find(a)!=freq.end()){
                freq[a]-- ;
                if(freq[a]==0) freq.erase(a);
                if(freq.find(b)!=freq.end()){
                    freq[b]-- ;
                    if(freq[b]==0) freq.erase(b);
                        if(freq.find(c)!=freq.end()) cnt++ ;
                    freq[b]++ ;
                }
                freq[a]++ ;
            }
        }
        return cnt ;
    }
};