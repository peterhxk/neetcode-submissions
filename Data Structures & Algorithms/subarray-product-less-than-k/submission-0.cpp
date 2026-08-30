class Solution {
public:
    int ret = 0;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0; int j=0;
        int cur = 1;
        while (j<nums.size()){
            cur *= nums[j];
            //cout<<"j: "<<nums[j]<<" cur: "<<cur<<endl;
            if (cur<k){
                ret += j-i+1;
            } else {
                while (i<j&&cur>=k){
                    cur /= nums[i];
                    i++;
                }
                if (cur<k){
                    int base = j-i+1;
                    ret += base;
                }
            }
            //cout<<"ret: "<<ret<<endl;
            j++;
        }
        return ret;
    }
};