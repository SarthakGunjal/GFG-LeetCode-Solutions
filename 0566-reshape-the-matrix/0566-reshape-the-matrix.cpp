class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int n = mat.size();
        int m = mat[0].size();

        int columnCopy = c;

        vector<vector<int>> ret{};
        if(n*m != r*c) return mat;

        else{

            c = 0;
            r = -1;

            for(int i=0; i<n; i++){

                for(int j=0; j<m; j++){

                    if(c == 0) {ret.push_back(vector<int>()); c = columnCopy; r++;}
                
                    ret[r].push_back(mat[i][j]);
                    c--;
                    
                }

            }

        }

        return ret;

    }
};