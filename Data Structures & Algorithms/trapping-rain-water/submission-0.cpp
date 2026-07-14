class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int,int>> pre_suf(height.size());
        int prefix_max = 0;
        int suffix_max = 0;
        for (int i=0;i<height.size();i++){
            pre_suf[i].first=prefix_max;
            prefix_max=max(prefix_max, height[i]);
        }
        for (int j=height.size()-1; j>=0; j--){
            pre_suf[j].second=suffix_max;
            suffix_max = max(suffix_max, height[j]);
        }
        int sum = 0;
        for (int k=0;k<height.size();k++){
            sum += max(min(pre_suf[k].first, pre_suf[k].second)-height[k], 0);
            cout << "height: " << height[k] << " pre: " << pre_suf[k].first << " suf: " << pre_suf[k].second << " sum: "<<sum<<endl;

        }
        return sum;

    }
};
