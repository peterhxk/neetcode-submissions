class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; int fast = nums[nums[0]];

        while (nums[slow] != nums[fast]){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int ret = 0;
        while (nums[ret]!=nums[slow]){
            ret = nums[ret];
            slow = nums[slow];
        }
        return nums[slow];
    }
};
