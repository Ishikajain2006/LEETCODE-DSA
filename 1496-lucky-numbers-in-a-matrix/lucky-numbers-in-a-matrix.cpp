class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>row(n);
        vector<int>col(m);
        vector<int>ans ;
        for(int i=0 ; i<n ; i++){
            int num2 = INT_MAX ;
            for(int j=0 ; j<m ; j++){
                num2 = min(num2 , matrix[i][j]);
            }
            row[i] = num2;
        }
        for(int i=0 ; i<m ; i++){
            int num1 = INT_MIN ;
            for(int j=0 ; j<n ; j++){
                num1 = max(num1 , matrix[j][i]);
            }
            col[i] = num1;
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
            if(matrix[i][j]==row[i] && matrix[i][j]==col[j]) ans.push_back(matrix[i][j]);
            }
        }
        return ans ;
    }
};