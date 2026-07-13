class Solution {
public:
    int vol(int x, int y, int height1, int height2){
            return (y-x)*min(height1,height2);
        }
    int maxArea(vector<int>& heights) {
        int ret = 0;
        int i = 0; int j = heights.size()-1;

        

        while (i<j){
            ret = max(ret, vol(i, j, heights[i], heights[j]));
            if (heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ret;

    }
};
