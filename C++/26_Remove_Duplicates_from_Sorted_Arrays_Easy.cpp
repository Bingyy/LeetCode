class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 形参是引用参数传递
        // 相邻元素对比，相同则去除
        if(nums.size() == 0) return 0;
        int i = 0; // 在后
        for(int j = 0; j < nums.size(); j++) { // j在前
            if(nums[j] != nums[i]) {
                i++; // 
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
