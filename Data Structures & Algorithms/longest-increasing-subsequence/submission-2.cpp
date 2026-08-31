class Solution {
public:
    int dfs(vector<int>& nums, int i, int prev, map<pair<int,int>,int>& cache){
        if (i==nums.size()){
            return 0;
        }
        if (cache.contains({i,prev})){
            return cache[{i,prev}];
        }
        int ret = dfs(nums,i+1,prev,cache);
        if (prev==-1||nums[i]>nums[prev]){
            ret = max(ret, 1+dfs(nums,i+1,i,cache));
        }
        cache[{i,prev}] = ret;
        //cout<<"i: "<<i<<" prev: "<<prev<<" ret: "<<ret<<endl;
        return ret;

    }
    int lengthOfLIS(vector<int>& nums) {
        map<pair<int,int>,int> cache;
        return dfs(nums, 0, -1, cache);
    }
};
