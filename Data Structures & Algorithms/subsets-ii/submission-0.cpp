class Solution {
public:
    vector<vector<int>> ret;

    void helper(int i, vector<int>& nums, vector<int>& cur){
        if (i == nums.size()){
            ret.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        helper(i+1, nums, cur);
        cur.pop_back();

        while (i+1<nums.size()&&nums[i]==nums[i+1]){
            i++;
        }
        helper(i+1, nums, cur);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur = {};
        helper(0, nums, cur);
        return ret;
    }
};
