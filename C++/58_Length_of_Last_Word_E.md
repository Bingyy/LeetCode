[20190407]

### 题目描述

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

```pre
Input: "Hello World"
Output: 5
```

### 题解

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int i = s.size() - 1;
        
        // till s[i] != ' '
        while (s[i] == ' ') {
            i--; 
            cout << i << endl;
        } 
        while (i >= 0) {   
            if (s[i] != ' ') {
                cnt++;
                i--;
            } else {
                break;
            }
        }
        return cnt;
    }
};
```
