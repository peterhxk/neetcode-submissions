class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int repeated = false;
        int i = 1; int j = 1;
        for (j; j < nums.size(); j++){
            int cur = nums[j];
            if (cur == prev){
                if (!repeated){
                    nums[i] = cur;
                    repeated = true;
                    i++;
                }
            }
            else{
                repeated = false;
                nums[i] = cur;
                i++;
                prev = cur;
            }
        }
        return i;
    }
};