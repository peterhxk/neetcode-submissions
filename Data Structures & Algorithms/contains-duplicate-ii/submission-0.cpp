class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0; int j = 0;
        unordered_set<int> s;
        while (j < nums.size()){
            int cur = nums[j];
            if (s.count(cur)){
                return true;
            }
            s.insert(cur);
            if (j-i == k){
                s.erase(nums[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};