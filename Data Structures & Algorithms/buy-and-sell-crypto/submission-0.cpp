class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2){
            return 0;
        }
        int m = 0; int small = prices[0];
        int l = 0; int r = 1;
        while (r<prices.size()){
            m = max(prices[r]-prices[l],m);
            if (prices[r]<prices[l]){
                l = r;
            }
            r++;
        }
        return m;
    }
};
