class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> m;
        for (auto l: times){
            auto a = l[0]; auto b = l[1]; auto c = l[2];
            m[a].push_back({b,c});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
        unordered_map<int,int> distance;
        q.push({0,k});
        while (!q.empty()){
            auto cur = q.top();
            q.pop();
            int dist = get<0>(cur); int node = get<1>(cur);
            //cout << "cur: "<<node<<" dist: "<<dist<<endl;
            if (distance.count(node)){
                continue;
            }
            distance[node] = dist;
            for (auto [a,b]:m[node]){
                q.push({dist+b, a});
            }
        }
        cout<<distance.size();

        if (distance.size() < n){
            return -1;
        }

        int ret = 0;
        for (auto [node, d]: distance){
            ret = max(d, ret);
        }
        return ret;

    }
};
