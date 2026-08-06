class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1, days[days.size()-1]*costs[2]);
        // [0,2,4,6,max,max,max]
        dp[0]=0;
        for (int i =1; i<days.size()+1; i++){
            for (int j = 0; j<costs.size();j++){
                int cost = costs[j];
                int duration;
                if (j==0){
                    duration = 1;
                }
                else if (j==1){
                    duration = 7;
                } else {
                    duration = 30;
                }
                int k = i-1;
                //cout<<"k "<<days[k]<<" i: "<< days[i]<<" duration: "<<duration<<endl;
                while (k > 0 && days[k-1]>=days[i-1]-duration+1){
                    k--;
                }
                //cout<< dp[i] <<" k: "<<k << " "<<dp[k+1]<<" cost: "<<cost<<endl;
                dp[i] = min(dp[i], dp[k]+cost);
                   
            }
            //cout<< "dp: "<< dp[i]<<endl;
            //cout<<dp[i]<<", ";
        }
        return dp[days.size()];

    }
};