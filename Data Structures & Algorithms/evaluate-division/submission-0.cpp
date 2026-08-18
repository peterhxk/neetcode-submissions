class Solution {
public:

    double dfs(string cur, string target, double val, unordered_map<string, unordered_map<string, double>>& m, unordered_set<string>& visited){
        double ret = -1;
        if (visited.contains(cur)||!m.contains(cur)){
            return ret;
        }
        if (cur == target){
            return val;
        }
        
        if (m[cur].contains(target)){
            return val * m[cur][target];
        }
        visited.insert(cur);
        for (auto [k, v] : m[cur]){
            double v2 = dfs(k, target, val*v,m,visited);
            if (v2 != -1){
                return v2;
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m;
        for (int i = 0; i< equations.size(); i++){
            auto eq = equations[i];
            auto val = values[i];
            string num = eq[0];
            string denum = eq[1];
            m[num][denum] = val;
            m[denum][num] = 1/val;
        }
        vector<double> ret;
        for (auto query : queries){
            string source = query[0];
            string sink = query[1];
            unordered_set<string> visited;
            ret.push_back(dfs(source, sink, 1, m, visited));
        }
        return ret;
    }
};