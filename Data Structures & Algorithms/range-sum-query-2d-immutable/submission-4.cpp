class NumMatrix {
public:
    vector<int> prefix;
    int offset;
    NumMatrix(vector<vector<int>>& matrix) {
        int sum = 0;
        offset = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                sum += matrix[i][j];
                prefix.push_back(sum);
                cout << sum << ", ";
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row2; i>=row1; i--){
            if (col1 == 0){
                if (i==0){
                    return sum + prefix[col2];
                }
                sum += prefix[i*offset+col2]-prefix[(i-1)*offset+offset-1];
            }
            else {
                sum += prefix[i*offset+col2]-prefix[i*offset+col1-1];
            }
        }
        
        return sum;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */