class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        deque<int> m;
        vector<int> ret;
        while (i<k&&i<nums.size()){
            int cur = nums[i];
            if (m.empty()){
                m.push_front(cur);
            } else{
                while (!m.empty() && m.back()<cur){
                    m.pop_back();
                }
                m.push_back(cur);
            }
            i++;
        }
        ret.push_back(m.front());
        while (i < nums.size()){
            int l = i-k;
            if (m.front()==nums[l]){
                m.pop_front();
            }
            int cur = nums[i];
            while (!m.empty() && m.back()<cur){
                m.pop_back();
            }
            m.push_back(cur);
            ret.push_back(m.front());
            i++;
        }
        return ret;

        
    }
};
