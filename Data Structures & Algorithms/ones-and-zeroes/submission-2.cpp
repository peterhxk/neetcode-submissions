class Solution {
public:
    pair<int,int> count(string str){
        int m = 0; int n = 0;
        for (char c : str){
            if (c == '1'){
                n++;
            }
            else{
                m++;
            }
        }
        return {m,n};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        //knapsack
        //x:strs.size()+1
        //y:m+1
        //z:n+1
        vector<vector<vector<int>>> s (strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        //s[0][0][0]=0;
        for (int i = 1; i<=strs.size();i++){
            auto cur = count(strs[i-1]);
            for (int j=0; j<=m; j++){
                for (int k=0; k<=n; k++){
                    int prev = s[i-1][j][k];
                    if (j-get<0>(cur)>=0 && k-get<1>(cur)>=0){
                        // if (s[i-1][j-get<0>(cur)][k-get<1>(cur)] == -1){
                        //     continue;
                        // }
                        s[i][j][k] = max(prev, s[i-1][j-get<0>(cur)][k-get<1>(cur)]+1);
                    } else{
                        s[i][j][k] = prev;
                    }
                }
            }
        }
        return s[strs.size()][m][n];

    }
};