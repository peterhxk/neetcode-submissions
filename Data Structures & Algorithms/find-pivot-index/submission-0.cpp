class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> postfix(nums.size());
        int sum1 = 0; int sum2 =0;

        for (int i = 0; i< nums.size(); i++){
            sum1 += nums[i];
            prefix[i]=sum1;
        }

        for (int j = nums.size()-1; j>=0; j--){
            sum2 += nums[j];
            postfix[j]=sum2;
        }

        for (int k = 0; k<nums.size();k++){
            if (prefix[k]==postfix[k]){
                return k;
            }
        }
        return -1;
    }
};