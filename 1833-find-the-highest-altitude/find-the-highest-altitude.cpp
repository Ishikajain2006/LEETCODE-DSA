class Solution {
public:
    int largestAltitude(vector<int>& gain)
    // {
    //     vector<int>ans ;
    //     int sum=0 ;
    //     for(int i=0 ; i<gain.size() ; i++){
    //         ans.push_back(sum);
    //         sum += gain[i];
    //     }
    //     int high = *max_element(ans.begin() , ans.end());
    //     return high ;
    // }
    {
        int sum =0 , high = INT_MIN ;
        for(int i=0 ; i<gain.size() ; i++){
            sum+=gain[i];
            high = max(sum , high);
        }
        if(high<0) return 0;
        return high ;
    }
};