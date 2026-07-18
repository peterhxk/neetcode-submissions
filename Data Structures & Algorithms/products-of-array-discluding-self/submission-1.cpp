class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        int left=1;
        int right=1;
        for (int i = 0; i< nums.size(); i++){
            left *= nums[i];
            prefix[i] = left;
        }
        for (int j = nums.size()-1; j>=0; j--){
            right *= nums[j];
            suffix[j] = right;
        }
        vector<int> ret(nums.size());
        
        for (int k=0;k<nums.size();k++){
            if (k==0){
                ret[k] = suffix[k+1];
            }
            else if (k==nums.size()-1){
                ret[k] = prefix[k-1];
            }
            else {
                ret[k] = suffix[k+1]*prefix[k-1];
            }

        }
        return ret;
    }
};
