class Solution {
public:
    int computeSum(vector<int>& prefix, int i, int j){
        if (i==0){
            return prefix[j];
        }
        else{
            return prefix[j]-prefix[i-1];
        }
    }
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix;
        int total = 0;
        for (int num: nums){
            total += num;
            prefix.push_back(total);

        }
        int ret = 0;
        for (int i=0;i<nums.size();i++){
            for (int j=i; j<nums.size();j++){
                if (computeSum(prefix, i, j)==k){
                    ret += 1;
                }
            }
        }
        return ret;


    }
};