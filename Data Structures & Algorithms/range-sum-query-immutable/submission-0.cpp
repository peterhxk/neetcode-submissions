class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int num : nums){
            sum += num;
            this->prefix.push_back(sum);
            //cout << sum << ", ";
        }
    }
    int sumRange(int left, int right) {
        //cout<<endl<<this->prefix[0];
    
        if (left == 0){
            return this->prefix[right];
        }
        return this->prefix[right]-this->prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */