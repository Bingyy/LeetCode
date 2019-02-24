class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // 
        for(int j = 0; j < nums.size(); j++) { 
            if(nums[j] != val) { // j跟踪非val的值 
                nums[i] = nums[j];
                i++; //
            }
        }
        return i;
    }
};
