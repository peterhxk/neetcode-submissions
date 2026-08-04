class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> m;
        for (int i = 0; i<edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            double prob = succProb[i];
            m[n1].push_back({n2,prob});
            m[n2].push_back({n1,prob});
        }

        unordered_map<int, double> shortest;
        priority_queue<pair<double,int>> q;
        q.push({1,start_node});
        while (!q.empty()){
            auto cur = q.top();
            q.pop();
            double p = get<0>(cur); int n = get<1>(cur);
            //cout<< "cur: "<< n<<endl;
            if (shortest.count(n)){
                continue;
            }
            shortest[n] = p;
            for (auto[n2, p2]:m[n]){
                q.push({p2*p, n2});
            }
        }
        return shortest[end_node];
    }
};