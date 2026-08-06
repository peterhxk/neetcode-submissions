class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(); int n = text2.size();
        vector<int> dp (m+1, 0);
        for (int i = 0; i<n; i++){
            vector<int> cur(m+1,0);
            for (int j = 0; j< m; j++){
                if (text1[j] == text2[i]){
                    cur[j+1]= dp[j]+1;
                } else {
                    cur[j+1] = max(dp[j+1],cur[j]);
                }
                //cout<< cur[j+1]<<", ";
            }
            //cout<<endl;
            dp = cur;
        }
        return dp[m];
    }
};
