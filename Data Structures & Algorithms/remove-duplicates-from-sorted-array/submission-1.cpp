class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j = 1;
        int prev = nums[0];
        while (j < nums.size()){
            if (nums[j]!=prev){
                cout << nums[j] << endl;
                i++;
                nums[i] = nums[j];
                prev = nums[j];
            }
            j++;
        }
        return i+1;
    }
};