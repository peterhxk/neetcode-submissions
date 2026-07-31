class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};
        for (int i : nums){
            vector<vector<int>> new_perms = {};
            for (auto perm : perms){
                for (int j = 0; j<perm.size()+1; j++){
                    auto cur = perm;
                    cur.insert(cur.begin()+j, i);
                    new_perms.push_back(cur);
                }
            }
            perms = new_perms;
        }
        return perms;
    }
};
