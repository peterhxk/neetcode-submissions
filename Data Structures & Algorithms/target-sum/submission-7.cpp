class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //knapsack
        // x: iterator
        // y: sum
        // m[x][y]: count
        // if (nums.size() == 1 && target==nums[0]){
        //     return 1;
        // }
        // if (nums.size() == 1 && target!=nums[0]){
        //     return 0;
        // }
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (target>total){
            return 0;
        }
        vector<vector<int>> m (nums.size()+1, vector<int>(total*2+1, 0));
        int target_ind = target+total;
        m[0][total] = 1;
        for (int i = 1; i<nums.size()+1; i++){
            for (int j = 0; j<=total*2; j++){
                int ind = i-1;
                if (j-nums[ind]>=0){
                    m[i][j]+=m[i-1][j-nums[ind]];
                }
                if (j+nums[ind]<=total*2){
                    m[i][j]+=m[i-1][j+nums[ind]];
                }
            }
        }
        return m[nums.size()][target_ind];




    }
};
