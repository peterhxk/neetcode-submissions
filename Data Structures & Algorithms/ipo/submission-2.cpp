class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_hp;

        for (int i =0; i< profits.size(); i++){
            int profit = profits[i];
            int c = capital[i];
            min_hp.push({c,profit});
        }
        priority_queue<pair<int,int>> max_hp;
        int cur = w;
        for (int i = 0; i<k; i++){
            while (get<0>(min_hp.top())<=cur&&!min_hp.empty()){
                auto node = min_hp.top();
                min_hp.pop();
                int cap = get<0>(node);
                int prof = get<1>(node);
                max_hp.push({prof,cap});
            }
            if (!max_hp.empty()){
                auto node = max_hp.top();
                max_hp.pop();
                cur += get<0>(node);
            }
        }
        return cur;

    }
};