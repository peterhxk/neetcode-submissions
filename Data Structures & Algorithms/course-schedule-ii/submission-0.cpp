class Solution {
public:

    bool dfs(int i, unordered_set<int>& visited, unordered_map<int,vector<int>>& m, vector<int>& ret, unordered_set<int>& ret_visited){
        if (visited.count(i)){
            return false;
        }
        visited.insert(i);
        bool result = true;
        for (auto node: m[i]){
            result = (result && dfs(node, visited, m, ret, ret_visited));
        }
        m.erase(i);
        visited.erase(i);
        if (!ret_visited.count(i)){
            ret.push_back(i);
            ret_visited.insert(i);
            
        }
        return result;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        for (auto prereq:prerequisites){
            int key = prereq[0];
            int val = prereq[1];
            m[key].push_back(val);
        }

        vector<int> ret;
        unordered_set<int> visited;
        unordered_set<int> a;
        bool valid = true;
        for (int i = 0; i< numCourses; i++){
            valid = (valid && dfs(i, visited, m, ret,a ));
            if (!valid){
                return {};
            }
        }
        return ret;
    }
};
