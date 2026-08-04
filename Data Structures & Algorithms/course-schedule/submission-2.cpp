class Solution {
public:
    bool dfs(int i, unordered_set<int>& visited, unordered_map<int,vector<int>>& m){
        if (visited.count(i)){
            return false;
        }
        if (!m.count(i)){
            return true;
        }
        visited.insert(i);
        
        bool ret = true;
        for (auto node : m[i]){
            if (!dfs(node, visited, m)){
                return false;
            }
        } 
        visited.erase(i);
        m.erase(i);
        return ret;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m;
        for (auto l: prerequisites){
            int a = l[0];
            int b = l[1];
            m[a].push_back(b);
        }
        bool ret = true;
        
        for (int i = 0; i<numCourses; i++){
            for (auto node : m[i]){
                unordered_set<int> visited;
                ret = (ret && dfs(node, visited, m));
            }
        }
        return ret;
    }
};
