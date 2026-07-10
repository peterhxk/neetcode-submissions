class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0; int j = 0;
        int cur_sum = 0;
        int ret=0;
        while (j < arr.size()){
            cur_sum += arr[j];
            if (j-i == k-1){
                float avg = static_cast<float>(cur_sum) / k;
                if (avg >= static_cast<float>(threshold)){
                    ret ++;
                } 
                cur_sum -= arr[i];
                i++;
            }
            j++;
        }
        return ret;
    }
};