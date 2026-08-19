class Solution {
public:
    bool isfree(unordered_set<int>&seat , int start){
        
        for(int i=start ; i<start+4 ; i++){
            if(seat.count(i)) return false ;
        }
        return true ;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int possible = 0 ;
        unordered_map<int , unordered_set<int>> mp ;
        for(auto seats : reservedSeats){
            int row = seats[0];
            int seat = seats[1];
            mp[row].insert(seat);
        }
        for(auto& [row , seat] : mp){
            bool left = isfree(seat , 2);
            bool mid = isfree(seat , 4);
            bool right = isfree(seat , 6);

            if(left && right) possible+=2 ;
            else if(left || mid || right) possible+=1 ;

        }
        possible += (n-mp.size())*2 ;
        return possible ;
    }
};