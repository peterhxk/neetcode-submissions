class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        int cur_sum = 0;
        for (int num : nums){
            cur_sum = max(0,cur_sum);
            cur_sum+=num;
            ret = max(ret, cur_sum);
        }
        return ret;
    }
};
