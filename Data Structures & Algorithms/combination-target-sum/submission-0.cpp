class Solution {
public:

    void helper(int i, vector<int>& nums, vector<int>& cur, int sum, int target, vector<vector<int>>& ret){
        if (sum == target){
            ret.push_back(cur);
            return;
        }

        if (sum > target){
            return;
        }

        for (int j = i; j<nums.size(); j++){
            cur.push_back(nums[j]);
            sum+=nums[j];
            helper(j, nums, cur, sum, target, ret);
            sum-=nums[j];
            cur.pop_back();
        }
        

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ret = {};
        vector<int> cur = {};
        helper(0, nums, cur, 0, target, ret);
        return ret;
    }
};
