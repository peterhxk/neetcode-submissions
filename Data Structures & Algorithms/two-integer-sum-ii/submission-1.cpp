class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0; int j = numbers.size()-1;
        while (i<j){
            //cout << numbers[i] << numbers[j] << endl;
            if (numbers[i]+numbers[j] > target){
                j--;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else {
                return {i+1, j+1};
            }
        }
    }
};
