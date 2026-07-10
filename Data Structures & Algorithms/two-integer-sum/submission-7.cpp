class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size();i++){
            int v1 = nums[i];
            int v2 = target-v1;
            if (m.contains(v2)){
                return {m[v2],i};
            }
            else{
                m[v1]=i;
            }
        }
    }
};
