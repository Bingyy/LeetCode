[20190407]

### 题目描述


Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

```pre
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
```pre
Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```
### 题解

**思路**：

这道题之前尝试着去解过一次，但是感觉不好解，就知难而退了，晚上开始从Easy题从头开始做起，这道未解的题，想了一下，开始没有思路，只知道用`map`来保存一下字符对应的数值。

然后，再看一下三条减法规则，只要能解析这三条规则，就可以完成罗马数字到整数的转换。

而这个减法规则则是向前看一位，想到这里，动手实现一下发现并不难，但是注意减法规则这里，`i += 2`，不是`i++`，动手模拟一下就知道需要跳过两个字符，否则`IV`会解析为9，而不是5.

```cpp
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int sum = 0;
        int i = 0;
        for (; i < s.size();) {
            int temp = mp[s[i]];
            if (i + 1 < s.size() && s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                sum += (mp[s[i+1]] - temp);
                i += 2; // not i++
                cout << sum << " "<< i << endl;
            } else if (i + 1 < s.size() && s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                sum += (mp[s[i+1]] - temp);
                i += 2; 
            } else if (i + 1 < s.size() && s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                sum += (mp[s[i+1]] - temp);
                i += 2; 
            } else {
                sum += temp;
                i++;
            }
        }
        return sum;
    }
};
```

END.
