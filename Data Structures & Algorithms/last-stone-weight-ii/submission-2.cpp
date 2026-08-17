class Solution {
public:
    int dfs(int i, int cur, int target, vector<int>& stones,map<pair<int,int>,int>& cache){
        if (i>=stones.size()){
            return abs(cur-target);
        }
        if (cache.count({i,cur})){
            return cache[{i,cur}];
        }
        int skip = dfs(i+1,cur, target, stones,cache);
        int take = dfs(i+1,cur+stones[i],target,stones,cache);

        cache[{i,cur}] = min(skip, take);
        return cache[{i,cur}];
    }
    int lastStoneWeightII(vector<int>& stones) {
        // We want to find the split that is closest to sum(stones)/2
        // then return the difference of the two split
        // dfs:
        // - include stone
        // - skip stone
        // ends if sum greater or equal to the target
        // minimize over it
        
        // instead of dfs with cache, can we do dp (no, we're not looking for a min/max on each step)
        // x axis: target
        // y axis: stone index
        int s = accumulate(stones.begin(), stones.end(),0);
        int target = s/2;
        map<pair<int,int>,int> cache;
        int ret = dfs(0,0,target,stones,cache);
        if (s%2==1){
            return 2*ret+1;
        }
        return 2*ret;
    }
};