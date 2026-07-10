class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num: nums){
            m[num]++;
        }
        priority_queue<pair<int, int>> q;
        for (auto& [num, freq]:m){
            //cout << freq << num << endl;
            q.push({freq,num});
        }
        vector<int> ret;
        for (int i =0; i<k; i++){
            auto [freq, num] = q.top();
            q.pop();
            ret.push_back(num);
        }
        return ret;
    }
};
