class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n<=8) return n ;
        int cnt = 8 ;
        int num = 2;
        n = n-8 ;
        while(n>0){
            int take = min(8, n);
            cnt += take * num;
            n -= take;
            num++;
        }
        return cnt ;

        
    }
};