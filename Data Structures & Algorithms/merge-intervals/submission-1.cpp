class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> m; //start = end
        for (vector<int> interval: intervals){
            int s = interval[0];
            int e = interval[1];
            auto it = m.lower_bound(s);
            while (it != m.end() && it->first<=e){
                e = max(it->second,e);
                it = m.erase(it);
            }
            auto lb = m.lower_bound(s);
            if (lb != m.begin()){
                auto it2 = prev(lb);
                auto [s2, e2] = *it2;
                if (e2>=s){
                    s = s2;
                    m.erase(s2);
                    if (e2 > e){
                        e = e2;
                    }
                }
            }
            m[s] = e;
        }
        vector<vector<int>> ret;
        for (auto [s, e]:m){
            ret.push_back({s,e});
        }
        return ret;
    }
};
