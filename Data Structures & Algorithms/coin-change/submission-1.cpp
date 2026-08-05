class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1, amount+1);
        for (int coin : coins){
            vector<int> cur (amount+1, amount+1);
            cur[0] = 0;
            //cout<<endl;
            for (int i = 0; i<amount+1; i++){
                // [0,0,0,0]
                // [0,0,1,]

                // [0,1,2,3,4,5,6,7,8,9,10,11,12]
                // [0,1,1,2,2,3,3,4,4,5,5,6,6]
                // [0,1,1,2,2,1,2,2,3,3,2,3,3]
                
                if (i-coin>=0){
                    cur[i] = min(dp[i], cur[i-coin]+1);  
                }
                else{
                    cur[i] = min(cur[i],dp[i]);
                }
                //cout<<cur[i]<<", ";
            }
            dp = cur;
        }
        return dp[amount]==amount+1? -1:dp[amount];
    }
};
