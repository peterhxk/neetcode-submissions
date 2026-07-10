class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = nums.size()+1;
        int i = 0; int j = 0;
        int cur_sum = 0;
        int cur_len = 0;
        while (j < nums.size()){
            cur_sum += nums[j];
            cur_len += 1;
            while (cur_sum >= target){
                min_len = min(min_len, cur_len);
                cur_sum -= nums[i];
                cur_len--;
                i++;
            }

            j++;
        }

        return (min_len > nums.size()) ? 0 : min_len;
    }
};