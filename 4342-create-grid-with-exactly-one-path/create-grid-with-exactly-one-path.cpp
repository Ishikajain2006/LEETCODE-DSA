class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // vector<vector<char>> ans(m, vector<char>(n, '#'));
        // for(int i=0 ; i<m ; i++){
        //     if(ans[i][n-1]=='#') ans[i][n-1]='.' ;
        // }
        // for(int i=0 ; i<n ; i++){
        //     if(ans[0][i]=='#') ans[0][i]='.' ;
        // }
        vector<string>grid ;
        
        for(int i=0 ; i<m ; i++){
            string s = "";
            for(int j=0 ; j<n ; j++){
                if(i==0) s+='.' ;
                else if(j==n-1) s+='.' ;
                else s+='#';
            }
            grid.push_back(s);
        }
        return grid ;
    }
};