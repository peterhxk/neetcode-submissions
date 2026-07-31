class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> perms = {{}};
        for (int i: nums){
            set<vector<int>> new_perms = {};
            for (auto perm : perms){
                for (int j = 0; j<perm.size()+1;j++){
                    auto cur = perm;
                    cur.insert(cur.begin()+j, i);
                    new_perms.insert(cur);
                }
            }
            perms = new_perms;
        }
        vector<vector<int>> ret(perms.begin(), perms.end());
        return ret;

    }
};