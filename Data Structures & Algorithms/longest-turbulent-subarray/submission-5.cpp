class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int prev_val=arr[0];
        int prev_sign = 0; // 1 is <, 2 is >, 0 is None or ==
        int cur_count = 1;
        int max_count = 1;
        for (int i = 1; i < arr.size(); i++) {
            int cur = arr[i];
            if (cur > prev_val && prev_sign == 1){
                cur_count++;
            }else if (cur < prev_val && prev_sign == 2){
                cur_count++;
            } else{
                cur_count = 2;
            }
            if (cur > prev_val){
                prev_sign = 2;
            }else if (cur < prev_val){
                prev_sign = 1;
            }else{
                prev_sign = 0;
                cur_count --;
            }  
            //cout << " cur_sign: " << prev_sign;
            //cout << " cur_count: " << cur_count<<endl;
            max_count = max(max_count, cur_count);
            prev_val = cur;
        }
        return max_count;
    }
};
