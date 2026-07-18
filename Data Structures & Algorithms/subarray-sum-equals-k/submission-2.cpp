class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res = 0;
        int total = 0;
        m[0]=1;
        for (int num: nums){
            total += num;
            int diff = total-k;
            res += m[diff];
            m[total] += 1;
        }
        return res;


    }
};