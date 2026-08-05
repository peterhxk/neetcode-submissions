class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum/2;
        if (target*2 != sum){
            return false;
        }
        unordered_set<int> cur = {0};
        for (int num: nums){
            unordered_set<int> new_cur = {};
            for (int x: cur){
                cout<<x+num<<endl;
                if (x+num == target){
                    return true;
                }
                new_cur.insert(x+num);
                new_cur.insert(x);
            }
            cur = new_cur;
        }
        return false;

    }
};
