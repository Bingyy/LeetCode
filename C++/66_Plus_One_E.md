[20190407]

### 题目描述

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
```pre
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
```

### 题解

这也是模拟题，从最后一位开始计算，显然用`while`循环会更好，记录进位。

注意最后还有进位时，会使得数组扩大一位。

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int i = digits.size() - 1;
        while (i >= 0) {
            if (i == digits.size() - 1) { // only last digit gets plus one
                int temp = digits[i] + 1 + carry;
                digits[i] = temp % 10;
                carry = temp / 10;
            } else {
                int temp = digits[i] + carry;
                digits[i] = temp % 10;
                carry = temp / 10;
            }
            if (carry != 0) {
                i--;
            } else {
                break;
            }
        }
        cout << carry << endl;
        if (carry != 0) {
            digits.push_back(carry);
            // swap(digits[0], digits[digits.size() - 1]); // could AC for test cases, but not right in logic
            for (int i = digits.size() - 1; i > 0; i--) {
                digits[i] = digits[i - 1];
            }
            digits[0] = carry;
        }
        
        return digits;
    }
};
```
