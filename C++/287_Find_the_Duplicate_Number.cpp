#include "lib.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (1) {
            slow = nums[slow]; // 跳一步
            fast = nums[nums[fast]]; // 跳两步
            if (slow == fast) {
                break; // 被追及
            }
        }
        // 找交点
        while (1) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) {
                return slow;
            }
        }
        return -1;
    }
};