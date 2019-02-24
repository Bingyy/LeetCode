class Solution {
public:
    // 二分查找法
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        int mid;
        
        while(low < high) {
            
            mid = (low + high) / 2;
            
            if(target < nums[mid]) {
                high = mid;
            } 
            
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
              
        return low;
    }
};
